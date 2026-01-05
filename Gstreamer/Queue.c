#include<gst/gst.h>
static GMainLoop *loop;
GstElement *bin ,*pipeline, *vd_source, *vd_sink,*vd_queue,*au_queue,*au_source, *au_sink;

int main(int argc,char *argv[] ){
    
    GstBus *bus;
    gst_init(&argc,&argv);
    vd_source = gst_element_factory_make("videotestsrc","vd_source");
    vd_sink = gst_element_factory_make("autovideosink","vd_sink");
    au_source = gst_element_factory_make("audiotestsrc","au_source");
    au_sink = gst_element_factory_make("autoaudiosink","au_sink");

    au_queue = gst_element_factory_make ("queue", "au_queue");
    vd_queue = gst_element_factory_make ("queue","vd_queue");
    pipeline = gst_pipeline_new("test_pipe");


    gst_bin_add_many(GST_BIN(pipeline),vd_source,vd_queue,vd_sink,au_source,au_queue,au_sink,NULL);
    
    gst_element_link_many(vd_source,vd_queue,vd_sink,NULL);
     gst_element_link_many(au_source,au_queue,au_sink,NULL);
   
    gst_element_set_state(pipeline,GST_STATE_PLAYING);
    
    loop = g_main_loop_new(NULL, FALSE);
    g_main_loop_run(loop);

    gst_element_set_state (pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);

    return 0;
}