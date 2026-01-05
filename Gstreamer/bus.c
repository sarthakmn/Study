#include<gst/gst.h>
static GMainLoop *loop;

static gboolean my_bus_callback(GstBus *bus ,GstMessage *message,gpointer data){
    g_print("Recived Bus message is : %s\n",GST_MESSAGE_TYPE_NAME(message));

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
}

int main(int argc,char *argv[] ){
    GstElement *bin ,*pipeline, *source, *sink,*parse, *decode, *convert;
    GstBus *bus;
    gst_init(&argc,&argv);
    source = gst_element_factory_make("filesrc","source");
    parse = gst_element_factory_make("mpegaudioparse","parse");
    decode = gst_element_factory_make("mpg123audiodec","decode");
    convert = gst_element_factory_make("audioconvert","convert");
    sink = gst_element_factory_make("autoaudiosink","sink");

    pipeline = gst_pipeline_new("test_pipe");
    g_object_set(source,"location","audio.mp3",NULL);
    
    gst_bin_add_many(GST_BIN(pipeline),source,parse,decode,convert,sink,NULL);
    
    gst_element_link_many(source,parse,decode,convert,sink,NULL);
   
    bus = gst_pipeline_get_bus(GST_PIPELINE(pipeline)); 
    gst_bus_add_watch(bus, my_bus_callback, NULL);
    gst_object_unref (bus);

    gst_element_set_state(pipeline,GST_STATE_PLAYING);
     

    loop = g_main_loop_new(NULL, FALSE);
    g_main_loop_run(loop);

    gst_element_set_state (pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);

    return 0;
}