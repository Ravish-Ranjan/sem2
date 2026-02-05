#ifndef QUICKSORT_CPP
#define QUICKSORT_CPP

#include "../metric.cpp"

class QuickSort:public Metric{
    int partition(json& data,int low,int high,int key){
        int pivot = data[high][key];
        int i = low-1;
        for (int j = low; j<high; j++){
            if (data[j][key] <= pivot){
                i++;
                swapJson(data,i,j);
            }
        }
        swapJson(data,i+1,high);
        return i+1;
    }
    void quickSort(json& data,int low,int high,int key){
        if (low < high){
            int p = partition(data,low,high,key);
            quickSort(data,low,p-1,key);
            quickSort(data,p+1,high,key);
        }
    }
    void algo(json& data,int key) override{
        quickSort(data,0,data.size()-1,key);
    }
};

#endif