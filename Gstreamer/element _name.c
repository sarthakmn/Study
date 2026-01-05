#include<gst/gst.h>

int main(int argc,char * argv[]){
  GstElement *source;
  gchar *name;
  gst_init(&argc,&argv);
  source = gst_element_factory_make("audiotestsrc","source");
  g_object_get (G_OBJECT (source), "name", &name, NULL);
  g_print ("The name of the element is %s.\n", name);
  g_free (name);
  gst_object_unref (GST_OBJECT (source));
  return 0;
}