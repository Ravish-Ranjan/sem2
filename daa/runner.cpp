#include <vector>
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