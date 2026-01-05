#include<gst/gst.h>
#include <stdio.h>

int main(int argc ,char *argv[]){
    const gchar *nano_str;
    guint major, minor, micro, nano;

    gst_init(&argc,&argv);
    gst_version (&major, &minor, &micro, &nano);
    printf ("This program is linked against GStreamer %d.%d.%d \n",major, minor, micro);
    //or use GST_VERSION_MAJOR, GST_VERSION_MINOR, GST_VERSION_MICRO 
    return 0;
}  