#ifndef RADIXSORT_CPP
#define RADIXSORT_CPP

#include "../metric.cpp"
#include "CountSort.cpp"

class RadixSort:public Metric{
    public:
        void algo(json& data,int key) override{
            int range = 0;
            if (data[0][key].is_number_integer()){
                range = 2;
            } else if (data[0][key].is_string()){
                range = 10;
            }

            for (int i = 0; i < range; i++){
                countSort(data,key,i);
            }
            
        }
};

#endif