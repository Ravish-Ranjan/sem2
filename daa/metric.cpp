#ifndef METRIC_CPP
#define METRIC_CPP

#include <iostream>
#include <string>
#include <vector>

#include "util/json.hpp"
using json = nlohmann::json;

// abstract class with algo function to override and implement own algorithm
class Metric{
    public:
        int comps = 0; // variable to store comparisions
        int assigns = 0; // variable to store assignments
        virtual void algo(json& data,std::string key) = 0; // virtual function to be overriden in inheriting clas
        
        // function to reset metric variables 
        void reset() {
            comps = 0;
            assigns = 0;
        }

        // function to print algorithm metrics
        void printStats() const {
            std::cout << "Comparisons: " << comps << "\n";
            std::cout << "Assignments: " << assigns << "\n";
        }
        
        virtual ~Metric() {} // virtual destructor for inherited classs
};

// function to split string by separator and return in vector
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