#ifndef SCHEDULER_CPP
#define SCHEDULER_CPP

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>


std::vector<std::string> split(std::string inp,char sep = ' '){   
    std::stringstream ss(inp);
    std::string segment;
    std::vector<std::string> results;
    
    while (std::getline(ss, segment, sep)) results.push_back(segment);

    return results;
}

class Job{
    public:
        int id;
        int at;
        int bt;
        int pt;
        int ct = 0;
        int tat = 0;
        int wt = 0;
        int rt = 0;

        Job(int id,int bt,int at = 0,int pt = 0):id(id),bt(bt),at(at),pt(pt){}
};

class Scheduler{
    public:
        virtual void apply(std::vector<Job>& jobs) = 0;
        void printTable(const std::vector<Job>& jobs){
            std::cout << "\nid\tat\tbt\tpt\tct\ttat\twt\trt" << std::endl;
            for (Job job:jobs){
                printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",job.id,job.at,job.bt,job.pt,job.ct,job.tat,job.wt,job.rt);
            }
            std::cout << std::endl;
        }
        void getAvgs(const std::vector<Job>& jobs){
            double avgTat,avgWt,avgRt;
            for(Job job:jobs){
                avgTat += job.tat;
                avgWt += job.wt;
                avgRt += job.rt;
            }
            std::cout << "Avg. Turn Around Time : " << (double)avgTat/jobs.size() << std::endl;
            std::cout << "Avg. Waiting Time : " << (double)avgWt/jobs.size() << std::endl;
            // std::cout << "Avg. Response Time : " << (double)avgRt/jobs.size() << std::endl;
        }
};

#endif