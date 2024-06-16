#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>

struct Instance {
    std::string name;
};

struct Net {
    std::string name;
    std::vector<std::string> pins;
};

struct DieSize {
    int rows;
    int cols;
};

struct ParsedData {
    DieSize dieSize;
    std::vector<Instance> instances;
    std::vector<Net> nets;
};

bool parseFile(const std::string& filename, ParsedData& data);

#endif // PARSER_H

