#include <iostream>
#include <unistd.h>
#include "parser.h"
#include "place.h"
#include "exporter.h"

int main() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        std::cout << "Current working dir: " << cwd << std::endl;
    } else {
        perror("getcwd() error");
        return 1;
    }

    const std::string filename = "../input.txt"; // Adjust the path accordingly
    std::cout << "Looking for file: " << filename << std::endl;

    ParsedData data;
    if (!parseFile(filename, data)) {
        std::cerr << "Error reading input file" << std::endl;
        return 1;
    }

    std::vector<std::pair<std::string, std::pair<int, int>>> placements;
    placeModules(data, placements);

    exportPlacement("output.txt", placements);

    std::cout << "Placement completed successfully" << std::endl;
    return 0;
}

