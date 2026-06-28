#include <taglib/fileref.h>
#include <taglib/tag.h>
#include "extractor.h"

void process_metadata(const std::string& path) {
    TagLib::FileRef f(path.c_str());
    if (!f.isNull() && f.tag()) {
        auto tag = f.tag();
        auto prop = f.audioProperties();

        std::cout << "Title: " << tag->title() << std::endl;
        std::cout << "Artist: " << tag->artist() << std::endl;

        if (prop) {
            std::cout << "Duration: " << prop->length() << " sec" << std::endl;
        }
    }
}