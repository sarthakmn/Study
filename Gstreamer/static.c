#include <gst/gst.h>
//gcc basic_manual.c -o basic `pkg-config --cflags --libs gstreamer-1.0`
int main(int argc, char *argv[]) {
  GstElement *pipeline , *source , *sink , *decode;
  GstBus *bus;
  GstMessage *msg;

  /* Initialize GStreamer */
  gst_init(&argc, &argv);

  
  /* Create Elements */
  source = gst_element_factory_make ("videotestsrc", "source");
  decode = gst_element_factory_make ("videoconvert","decode");
  sink = gst_element_factory_make ("autovideosink", "sink");

  /* Create Empty Pipeline */
  pipeline = gst_pipeline_new("test_pipe");


  /* Build the pipeline */
  gst_bin_add_many (GST_BIN (pipeline), source, decode ,sink, NULL);
  
  if (gst_element_link_many (source,decode,sink,NULL) != TRUE) {
    g_printerr ("Elements could not be linked.\n");
    gst_object_unref (pipeline);
    return -1;
  }

  /* Start pipeline */
  gst_element_set_state(pipeline, GST_STATE_PLAYING);

  /* Wait until error or end-of-stream */
  bus = gst_element_get_bus(pipeline);
  msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE, GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

  /* Free resources */
  if (msg != NULL)
  gst_message_unref(msg);
  gst_object_unref(bus);
  gst_element_set_state(pipeline, GST_STATE_NULL);
  gst_object_unref(pipeline);
  return 0;
}

