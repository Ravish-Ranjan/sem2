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
            outputs["data"] = {};
            outputs["comps"] = {};
            outputs["assigns"] = {};
        }

        // function to save output in json file
        void saveOutput(){
            std::ofstream outputFile("./output/"+outputFileName+".json"); // opening file

            if (outputFile.is_open()){
                outputFile << outputs.dump(4); // saving json data
                outputFile.close(); // closing file
                std::cout << "Output file saved : " << ("./output/"+outputFileName+".json") << std::endl; // printing output file path
            } else {
                std::cout << "Error : error opening output to json file" << std::endl; // printing error
            }
        }
        json getSavedOutput(const std::string& readFrom) const {
            std::ifstream inputFile("./output/"+readFrom+".json"); // opening file

            json allData;

            if (inputFile.is_open()){
                inputFile >> allData; // reading json data
                inputFile.close(); // closing file
                std::cout << "Output file loaded : " << ("./output/"+readFrom+".json") << std::endl; // printing output file path
            } else {
                std::cout << "Error : error opening output from json file" << std::endl; // printing error
            }
            return allData;
        }
};

#endif