#include<gst/gst.h>
static gboolean idle_exit_loop (gpointer data)
    {
    g_main_loop_quit ((GMainLoop *) data);
    /* once */
    return FALSE;
}
static void cb_typefound (GstElement *typefind,guint probability, GstCaps *caps, gpointer data)
{
    GMainLoop *loop = data;
    gchar *type;
    type = gst_caps_to_string (caps);
    g_print ("Media type %s found, probability %d%%\n", type, probability);
    g_free (type);
    g_idle_add (idle_exit_loop, loop);
}
gint main (gint argc, gchar *argv[])
{
GMainLoop *loop;
GstElement *pipeline, *filesrc, *typefind, *fakesink;
GstBus *bus;
/* init GStreamer */
gst_init (&argc, &argv);
loop = g_main_loop_new (NULL, FALSE);

/* create a new pipeline to hold the elements */
pipeline = gst_pipeline_new ("pipe");

/* create file source and typefind element */
filesrc = gst_element_factory_make ("filesrc", "source");
g_object_set (G_OBJECT (filesrc), "location", "video_india.mp4", NULL);
typefind = gst_element_factory_make ("typefind", "typefinder");
g_signal_connect (typefind, "have-type", G_CALLBACK (cb_typefound), loop);
fakesink = gst_element_factory_make ("fakesink", "sink");
/* setup */
gst_bin_add_many (GST_BIN (pipeline), filesrc, typefind, fakesink, NULL);
gst_element_link_many (filesrc, typefind, fakesink, NULL);
gst_element_set_state (GST_ELEMENT (pipeline), GST_STATE_PLAYING);
g_main_loop_run (loop);
/* unset */
gst_element_set_state (GST_ELEMENT (pipeline), GST_STATE_NULL);
gst_object_unref (GST_OBJECT (pipeline));
return 0;
}