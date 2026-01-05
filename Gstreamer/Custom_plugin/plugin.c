#include <gst/gst.h>
#include <gst/gstbuffer.h>

#define VERSION "1.0"
#define PACKAGE "loudnessfilter"

enum {
    PROP_0,
    PROP_GAIN
};

typedef struct _loudnessFilter {
    GstElement element;
    GstPad *sinkpad, *srcpad;
    gdouble gain;
} loudnessFilter;

typedef struct _loudnessFilterClass {
    GstElementClass parent_class;
} loudnessFilterClass;

G_DEFINE_TYPE(loudnessFilter, loudness_filter, GST_TYPE_ELEMENT)

static void loudness_filter_set_property(GObject *object, guint prop_id, const GValue *value, GParamSpec *pspec) {
    loudnessFilter *filter = (loudnessFilter *)object;
    switch (prop_id) {
        case PROP_GAIN:
            filter->gain = g_value_get_double(value);
            break;
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
            break;
    }
}

static void loudness_filter_get_property(GObject *object, guint prop_id, GValue *value, GParamSpec *pspec) {
    loudnessFilter *filter = (loudnessFilter *)object;
    switch (prop_id) {
        case PROP_GAIN:
            g_value_set_double(value, filter->gain);
            break;
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
            break;
    }
}

static GstFlowReturn loudness_filter_chain(GstPad *pad, GstObject *parent, GstBuffer *buf) {
    loudnessFilter *filter = (loudnessFilter *)parent;
    GstMapInfo map;

    if (gst_buffer_map(buf, &map, GST_MAP_READWRITE)) {
        gint16 *data = (gint16 *)map.data;
        gsize num_samples = map.size / sizeof(gint16);

        for (gsize i = 0; i < num_samples; i++) {
            gdouble sample = data[i] * filter->gain;
            if (sample > G_MAXINT16) sample = G_MAXINT16;
            else if (sample < G_MININT16) sample = G_MININT16;
            else
            data[i] = (gint16)sample;
        }
        gst_buffer_unmap(buf, &map);
    }
    return gst_pad_push(filter->srcpad, buf);
}

static gboolean loudness_filter_sink_event(GstPad *pad, GstObject *parent, GstEvent *event) {
    loudnessFilter *filter = (loudnessFilter *)parent;

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

static void loudness_filter_class_init(loudnessFilterClass *klass) {
    GObjectClass *gobject_class = G_OBJECT_CLASS(klass);
    GstElementClass *element_class = GST_ELEMENT_CLASS(klass);

    gobject_class->set_property = loudness_filter_set_property;
    gobject_class->get_property = loudness_filter_get_property;

    g_object_class_install_property(gobject_class, PROP_GAIN,
        g_param_spec_double("gain", "Gain", "Amplification gain",
                            0.0, 10.0, 1.0, G_PARAM_READWRITE));

    gst_element_class_add_pad_template(element_class, gst_static_pad_template_get(&sink_template));
    gst_element_class_add_pad_template(element_class, gst_static_pad_template_get(&src_template));
    gst_element_class_set_details_simple(element_class, "loudness Filter",
        "Filter/Effect/Audio", "Simple gain filter", "Sarthak Nanivadekar <sarthaknanivadekar@gmail.com>");
}

static void loudness_filter_init(loudnessFilter *filter) {
    filter->gain = 1.0;
    
    filter->sinkpad = gst_pad_new_from_static_template(&sink_template, "sink");
    gst_pad_set_chain_function(filter->sinkpad, loudness_filter_chain);
    gst_pad_set_event_function(filter->sinkpad, loudness_filter_sink_event);
    gst_element_add_pad(GST_ELEMENT(filter), filter->sinkpad);

    filter->srcpad = gst_pad_new_from_static_template(&src_template, "src");
    gst_element_add_pad(GST_ELEMENT(filter), filter->srcpad);
}

static gboolean plugin_init(GstPlugin *plugin) {
    return gst_element_register(plugin, "loudnessFilter", GST_RANK_NONE, loudness_filter_get_type());
}

GST_PLUGIN_DEFINE(
    GST_VERSION_MAJOR,
    GST_VERSION_MINOR,
    loudnessfilter,
    "Loudness filter",
    plugin_init,
    "1.0",
    "LGPL",
    "GStreamer",
    "http://gstreamer.net/"
)
