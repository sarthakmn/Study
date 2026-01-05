#include <gst/gst.h>
static GMainLoop *loop;
#include<stdio.h>

static gboolean my_bus_callback (GstBus *bus,GstMessage *message,gpointer data)
{
  g_print ("Got %s message\n", GST_MESSAGE_TYPE_NAME (message));
  switch (GST_MESSAGE_TYPE (message)) {
      case GST_MESSAGE_ERROR: 
          g_main_loop_quit (loop);
          break;
      case GST_MESSAGE_EOS:
      /* end-of-stream */
          printf("quite ho\n");
          g_main_loop_quit (loop);
          break;
      default:
      /* unhandled message */
      break;
  }
}

static gboolean cb_print_position (GstElement *pipeline)
{
    //GstFormat fmt = GST_FORMAT_TIME;
    gint64 pos, len;
    if (gst_element_query_position (pipeline, GST_FORMAT_TIME, &pos)
    && gst_element_query_duration (pipeline, GST_FORMAT_TIME, &len)) {
        g_print ("Time: %" GST_TIME_FORMAT " / %" GST_TIME_FORMAT "\r",
        GST_TIME_ARGS (pos), GST_TIME_ARGS (len));
    }
    
    /* call me again */
    return TRUE;
}

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

gint main(int argc, char *argv[]) {
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
  
  gst_element_link_many (data.source,data.mpeg, data.decode,data.convert,data.resample ,data.sink,NULL);

  /* Start pipeline */
  gst_element_set_state(data.pipeline, GST_STATE_PLAYING);
  
  g_timeout_add (200, (GSourceFunc) cb_print_position, data.pipeline);
  
  bus = gst_element_get_bus(data.pipeline);
  loop = g_main_loop_new (NULL, FALSE);
  g_main_loop_run (loop);

  /* Wait until error or end-of-stream */
  bus = gst_element_get_bus(data.pipeline);
  gst_bus_add_watch (bus, my_bus_callback, NULL);
  msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE, GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

  /* Free resources */
  if (msg != NULL)
  gst_message_unref(msg);
  g_main_loop_unref (loop);
  gst_object_unref(bus);
  gst_element_set_state(data.pipeline, GST_STATE_NULL);
  gst_object_unref(data.pipeline);
  return 0;
}

