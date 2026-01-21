#ifndef GRAPH_CPP
#define GRAPH_CPP

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
class Graph{
    private:
        std::string graphName = ""; // graph filename and graph title
    public:
        // constructor of graph class to store filename and graph title
        Graph(std::string grfNm = "algo-analyze"){
            this->graphName = grfNm;
        }
        
        // function generate graph from python interface
        void genGraph(const std::vector<double>& comps,const std::vector<double>& assigns){
            std::string fileNameArgv = "filename:" + this->graphName; // command line argument for filename
            std::string graphTitleArgv = "title:" + this->graphName; // command line argument for graph title
            std::string cmd = "python util/graphgen.py " + fileNameArgv + " " + graphTitleArgv + " "; // complete command prefix

            // command line argument for plotting comparisions on graph
            std::ostringstream yArgv1;
            yArgv1 << "comparisions:";
            for (int i = 0; i<comps.size() ;++i){
                if (i > 0) yArgv1 << ",";
                yArgv1 << comps[i];
            }
            cmd = cmd + yArgv1.str() + " ";
            
            // command line argument for plotting assignments on graph
            std::ostringstream yArgv2;
            yArgv2 << "assignments:";
            for (int i = 0; i<assigns.size() ;++i){
                if (i > 0) yArgv2 << ",";
                yArgv2 << assigns[i];
            }
            cmd += yArgv2.str();
            
            // running command 
            runCommand(cmd);
            // openging image file
            openImageInNativeViewer("./images/"+this->graphName+".png");
        }
};

#endif