#include<gst/gst.h>

int main(int argc,char *argv[]){
    GstElement *source, *sink, *pipeline,*bin;
    GstPad *pad;
    
    gst_init(&argc, &argv);

    /* create element, add to bin */
    source = gst_element_factory_make("audiotestsrc","source");
    sink = gst_element_factory_make("alsasink","sink");
    bin = gst_bin_new ("mybin");
    gst_bin_add (GST_BIN (bin), sink); 

    /* add ghostpad */
    pad = gst_element_get_static_pad (sink, "sink");
    gst_element_add_pad (bin, gst_ghost_pad_new ("sink", pad));
    gst_object_unref (GST_OBJECT (pad));

    pipeline = gst_pipeline_new("my_pipe");

    gst_bin_add_many(GST_BIN(pipeline),source,bin,NULL);
    gst_element_link_many(source,bin,NULL);


    lable:
    gst_element_set_state(pipeline,GST_STATE_PLAYING);
    
    goto lable;
    gst_element_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);
    return 0;
}