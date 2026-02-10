#ifndef RANDOMQUICKSORT_CPP
#define RANDOMQUICKSORT_CPP

#include <random>
#include "../metric.cpp"

class RandomQuickSort:public Metric{
    public:
        int partition(json& data,int low,int high,int key){
            json pivot = data[high][key];
            this->assigns++;
            int i = low-1;
            for (int j = low; j<high; j++){
                this->comps++;
                if (data[j][key] <= pivot){
                    i++;
                    swapJson(data,i,j);
                    this->assigns++;
                }
            }
            swapJson(data,i+1,high);
            this->assigns++;
            return i+1;
        }
        int getRandomInt(int min, int max) {
            static std::random_device rd;
            static std::mt19937 gen(rd());            
            std::uniform_int_distribution<> distrib(min, max);
            return distrib(gen);
        }
        int partitionRand(json& data,int low,int high,int key){
            int from = getRandomInt(low,high);
            swapJson(data,from,high);
            return partition(data,low,high,key);
        }
        void quickSort(json& data,int low,int high,int key){
            this->comps++;
            if (low < high){
                int p = partitionRand(data,low,high,key);
                quickSort(data,low,p-1,key);
                quickSort(data,p+1,high,key);
            }
        }
        void algo(json& data,int key) override{
            quickSort(data,0,data.size()-1,key);
        }
};

#endif