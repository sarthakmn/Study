#include <gst/gst.h>
//gst-launch-1.0 filesrc location=audio.ogx ! oggdemux ! vorbisdec ! autoaudiosink

/* Structure to contain all our information, so we can pass it to callbacks */
static void on_pad_added (GstElement *element,GstPad *pad,gpointer data){
    GstPad *sinkpad;
    GstElement *decoder = (GstElement *) data;
    /* We can now link this pad with the vorbis-decoder sink pad */
    g_print ("Dynamic pad created, linking demuxer/decoder\n");
    sinkpad = gst_element_get_static_pad (decoder, "sink");
    gst_pad_link (pad, sinkpad);
    gst_object_unref (sinkpad);
}

typedef struct _CustomData {
  GstElement *pipeline;
  GstElement *source;
  GstElement *demux;
  GstElement *decode;
  GstElement *sink;
} CustomData;

int main(int argc, char *argv[]) {
  CustomData data;
  GstBus *bus;
  GstMessage *msg;
  GstStateChangeReturn ret;
  gboolean terminate = FALSE;

  /* Initialize GStreamer */
  gst_init (&argc, &argv);

  /* Create the elements */
  data.source = gst_element_factory_make ("filesrc", "source");
  data.demux = gst_element_factory_make ("oggdemux", "demux");
  data.decode = gst_element_factory_make ("vorbisdec", "decode");
  data.sink = gst_element_factory_make ("autoaudiosink", "sink");

  /* Create the empty pipeline */
  data.pipeline = gst_pipeline_new ("test-pipeline");

  if (!data.pipeline || !data.source || !data.demux || !data.decode || !data.sink) {
    g_printerr ("Not all elements could be created.\n");
    return -1;
  }

  /* Set the file to play */
  g_object_set (data.source, "location","audio.ogx", NULL);

  /* Build the pipeline. Note that we are NOT linking the source at this
   * point. We will do it later. */
  gst_bin_add_many (GST_BIN (data.pipeline), data.source, data.demux, data.decode, data.sink, NULL);
  gst_element_link_many (data.source, data.demux,NULL) ;
  gst_element_link_many (data.decode, data.sink, NULL);

  /* Connect to the pad-added signal */
  g_signal_connect (data.demux, "pad-added", G_CALLBACK (on_pad_added),data.decode);

  /* Start playing */
  ret = gst_element_set_state (data.pipeline, GST_STATE_PLAYING);
  /* Wait until error or end-of-stream */
  bus = gst_element_get_bus(data.pipeline);
  msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE, GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

  /* Free resources */
  if (msg != NULL)
  gst_message_unref(msg);
  gst_object_unref(bus);
  gst_element_set_state(data.pipeline, GST_STATE_NULL);
  gst_object_unref(data.pipeline);
  return 0;
}

