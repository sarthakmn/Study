#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <unordered_set>
#include <algorithm>
#include "extractor.h"

namespace fs = std::filesystem;
std::unordered_set<std::string> mediaFormats = {
    ".mp3", ".wav"
};

std::string toLower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

void fastCrawler(const std::string& mountPath) {
    auto iterOptions = fs::directory_options::skip_permission_denied;
    
    for (const auto& entry : fs::recursive_directory_iterator(mountPath, iterOptions)) {
        if (entry.is_regular_file()) {
            std::string ext = toLower(entry.path().extension().string());
            if (mediaFormats.count(ext)) {
                std::cout << entry.path() << std::endl;
                process_metadata(entry.path().string());
            }
        }
    }
}