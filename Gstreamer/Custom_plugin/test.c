#include <gst/gst.h>
#include <gst/gstbuffer.h>

#define VERSION "1.0"
#define PACKAGE "myaudiofilter"

typedef struct _MyAudioFilter {
    GstElement element;
    GstPad *sinkpad, *srcpad;
    gdouble gain;
} MyAudioFilter;

typedef struct _MyAudioFilterClass {
    GstElementClass parent_class;
} MyAudioFilterClass;

G_DEFINE_TYPE(MyAudioFilter, my_audio_filter, GST_TYPE_ELEMENT)

static GstFlowReturn my_audio_filter_chain(GstPad *pad, GstObject *parent, GstBuffer *buf) {
    MyAudioFilter *filter = (MyAudioFilter *)parent;
    GstMapInfo map;

    if (gst_buffer_map(buf, &map, GST_MAP_READWRITE)) {
        gint16 *data = (gint16 *)map.data;
        gsize num_samples = map.size / sizeof(gint16);

        for (gsize i = 0; i < num_samples; i++) {
            gdouble sample = data[i] * filter->gain;
            if (sample > G_MAXINT16) sample = G_MAXINT16;
            else if (sample < G_MININT16) sample = G_MININT16;
            data[i] = (gint16)sample;
        }

        gst_buffer_unmap(buf, &map);
    }

    return gst_pad_push(filter->srcpad, buf);
}

static gboolean my_audio_filter_sink_event(GstPad *pad, GstObject *parent, GstEvent *event) {
    MyAudioFilter *filter = (MyAudioFilter *)parent;

    if (GST_EVENT_TYPE(event) == GST_EVENT_CAPS) {
        GstCaps *caps;
        gst_event_parse_caps(event, &caps);
        // Forward the same caps downstream
        gst_pad_set_caps(filter->srcpad, caps);
    }

    return gst_pad_event_default(pad, parent, event);
}

static GstStaticPadTemplate sink_template = GST_STATIC_PAD_TEMPLATE("sink",
    GST_PAD_SINK, GST_PAD_ALWAYS,
    GST_STATIC_CAPS("audio/x-raw, format=S16LE, channels=2, rate=44100"));

static GstStaticPadTemplate src_template = GST_STATIC_PAD_TEMPLATE("src",
    GST_PAD_SRC, GST_PAD_ALWAYS,
    GST_STATIC_CAPS("audio/x-raw, format=S16LE, channels=2, rate=44100"));

static void my_audio_filter_class_init(MyAudioFilterClass *klass) {
    GstElementClass *element_class = GST_ELEMENT_CLASS(klass);
    gst_element_class_add_pad_template(element_class, gst_static_pad_template_get(&sink_template));
    gst_element_class_add_pad_template(element_class, gst_static_pad_template_get(&src_template));
    gst_element_class_set_details_simple(element_class, "My Audio Filter",
        "Filter/Effect/Audio", "Simple gain filter", "Your Name <you@example.com>");
}

static void my_audio_filter_init(MyAudioFilter *filter) {
    filter->gain = 0.3;

    filter->sinkpad = gst_pad_new_from_static_template(&sink_template, "sink");
    gst_pad_set_chain_function(filter->sinkpad, my_audio_filter_chain);
    gst_pad_set_event_function(filter->sinkpad, my_audio_filter_sink_event);
    gst_element_add_pad(GST_ELEMENT(filter), filter->sinkpad);

    filter->srcpad = gst_pad_new_from_static_template(&src_template, "src");
    gst_element_add_pad(GST_ELEMENT(filter), filter->srcpad);
}

static gboolean plugin_init(GstPlugin *plugin) {
    return gst_element_register(plugin, "myaudiofilter", GST_RANK_NONE, my_audio_filter_get_type());
}

GST_PLUGIN_DEFINE(
    GST_VERSION_MAJOR,
    GST_VERSION_MINOR,
    myaudiofilter,
    "Audio gain filter",
    plugin_init,
    "1.0",
    "LGPL",
    "GStreamer",
    "http://gstreamer.net/"
)
