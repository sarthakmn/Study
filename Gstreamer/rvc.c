#include <gst/gst.h>

int main(int argc, char *argv[]) {
    GstElement *pipeline, *source, *convert, *scale, *encoder, *muxer, *sink;
    GstBus *bus;
    GstMessage *msg;
    GstStateChangeReturn ret;

    /* Initialize GStreamer */
    gst_init(&argc, &argv);

    /* Create the elements */
    source = gst_element_factory_make("v4l2src", "source");
    convert = gst_element_factory_make("videoconvert", "convert");
    scale = gst_element_factory_make("videoscale", "scale");
    encoder = gst_element_factory_make("x264enc", "encoder");
    muxer = gst_element_factory_make("mp4mux", "muxer");
    sink = gst_element_factory_make("filesink", "sink");

    /* Check for missing elements */
    if (!source || !convert || !scale || !encoder || !muxer || !sink) {
        g_printerr("Not all elements could be created.\n");
        return -1;
    }

    /* Set properties */
    g_object_set(source, "device", "/dev/video0", NULL);
    g_object_set(sink, "location", "rvc.mp4", NULL);
    
    /* Enable fragmentation for proper MP4 finalization */
    g_object_set(muxer, "faststart", TRUE, NULL);  // MP4 optimizes for streaming
    g_object_set(muxer, "fragment-duration", 1000, NULL); // Creates small fragments

    /* Create the pipeline */
    pipeline = gst_pipeline_new("video-pipeline");

    if (!pipeline) {
        g_printerr("Pipeline could not be created.\n");
        return -1;
    }

    /* Build the pipeline */
    gst_bin_add_many(GST_BIN(pipeline), source, convert, scale, encoder, muxer, sink, NULL);
    if (!gst_element_link_many(source, convert, scale, encoder, muxer, sink, NULL)) {
        g_printerr("Elements could not be linked.\n");
        gst_object_unref(pipeline);
        return -1;
    }

    /* Start playing the pipeline */
    ret = gst_element_set_state(pipeline, GST_STATE_PLAYING);
    if (ret == GST_STATE_CHANGE_FAILURE) {
        g_printerr("Unable to set the pipeline to the playing state.\n");
        gst_object_unref(pipeline);
        return -1;
    }

    /* Let the pipeline run for 5 seconds to record video */
    g_print("Recording video for 5 seconds...\n");
    g_usleep(10 * 500000);  // Sleep for 10 seconds

    /* Send EOS to ensure file is properly closed */
    g_print("Sending EOS to finalize the recording...\n");
    gst_element_send_event(pipeline, gst_event_new_eos());

    /* Wait for EOS message or error */
    bus = gst_element_get_bus(pipeline);
    msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE,
                                     GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

    /* Parse message */
    if (msg != NULL) {
        GError *err;
        gchar *debug_info;

        switch (GST_MESSAGE_TYPE(msg)) {
        case GST_MESSAGE_ERROR:
            gst_message_parse_error(msg, &err, &debug_info);
            g_printerr("Error received from element %s: %s\n",
                       GST_OBJECT_NAME(msg->src), err->message);
            g_printerr("Debugging information: %s\n",
                       debug_info ? debug_info : "none");
            g_clear_error(&err);
            g_free(debug_info);
            break;
        case GST_MESSAGE_EOS:
            g_print("End-Of-Stream reached, file finalized.\n");
            break;
        default:
            g_printerr("Unexpected message received.\n");
            break;
        }
        gst_message_unref(msg);
    }

    /* Free resources */
    gst_object_unref(bus);
    gst_element_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);

    return 0;
}
