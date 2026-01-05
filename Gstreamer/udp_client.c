//udpsrc port=5000 ! application/x-rtp ! rtph264depay ! avdec_h264 ! videoconvert ! autovideosink 
#include <gst/gst.h>
//gcc basic_manual.c -o basic `pkg-config --cflags --libs gstreamer-1.0`
int main(int argc, char *argv[]) {
  GstElement *pipeline , *source , *sink ,*convert ,*encode,*rtp;
  GstBus *bus;
  GstMessage *msg;
  GstStateChangeReturn ret;

  /* Initialize GStreamer */
  gst_init(&argc, &argv);
  
  /* Create Elements */
  source = gst_element_factory_make ("v4l2src", "source");
  convert = gst_element_factory_make ("videoconvert","convert");
  encode = gst_element_factory_make ("x264enc","encode");
  rtp = gst_element_factory_make ("rtph264pay","rtp");
  sink = gst_element_factory_make ("udpsink", "sink");

  /* Create Empty Pipeline */
  pipeline = gst_pipeline_new("test_pipe");

  g_object_set (sink, "host","10.171.138.203", NULL);
  g_object_set (sink, "port","5000", NULL);

  /* Build the pipeline */
  gst_bin_add_many (GST_BIN (pipeline), source, convert,encode,rtp,sink, NULL);
  
  if (gst_element_link_many (source,convert,encode,rtp,sink,NULL) != TRUE) {
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
