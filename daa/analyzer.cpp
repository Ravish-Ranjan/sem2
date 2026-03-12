#ifndef ANALYZER_CPP
#define ANALYZER_CPP

#include "input.cpp"
#include "metric.cpp"
#include "output.cpp"
#include <chrono>

// analyzer class for re-analyzing any algorithms
class Analyzer{
    public:
        std::string inputTypes; // input type (name,int,float,charLower,charUpper,firstName,lastName)
        std::string inputNames; // json keys to put the data into
        std::string algoName; // algoName to be used for filenames
        std::string outputName = "output"; // output name to be used for filenames
        Metric& algoObj; // algo object for algorithm access
        bool preserveIntermediate; // flag to preserve data inbetween multiple analyzer runs
        json data; // cache intermedia te data
        int repetitions = 10;
        bool getTime;
        std::vector<double> comps,assigns,time;

        // class constructor 
        Analyzer(std::string inpTp,std::string inpNm,Metric& algoObj,std::string algoNm = "algo",bool getTime = false,bool presIntr=false) : algoObj(algoObj){
            this->inputTypes = inpTp;
            this->inputNames = inpNm;
            this->algoName = algoNm;
            this->preserveIntermediate = presIntr;
            this->getTime = getTime;
            if (presIntr){
                comps = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
                assigns = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
                time = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
            }
        }

        // analyzer function to analyze any algorithm
        json analyze(int key,std::string outNm = "output",std::string generatorFile = "util/gendataset.py"){
            Output out(outNm); // object of class output to save output

            std::cout << "Input file generated in input folder" << std::endl;
            // running algo for sifferent input size
            for (int size = 10; size <= 100; size+=10){
                // object of class input to get input data from python interface
                Input inp(this->inputTypes,this->inputNames,size,this->algoName);
                inp.generatorFile = generatorFile;
        
                double totalComps = 0; // comparisions for current size
                double totalAssigns = 0; // assignments for current size
                double totalTime = 0;
                json saveData; // data for saving in output
        
                std::string sizeStr = std::to_string(size);

                for (int rep = 0; rep<this->repetitions; rep++){
                    json copy;

                    if (
                        this->preserveIntermediate && 
                        this->data.contains(sizeStr) && 
                        this->data[sizeStr].size() > rep) 
                    {
                        // if user wants to preserve the intermediate data state and if chache exists, pick data from the cache
                        copy = this->data[sizeStr][rep];
                    } else {
                        inp.genInput(); // if not generate new data
                        copy = inp.input; // making copy of data so that multiple sort work actually

                        if (this->preserveIntermediate) {
                            this->data[sizeStr].push_back(copy); // saving cache
                        }
                    }
                    
                    if (this->getTime){
                        auto start = std::chrono::high_resolution_clock::now();
                        algoObj.algo(copy,key); // running algorithm
                        auto stop = std::chrono::high_resolution_clock::now();
                        std::chrono::duration<double,std::micro> dur = stop-start;
                        totalTime += dur.count(); // accumalating time 
                    } else {
                        algoObj.algo(copy,key); // running algorithm
                    }

                    totalComps += algoObj.comps; // accumalating comparisions 
                    totalAssigns += algoObj.assigns; // accumalating assignments
                    algoObj.reset(); // resetting metrics for current run
                
                    if (rep == 9) saveData = copy; // saving last run for output
                }

                if (this->preserveIntermediate){
                    int idx = (size-1)/10;
                    comps[idx] += totalComps/(double)10.0; // saving avg comparisions for graph 
                    assigns[idx] += totalAssigns/(double)10.0; // saving avg assignments for graph
                    if (this->getTime)
                        time[idx] += totalTime/(double)10.0;
                } else {
                    comps.push_back(totalComps/(double)10.0); // saving avg comparisions for graph 
                    assigns.push_back(totalAssigns/(double)10.0); // saving avg assignments for graph
                    if (this->getTime)
                        time.push_back(totalTime/(double)10.0);
                }
                 // saving avg time for graph
                
                out.outputs["data"][sizeStr] = saveData; // saving data to output object

                if (this->preserveIntermediate && this->data.contains(sizeStr)){ // saving new data back in cache
                    for(auto& dataset:this->data[sizeStr]){
                        dataset = saveData;
                    }
                }
            }
            out.outputs["comps"] = comps;
            out.outputs["assigns"] = assigns;
            out.outputs["c-time"] = time;
            
            std::cout << std::endl;

            std::cout << std::endl;
            out.saveOutput(); // saving output

            return {{"comps",comps},{"assigns",assigns},{"time",time}}; // returning comparisions, assignments and time
        }
};

#endif