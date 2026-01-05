#include <gst/gst.h>
#include<stdio.h>
static GMainLoop *loop;

GstElement *pipeline;
GstElement *source;
GstElement *demux;
GstElement *decode;
GstElement *sink;
GstElement *vd_decode;
GstElement *vd_sink;
GstElement *filter;
int input;
GstCaps *caps;
static GstBus *bus;


static void seek_forward_time (GstElement *pipeline,gint64 time_nanoseconds)
    {
    gint64 pos;
    gst_element_query_position (pipeline, GST_FORMAT_TIME, &pos);
    if (!gst_element_seek (pipeline, GST_SEEK_TYPE_END, GST_FORMAT_TIME, GST_SEEK_FLAG_FLUSH,
    GST_SEEK_TYPE_SET,pos+GST_SECOND*time_nanoseconds,GST_SEEK_TYPE_NONE, GST_CLOCK_TIME_NONE)) {
        g_print ("Seek failed!\n");
    }
}
static void seek_backward_time (GstElement *pipeline,gint64 time_nanoseconds)
{
    gint64 pos;
    gst_element_query_position (pipeline, GST_FORMAT_TIME, &pos);
    if (!gst_element_seek (pipeline, GST_SEEK_TYPE_END, GST_FORMAT_TIME, GST_SEEK_FLAG_FLUSH,
    GST_SEEK_TYPE_SET,pos-GST_SECOND*time_nanoseconds,GST_SEEK_TYPE_NONE, GST_CLOCK_TIME_NONE)) {
        g_print ("Seek failed!\n");
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

static gboolean my_bus_callback(GstBus *bus ,GstMessage *message,gpointer data){
    
    //g_print("Recived Bus message is : %s\n",GST_MESSAGE_TYPE_NAME(message));
    switch(GST_MESSAGE_TYPE(message)){

        case GST_MESSAGE_ERROR:{
            GError *err ;
            gchar *debug;
            gst_message_parse_error (message, &err, &debug);
            g_print ("Error: %s\n", err->message);
            g_error_free (err);
            g_free (debug);
            g_main_loop_quit (loop);
            }
            break;
        case GST_MESSAGE_TAG: {
            GstTagList *tags = NULL;
            GDate **date;
            gst_message_parse_tag (message, &tags);
            g_print ("Got tags from element %s\n", GST_OBJECT_NAME (message->src));
            gst_tag_list_unref (tags);
            break;
        }
        case GST_MESSAGE_EOS:
            g_main_loop_quit(loop);
            
            break;
        default:
            break;
    }
    lable:
    printf("\n1.PLAY\n2.PAUSE\n3.SEEK FORWARD\n4.SEEK BACKWARD\n5.QUIT\nEnter STATE : ");
    scanf("%d",&input);
    switch(input){
        case 1:
            gst_element_set_state(pipeline,GST_STATE_PLAYING);
            break;
        case 2:
            gst_element_set_state(pipeline,GST_STATE_PAUSED);
            break;
        case 3:
            seek_forward_time(pipeline,10);
            goto lable;
            break;
        case 4:
            seek_backward_time(pipeline,10);
            goto lable;
            break;
        case 5:
            g_main_loop_quit (loop);    
            break;
        default:
            printf("Invalid Input\n");
            goto lable;
            break;
    }
}

static void on_pad_au_added (GstElement *element,GstPad *pad,gpointer data){
    GstPad *sinkpad;
    GstElement *decoder = (GstElement *) data;
    //g_print ("Dynamic pad created for audio, linking demuxer/decoder\n");
    sinkpad = gst_element_get_static_pad (decoder, "sink");
    gst_pad_link (pad, sinkpad);
    gst_object_unref (sinkpad);
}
static void on_pad_vd_added (GstElement *element,GstPad *pad,gpointer data){
    GstPad *sinkpad;
    GstElement *decoder = (GstElement *) data;
    //g_print ("Dynamic pad created for video, linking demuxer/decoder\n");
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
  filter = gst_element_factory_make ("capsfilter", "filter");
  
  pipeline = gst_pipeline_new ("test-pipeline");

caps = gst_caps_new_simple ("video/x-raw",
    "width", G_TYPE_INT, 1000,"height", G_TYPE_INT, 1000,NULL);


  g_object_set(G_OBJECT(filter),"caps",caps,NULL);
  gst_caps_unref(caps);

  if (!pipeline || !source || !demux  || !decode || !sink || !filter || !vd_decode || !vd_sink) {
    g_printerr ("Not all elements could be created.\n");
    return -1;
  }


  g_object_set (source, "location","video_india.mp4", NULL);
  gst_bin_add_many (GST_BIN (pipeline), source,filter, demux ,vd_decode, vd_sink,decode, sink, NULL);
  gst_element_link_many (source,demux,NULL) ;
  gst_element_link_many (vd_decode ,vd_sink, NULL);
  gst_element_link_many (decode, sink, NULL);
  
  g_signal_connect (demux, "pad-added", G_CALLBACK (on_pad_vd_added),vd_decode);
  g_signal_connect (demux, "pad-added", G_CALLBACK (on_pad_au_added),decode);

  g_timeout_add (200, (GSourceFunc) cb_print_position, pipeline);

  bus = gst_pipeline_get_bus(GST_PIPELINE(pipeline)); 
  gst_bus_add_watch(bus, my_bus_callback, NULL);
  gst_object_unref (bus);
  
  loop = g_main_loop_new(NULL, FALSE);
  gst_element_set_state(pipeline, GST_STATE_PLAYING);
  g_main_loop_run(loop);


  return 0;
}

