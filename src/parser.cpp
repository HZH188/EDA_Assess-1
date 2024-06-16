#include "parser.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool parseFile(const std::string& filename, ParsedData& data) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string keyword;
        iss >> keyword;
        if (keyword == "DieSize") {
            iss >> data.dieSize.rows >> data.dieSize.cols;
            std::cout << "Parsed DieSize: " << data.dieSize.rows << " " << data.dieSize.cols << std::endl;
        } else if (keyword == "NumInstances") {
            int numInstances;
            iss >> numInstances;
            data.instances.resize(numInstances);
            std::cout << "Parsed NumInstances: " << numInstances << std::endl;
            for (int i = 0; i < numInstances; ++i) {
                std::getline(file, line);
                std::istringstream instanceLine(line);
                std::string instanceName;
                instanceLine >> instanceName;
                data.instances[i].name = instanceName;
                std::cout << "Parsed Instance: " << data.instances[i].name << std::endl;
            }
        } else if (keyword == "NumNets") {
            int numNets;
            iss >> numNets;
            data.nets.resize(numNets);
            std::cout << "Parsed NumNets: " << numNets << std::endl;
            for (int i = 0; i < numNets; ++i) {
                std::getline(file, line);
                std::istringstream netLine(line);
                std::string netName;
                netLine >> netName;
                data.nets[i].name = netName;
                int numPins;
                netLine >> numPins;
                data.nets[i].pins.resize(numPins);
                std::cout << "Parsed Net: " << data.nets[i].name << " with " << numPins << " pins" << std::endl;
                for (int j = 0; j < numPins; ++j) {
                    std::getline(file, line);
                    std::istringstream pinLine(line);
                    std::string pinName;
                    pinLine >> pinName;
                    data.nets[i].pins[j] = pinName;
                    std::cout << "Parsed Pin: " << data.nets[i].pins[j] << std::endl;
                }
            }
        }
    }

    file.close();
    return true;
}

