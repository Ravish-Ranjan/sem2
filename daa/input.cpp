#ifndef INPUT_CPP
#define INPUT_CPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "util/command.cpp"
#include "util/json.hpp"
using json = nlohmann::json;

// class to give command and get input from python interface 
class Input{
    private:
        int inputSize; // base input size
        std::string inputFile = ""; // input file path got from python 
        std::string inputTypes; // getting different type data from python 
        std::string inputNames; // keys to save data from python into json with
        std::string inputFileName = "algo-data"; // input filename to give in python to generate
        
        // function to fetch json data from generated files
        void getInput() {
            if (this->inputFile == "")
                throw std::runtime_error("Cannot open file");
            std::ifstream file(this->inputFile);

            if (file.is_open()){
                file >> this->input; // saving data into object
                file.close(); // closing file
            } else {
                std::cout << "Error : error opening input from json file" << std::endl; // printing error
            }
        }

    public:
        json input;
        std::string generatorFile = "util/gendataset.py";

        // class constructor to initialize data generation parameter
        Input(std::string inpTp,std::string inpNm,int inpSz = 10,std::string inpFN = "input-data"){
            this->inputSize = inpSz;
            this->inputTypes = inpTp;
            this->inputNames = inpNm;
            this->inputFileName= inpFN;
        }
        
        // function to run command to generate data from python interface
        void genInput(){
            this->input.clear(); // clearing previous data;
            std::string sizeArgv = "size:" + std::to_string(this->inputSize); // command line arguments for size
            std::string inputTypesArgv = "types:" + this->inputTypes; // command line arguments for data types
            std::string inputFileNameArgv = "filename:" + this->inputFileName; // command line arguments for filename
            std::string inputNamesArgv = "names:" + this->inputNames; // command line arguments for json key names
            std::string cmd = "python " + this->generatorFile + " " + sizeArgv + " " + inputTypesArgv + " " + inputNamesArgv + " " + inputFileNameArgv; // command line arguments for full command
            this->inputFile = runCommand(cmd); // running command 
            this->getInput(); // fetching data function run
        }
};

#endif