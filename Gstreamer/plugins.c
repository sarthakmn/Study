#include <gst/gst.h>
//gcc plugins.c -o basic `pkg-config --cflags --libs gstreamer-1.0`
int main(int argc, char *argv[]) {
  GstElement *pipeline;
  GstBus *bus;
  GstMessage *msg;

  /* Initialize GStreamer */
  gst_init(&argc, &argv);

  /* Create pipeline */
  pipeline = gst_parse_launch("v4l2src ! videoconvert! videoscale ! videoflip method=horizontal-flip ! video/x-raw, width=600, height=600 ! tee name=t1 t1. ! queue ! videobalance contrast=1.4 brightness=0.1 saturation=1.3 ! ximagesink t1. ! queue ! videoconvert ! video/x-raw, width=600, height=600 ! ximagesink t1. ! queue ! agingtv scratch-lines=20 ! ximagesink", NULL);

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

