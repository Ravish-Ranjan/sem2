#ifndef METRIC_CPP
#define METRIC_CPP

#include <iostream>
#include <string>
#include <vector>

#include "util/json.hpp"
using json = nlohmann::json;

// custom assign function to assign data from one index to other in data
void assign(json& data,int from, int to){
    for (auto& it:data.items()){
        data[it.key()][to] = data[it.key()][from];
    }
}

// custom assign function to assign data from given object to given data 
void assign(json& data, int to, const json& saved_row) {
    for (auto& it : data.items()) {
        data[it.key()][to] = saved_row[it.key()];
    }
}

// function to print json data
void printJson(const json& data){
     for (auto& it:data.items()){
        std::cout << it.key() << " : ";
        for (auto elem:data[it.key()]){
            std::cout << elem << " ";
        }
        std::cout << std::endl;
     }
}

// abstract class with algo function to override and implement own algorithm
class Metric{
    public:
        int comps = 0; // variable to store comparisions
        int assigns = 0; // variable to store assignments
        virtual void algo(json& data,const std::string& key) = 0; // virtual function to be overriden in inheriting clas
        
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