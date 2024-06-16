#include "exporter.h"
#include <fstream>
#include <iostream>

void exportPlacement(const std::string& filename, const std::vector<std::pair<std::string, std::pair<int, int>>>& placements) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for writing: " << filename << std::endl;
        return;
    }

    for (const auto& placement : placements) {
        file << placement.first << " " << placement.second.first << " " << placement.second.second << "\n";
    }

    file.close();
}


