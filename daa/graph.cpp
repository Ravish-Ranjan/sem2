#ifndef CREATE_GRAPH_CPP
#define CREATE_GRAPH_CPP

#include <sstream>
#include <string>
#include <vector>

#include "util/command.cpp"

// function to open generates graphs
void openImageInNativeViewer(const std::string& imagePath) {
    #ifdef _WIN32
        std::string cmd = "cmd /c start \"\" \"" + imagePath + "\"";
    #elif __APPLE__
        std::string cmd = "open \"" + imagePath + "\"";
    #else
        std::string cmd = "xdg-open \"" + imagePath + "\"";
    #endif
    
    runCommand(cmd + " >/dev/null 2>&1 &");
}


// graph class for generating class
class GraphPlot{
    public:
        std::string graphName = ""; // graph filename and graph title
        // constructor of graph class to store filename and graph title
        GraphPlot(std::string grfNm = "algo-analyze"){
            this->graphName = grfNm;
        }
        
        // function generate graph from python interface
        void genGraph(const std::vector<std::vector<double>>& valueLists,const std::vector<std::string>& listNames){
            std::string fileNameArgv = "filename:" + this->graphName; // command line argument for filename
            std::string graphTitleArgv = "title:" + this->graphName; // command line argument for graph title
            std::string cmd = "python util/graphgen.py " + fileNameArgv + " " + graphTitleArgv + " "; // complete command prefix

            std::ostringstream yArgv;
            for (int i = 0; i<listNames.size(); i++){
                yArgv << listNames[i] << ":";
                for (int j = 0; j<valueLists[i].size(); j++){
                    if (j > 0) yArgv << ",";
                    yArgv << valueLists[i][j];
                }
                yArgv << " "; 
            }
            
            // running command 
            runCommand(cmd+yArgv.str());
            // openging image file
            openImageInNativeViewer("./images/"+this->graphName+".png");
        }
};

#endif