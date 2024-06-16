#ifndef PLACE_H
#define PLACE_H

#include "parser.h"

void placeModules(const ParsedData& data, std::vector<std::pair<std::string, std::pair<int, int>>>& placements);

#endif // PLACE_H

