#include<gst/gst.h>
static GMainLoop *loop;
GstElement *bin ,*pipeline, *source, *sink,*filter;
GstCaps *caps;
int main(int argc,char *argv[] ){
    
    GstBus *bus;
    gst_init(&argc,&argv);
    source = gst_element_factory_make("videotestsrc","source");
    sink = gst_element_factory_make("autovideosink","sink");
    filter = gst_element_factory_make ("capsfilter", "filter");
    pipeline = gst_pipeline_new("test_pipe");
    
    caps = gst_caps_new_simple ("video/x-raw",
    "width", G_TYPE_INT, 1000,
    "height", G_TYPE_INT, 1000,
    NULL);
    g_object_set(G_OBJECT(filter),"caps",caps,NULL);
    gst_caps_unref(caps);

    gst_bin_add_many(GST_BIN(pipeline),source,filter,sink,NULL);
    
    gst_element_link_many(source,filter,sink,NULL);
   
    gst_element_set_state(pipeline,GST_STATE_PLAYING);
    
    loop = g_main_loop_new(NULL, FALSE);
    g_main_loop_run(loop);

    gst_element_set_state (pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);

    return 0;
}