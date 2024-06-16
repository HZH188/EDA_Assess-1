#ifndef EXPORTER_H
#define EXPORTER_H

#include <vector>
#include <string>

void exportPlacement(const std::string& filename, const std::vector<std::pair<std::string, std::pair<int, int>>>& placements);

#endif // EXPORTER_H

