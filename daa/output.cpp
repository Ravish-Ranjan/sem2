#ifndef OUTPUT_CPP
#define OUTPUT_CPP

#include <sstream>
#include <string>
#include "./util/command.cpp"
#include <vector>

class Output{
    private:
        std::string outputGraphImageName = "";
    public:
        Output(std::string outGIN = "algo-analyze"):outputGraphImageName(outGIN){}
        void genGraph(const std::vector<double>& y){
            std::string fileNameArgv = "filename:" + this->outputGraphImageName;
            std::ostringstream yArgv;
            yArgv << "y:";
            for (int i = 0; i<y.size() ;++i){
                if (i > 0) yArgv << ",";
                yArgv << y[i];
            }
            std::string cmd = "python3 util/graphgen.py " + fileNameArgv + " " + yArgv.str();
            runCommand(cmd);
        }
};

#endif