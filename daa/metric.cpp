#ifndef METRIC_CPP
#define METRIC_CPP

#include <iostream>
#include <string>
#include <vector>

#include "util/json.hpp"
using json = nlohmann::json;

// custom assign function to assign data from one index to other in data
void assign(json& data,int from, int to){
    data[to] = data[from];
}

// custom assign function to assign data from given object to given data 
void assign(json& data, int to, const json& saved_row) {
    data[to] = saved_row;
}

void swapJson(json& data,int first,int second){
    json firstData = data[first];
    data[first] = data[second];
    data[second] = firstData;
}

// function to print json data
void printJson(const json& data){
    if (data.is_array()) {
        // Handle array of arrays or array of objects
        for(size_t i = 0; i < data.size(); i++){
            const auto& elem = data[i];
            
            if (elem.is_array()) {
                // Array of arrays
                for(const auto& item : elem){
                    std::cout << item << " ";
                }
            } else if (elem.is_object()) {
                // Array of objects - print values
                for(auto it = elem.begin(); it != elem.end(); ++it){
                    std::cout << it.value() << " ";
                }
            } else {
                // Array of primitives
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
    } else if (data.is_object()) {
        // Handle single object
        for(auto it = data.begin(); it != data.end(); ++it){
            std::cout << it.key() << ": " << it.value() << std::endl;
        }
    } else {
        // Handle primitive
        std::cout << data << std::endl;
    }
}

// abstract class with algo function to override and implement own algorithm
class Metric{
    public:
        int comps = 0; // variable to store comparisions
        int assigns = 0; // variable to store assignments
        virtual void algo(json& data,int key) = 0; // virtual function to be overriden in inheriting clas
        
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

#endif