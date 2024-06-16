#include "place.h"
#include <set>

void placeModules(const ParsedData& data, std::vector<std::pair<std::string, std::pair<int, int>>>& placements) {
    int rows = data.dieSize.rows;
    int cols = data.dieSize.cols;
    std::set<std::pair<int, int>> usedPositions;
    int x = 0, y = 0;
    for (const auto& instance : data.instances) {
        while (usedPositions.find({x, y}) != usedPositions.end()) {
            if (++x >= cols) {
                x = 0;
                ++y;
            }
        }
        placements.push_back({instance.name, {x, y}});
        usedPositions.insert({x, y});
    }
}

