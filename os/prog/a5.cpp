#include "scheduler.cpp"
#include <queue>

class PPS:public Scheduler{
    public:
        void apply(std::vector<Job>& jobs){
            std::sort(jobs.begin(),jobs.end(),[](const Job& j1,const Job& j2){
                return j1.at < j2.at;
            });
            
            std::vector<int> rem_bt(jobs.size());
            for (int i = 0; i < jobs.size(); i++){
                rem_bt[i] = jobs[i].bt;
            }
            
            int at = 0;
            int completed = 0;

            while (completed < jobs.size()){
                int min_idx = -1;
                int min_pt = __INT_MAX__;
                
                for (int i = 0; i < jobs.size(); i++){
                    if (jobs[i].at <= at && rem_bt[i] > 0 && jobs[i].pt < min_pt){
                        min_pt = jobs[i].pt;
                        min_idx = i;
                    }
                }
                
                at++;

                if (min_pt > -1) {   
                    rem_bt[min_idx]--;;
                    if (rem_bt[min_idx] <= 0){
                        jobs[min_idx].ct = at;
                        jobs[min_idx].tat = jobs[min_idx].ct - jobs[min_idx].at;
                        jobs[min_idx].wt = jobs[min_idx].tat - jobs[min_idx].bt;
                        completed++;
                    }
                }
            }
        }
};

int main(){
    int n = 0;
    std::string inp = "";
    std::cout << "Enter the no. of jobs : ";
    std::cin >> n;

    std::vector<Job> jobs_pps;
    std::cout << "Enter the properties of following jobs (arival time,burst time,priority)" << std::endl;

    for (int i = 0; i < n; i++){
        std::cout << "P" << i+1 << " : ";
        std::cin >> inp;
        std::vector<std::string> parts = split(inp,',');
        
        jobs_pps.push_back(Job(i+1,std::stoi(parts[1]),std::stoi(parts[0]),std::stoi(parts[2])));
    }

    PPS pps;
    pps.apply(jobs_pps);
    pps.printTable(jobs_pps);
    pps.getAvgs(jobs_pps);

    return 0;
}