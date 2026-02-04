#include "scheduler.cpp"
#include <queue>

class FCFS:public Scheduler{
    public:
        void apply(std::vector<Job>& jobs){
            std::sort(jobs.begin(),jobs.end(),[](const Job& j1,const Job& j2){
                return j1.at < j2.at;
            });
            int gt_time = 0;
            for(Job& job:jobs){
                gt_time+= job.bt;
                job.ct = gt_time;
                job.tat = job.ct-job.at;
                job.wt = job.tat-job.bt;
            }
        }
};

struct BurstComparator{
    bool operator()(const Job& j1,const Job& j2)const {
        return j1.bt < j2.bt;
    }
};

class SRJF:public Scheduler{
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
                int min_bt = __INT_MAX__;
                
                for (int i = 0; i < jobs.size(); i++){
                    if (jobs[i].at <= at && rem_bt[i] > 0 && rem_bt[i] < min_bt){
                        min_bt = rem_bt[i];
                        min_idx = i;
                    }
                }
                
                at++;

                if (min_bt > -1) {   
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

class RR:public Scheduler{
    private:
        int q;
    public:
        RR(int q):q(q){}
        void apply(std::vector<Job>& jobs){
            std::sort(jobs.begin(),jobs.end(),[](const Job& j1,const Job& j2){
                return j1.at < j2.at;
            });

            std::vector<int> rem_bt(jobs.size());
            for (int i = 0; i < jobs.size(); i++){
                rem_bt[i] = jobs[i].bt;
            }

            std::deque<int> ready_q;

            int at = 0;
            int completed = 0;
            int next_idx = 0;

            while(next_idx < jobs.size() && jobs[next_idx].at <= at) {
                ready_q.push_back(next_idx);
                next_idx++;
            }

            while(completed < jobs.size()) {
                if(ready_q.empty()) {
                    if(next_idx < jobs.size()) {
                        at = jobs[next_idx].at;
                        ready_q.push_back(next_idx);
                        next_idx++;
                    }
                    continue;
                }
                
                int job_idx = ready_q.front();
                ready_q.pop_front();  // O(1) with deque
                
                int exec_time = std::min(q, rem_bt[job_idx]);
                rem_bt[job_idx] -= exec_time;
                at += exec_time;
                
                while(next_idx < jobs.size() && jobs[next_idx].at <= at) {
                    ready_q.push_back(next_idx);
                    next_idx++;
                }
                
                if(rem_bt[job_idx] == 0) {
                    jobs[job_idx].ct = at;
                    jobs[job_idx].tat = jobs[job_idx].ct - jobs[job_idx].at;
                    jobs[job_idx].wt = jobs[job_idx].tat - jobs[job_idx].bt;
                    completed++;
                } else {
                    ready_q.push_back(job_idx);
                }
            }
        }
};

int main(){
    int n = 0;
    std::string inp = "";
    std::cout << "Enter the no. of jobs : ";
    std::cin >> n;

    std::vector<Job> jobs_srjf,jobs_rr;
    std::cout << "Enter the properties of following jobs (arival time,burst time)" << std::endl;

    for (int i = 0; i < n; i++){
        std::cout << "P" << i+1 << " : ";
        std::cin >> inp;
        std::vector<std::string> parts = split(inp,',');
        
        jobs_srjf.push_back(Job(i+1,std::stoi(parts[1]),std::stoi(parts[0])));
        jobs_rr.push_back(Job(i+1,std::stoi(parts[1]),std::stoi(parts[0])));
    }

    std::cout << "SRJF" << std::endl;
    
    SRJF srjf;
    srjf.apply(jobs_srjf);
    srjf.printTable(jobs_srjf);
    srjf.getAvgs(jobs_srjf);
    
    std::cout << "RR" << std::endl;
    RR rr(4);
    rr.apply(jobs_rr);
    rr.printTable(jobs_rr);
    rr.getAvgs(jobs_rr);

    return 0;
}