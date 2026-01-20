#ifndef OUTPUT_CPP
#define OUTPUT_CPP

#include <vector>
#include <iostream>
#include <fstream>

#include "util/json.hpp"
using json = nlohmann::json;

// class to generate output file for algorithm 
class Output{
    public:
        json outputs; // json to store outputs of different sizes
        std::string outputFileName = "output"; // output filename

        // constructor to initialize filename and different size keys in outputs variable
        Output(std::string outFN){
            this->outputFileName = outFN;
            outputs["10"] = {};
            outputs["20"] = {};
            outputs["30"] = {};
            outputs["40"] = {};
            outputs["50"] = {};
            outputs["60"] = {};
            outputs["70"] = {};
            outputs["80"] = {};
            outputs["90"] = {};
            outputs["100"] = {};
        }

        // function to save output in json file
        void saveOutput(){
            std::ofstream outputFile("./output/"+outputFileName+".json"); // opening file

            if (outputFile.is_open()){
                outputFile << outputs.dump(4); // saving json data
                outputFile.close(); // closing file
            } else {
                std::cout << "Error : error opening output to json file" << std::endl; // printing error
            }
        }
};

#endif