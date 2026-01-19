#ifndef RUNNER_CPP
#define RUNNER_CPP

#include <iostream>
#include <string>

#include "input.cpp"
#include "output.cpp"
#include "util/json.hpp"
using json = nlohmann::json;

class Metric{
    public:
        int comps = 0;
        int assigns = 0;
        virtual void algo(json data,std::string key) = 0;
        
        void reset() {
            comps = 0;
            assigns = 0;
        }

        void printStats() const {
            std::cout << "Comparisons: " << comps << "\n";
            std::cout << "Assignments: " << assigns << "\n";
        }
        
        virtual ~Metric() {}
};

std::vector<std::string> split(std::string inp,char sep = ' '){   
    std::stringstream ss(inp);
    std::string segment;
    std::vector<std::string> results;
    
    while (std::getline(ss, segment, sep)) {
        results.push_back(segment);
    }
    return results;
}
    

#endif