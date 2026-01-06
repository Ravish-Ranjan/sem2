#include <vector>
#include <string>
#include <functional>
#include <iostream>
#include <cstdio>
#include <memory>
#include <array>
#include <fstream>
#include <sstream>
#include <variant>

bool isInt(const std::string& s) {
    if (s.empty()) return false;
    char* end;
    std::strtol(s.c_str(), &end, 10);
    return end == s.c_str() + s.size();
}

bool isDouble(const std::string& s) {
    if (s.empty()) return false;
    char* end;
    std::strtod(s.c_str(), &end);
    return end == s.c_str() + s.size();
}

using Token = std::variant<int, double, std::string>;

template <typename T>
std::vector<T> parse(const std::vector<Token>& array){
    std::vector<T> res;
    for(auto elem:array){
        res.push_back(std::get<T>(elem));
    }
    return res;
}


template <typename T=std::vector<Token>>
class Input{
    private:
        int inputSize = 10;
        std::string inputFile = "";
        std::string inputTypes = "int";
    public:
        std::vector<T> input;
        Input(int inputSize = 10,std::string inputTypes = "int"):inputSize(inputSize),inputTypes(inputTypes){}
        
        void genInput(){
            std::string sizeArgv = "size:" + std::to_string(this->inputSize);
            std::string inputTypesArgv = "types:" + this->inputTypes;
            std::string cmd = "python3 util/gendataset.py " + sizeArgv + " " + inputTypesArgv;
            this->genInputFile(cmd);
            this->getInput();
        }
        
        void genInputFile(const std::string& cmd) {
            std::array<char, 256> buffer;
            std::string result;
        
            FILE* pipe = popen(cmd.c_str(), "r");
            if (!pipe) throw std::runtime_error("popen failed");
        
            while (fgets(buffer.data(), buffer.size(), pipe)) {
                result += buffer.data();
            }
        
            pclose(pipe);
        
            if (!result.empty() && result.back() == '\n')
                result.pop_back();
        
            this->inputFile = result;
        }
        
        Token parseToken(const std::string& token) {
            if (isInt(token))
                return std::stoi(token);
            if (isDouble(token))
                return std::stod(token);
            return token;
        }
        
        void getInput() {
            std::ifstream file(this->inputFile);
            if (this->inputFile == "")
                throw std::runtime_error("Cannot open file");
        
            std::string line;
            std::vector<std::vector<Token>> tempRows;
        
            // First, read all rows normally
            while (std::getline(file, line)) {
                std::stringstream ss(line);
                std::string token;
                std::vector<Token> row;
        
                while (ss >> token) {
                    row.push_back(parseToken(token));
                }
                
                tempRows.push_back(std::move(row));
            }
            
            // Now transpose: convert rows to columns
            if (tempRows.empty()) return;
            
            size_t numCols = tempRows[0].size();
            
            // Create columns from rows
            for (size_t col = 0; col < numCols; col++) {
                std::vector<Token> column;
                for (size_t row = 0; row < tempRows.size(); row++) {
                    if (col < tempRows[row].size()) {
                        column.push_back(tempRows[row][col]);
                    }
                }
                this->input.push_back(std::move(column));
            }
        }

};