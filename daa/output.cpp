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
        void genGraph(const std::vector<double>& comps,const std::vector<double>& assigns){
            std::string fileNameArgv = "filename:" + this->outputGraphImageName;
            std::string cmd = "python3 util/graphgen.py " + fileNameArgv + " ";

            std::ostringstream yArgv1;
            yArgv1 << "comparisions:";
            for (int i = 0; i<comps.size() ;++i){
                if (i > 0) yArgv1 << ",";
                yArgv1 << comps[i];
            }
            cmd = cmd + yArgv1.str() + " ";
            
            std::ostringstream yArgv2;
            yArgv2 << "assignments:";
            for (int i = 0; i<assigns.size() ;++i){
                if (i > 0) yArgv2 << ",";
                yArgv2 << assigns[i];
            }
            cmd += yArgv2.str();
            
            runCommand(cmd);
        }
};

#endif