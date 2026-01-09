#ifndef RUNNER_CPP
#define RUNNER_CPP

#include "input.cpp"
#include "output.cpp"
#include <vector>
#include <string>
#include <chrono>
#include <functional>

template <typename Func>
class Runner{
    Func func;
    public:
        std::vector<double> timeTakes;
        Runner(Func f):func(f){}

        template <typename...Args>
        double run(Args&&... args){
            auto start = std::chrono::high_resolution_clock::now();
            func(std::forward<Args>(args)...);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double,std::micro> duration = (end - start);
            this->timeTakes.push_back(duration.count());
            return duration.count();
        }

        double getAvgTime(){
            if (this->timeTakes.size() <= 0) return 0.0;
            double avg = 0.0;
            for(double elem:this->timeTakes) avg+= elem;
            return avg/this->timeTakes.size();
        }
};

template <typename inputParseType,typename Func>
std::vector<double> analyzer(std::string inputTypes,Func algo,std::string inpFN = "input-data"){
    std::vector<double> timeAvgs;
    for (int size = 10; size<=100; size+=10){
        Input inp(size,inputTypes,inpFN);
        Runner runner(algo);
        for (int i = 0; i<10; i++){
            inp.genInput();
            std::vector<inputParseType> copy = parse<inputParseType>(inp.input[0]);
            runner.run(copy);
        }
        timeAvgs.push_back(runner.getAvgTime());
    }
    Output output(inpFN);
    output.genGraph(timeAvgs);
    return timeAvgs;
}
#endif