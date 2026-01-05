#include <gst/gst.h>

static GMainLoop *loop;

GstElement *pipeline;
GstElement *source;
GstElement *demux;
GstElement *decode;
GstElement *sink;
GstElement *vd_decode;
GstElement *vd_sink;


static GstBus *bus;
static void on_pad_au_added (GstElement *element,GstPad *pad,gpointer data){
    GstPad *sinkpad;
    GstElement *decoder = (GstElement *) data;
    g_print ("Dynamic pad created for audio, linking demuxer/decoder\n");
    sinkpad = gst_element_get_static_pad (decoder, "sink");
    gst_pad_link (pad, sinkpad);
    gst_object_unref (sinkpad);
}
static void on_pad_vd_added (GstElement *element,GstPad *pad,gpointer data){
    GstPad *sinkpad;
    GstElement *decoder = (GstElement *) data;
    g_print ("Dynamic pad created for video, linking demuxer/decoder\n");
    sinkpad = gst_element_get_static_pad (decoder, "sink");
    gst_pad_link (pad, sinkpad);
    gst_object_unref (sinkpad);
}

int main(int argc, char *argv[]) {

  gst_init (&argc, &argv);

  source = gst_element_factory_make ("filesrc", "source");
  demux = gst_element_factory_make ("decodebin", "demux");
  decode = gst_element_factory_make ("audioconvert", "decode");
  sink = gst_element_factory_make ("autoaudiosink", "sink");
  vd_decode = gst_element_factory_make ("videoconvert", "vd_decode");
  vd_sink = gst_element_factory_make ("autovideosink", "vd_sink");

  pipeline = gst_pipeline_new ("test-pipeline");

  if (!pipeline || !source || !demux  || !decode || !sink || !vd_decode || !vd_sink) {
    g_printerr ("Not all elements could be created.\n");
    return -1;
  }

  g_object_set (source, "location","video.mp4", NULL);

  gst_bin_add_many (GST_BIN (pipeline), source, demux, vd_decode, vd_sink,decode, sink, NULL);
  gst_element_link_many (source, demux,NULL) ;
  gst_element_link_many (vd_decode, vd_sink, NULL);
  gst_element_link_many (decode, sink, NULL);
  g_signal_connect (demux, "pad-added", G_CALLBACK (on_pad_vd_added),vd_decode);
  g_signal_connect (demux, "pad-added", G_CALLBACK (on_pad_au_added),decode);

  loop = g_main_loop_new(NULL, FALSE);
  gst_element_set_state(pipeline, GST_STATE_PLAYING);
  g_main_loop_run(loop);


  return 0;
}

