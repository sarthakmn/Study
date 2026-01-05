#include<gst/gst.h>

int main(int argc,char *argv[]){
    GstElement *bin ,*pipeline, *source, *sink, *decode;
    gst_init(&argc,&argv);
    source = gst_element_factory_make("v4l2src","source");
    decode = gst_element_factory_make("videoconvert","decode");
    sink = gst_element_factory_make("autovideosink","sink");
    pipeline = gst_pipeline_new("test_pipe");
    
    gst_bin_add_many(GST_BIN(pipeline),source,decode,sink,NULL);
    
    gst_element_link_many(source,decode,sink,NULL);
    lable:
    gst_element_set_state(pipeline,GST_STATE_PLAYING);

    goto lable;
    gst_element_set_state(pipeline,GST_STATE_NULL);
    gst_object_unref (pipeline);
  
    return 0;
}