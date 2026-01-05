#include <gst/gst.h>

/* Structure to contain all our information, so we can pass it to callbacks */
typedef struct _CustomData {
  GstElement *pipeline;
  GstElement *source;
  GstElement *convert;
  GstElement *resample;
  GstElement *sink;
  GstElement *decode;
  GstElement *mpeg;
  GstElement *bin;
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
  data.mpeg = gst_element_factory_make ("mpegaudioparse","mpeg");
  data.decode = gst_element_factory_make ("mpg123audiodec","decode");
  data.convert = gst_element_factory_make ("audioconvert", "convert");
  data.resample = gst_element_factory_make ("audioresample", "resample");
  data.sink = gst_element_factory_make ("autoaudiosink", "sink");

  /* Create Empty Pipeline */
  data.pipeline = gst_pipeline_new("test_pipe");
  g_object_set (data.source, "location", "audio.mp3", NULL);

  /* Build the pipeline */
  gst_bin_add_many (GST_BIN (data.pipeline), data.source,data.mpeg, data.decode,data.convert,data.resample ,data.sink, NULL);
  
  if (gst_element_link_many (data.source,data.mpeg, data.decode,data.convert,data.resample ,data.sink,NULL) != TRUE) {
    g_printerr ("Elements could not be linked.\n");
    gst_object_unref (data.pipeline);
    return -1;
  }

  /* Start pipeline */
  gst_element_set_state(data.pipeline, GST_STATE_PLAYING);

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

