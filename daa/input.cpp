#ifndef INPUT_CPP
#define INPUT_CPP

#include "util/command.cpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "util/json.hpp"
using json = nlohmann::json;

class Input{
    private:
        int inputSize = 10;
        std::string inputFile = "";
        std::string inputTypes = "int";
        std::string inputNames = "int";
        std::string inputFileName = "input-data";

        void getInput() {
            if (this->inputFile == "")
                throw std::runtime_error("Cannot open file");
            std::ifstream file(this->inputFile);
            file >> this->input;
        }

    public:
        json input;
        Input(std::string inpTp,std::string inpNm,int inpSz = 10,std::string inpFN = "input-data"){
            this->inputSize = inpSz;
            this->inputTypes = inpTp;
            this->inputNames = inpNm;
            this->inputFileName= inpFN;
        }
        
        void genInput(){
            this->input.clear();
            std::string sizeArgv = "size:" + std::to_string(this->inputSize);
            std::string inputTypesArgv = "types:" + this->inputTypes;
            std::string inputFileNameArgv = "filename:" + this->inputFileName;
            std::string inputNamesArgv = "names:" + this->inputNames;
            std::string cmd = "python3 util/gendataset.py " + sizeArgv + " " + inputTypesArgv + " " + inputNamesArgv + " " + inputFileNameArgv;
            this->inputFile = runCommand(cmd);
            this->getInput();
        }
};

#endif