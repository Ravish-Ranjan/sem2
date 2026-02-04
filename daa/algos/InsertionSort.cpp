#ifndef INSERTIONSORT_CPP
#define INSERTIONSORT_CPP

#include "../metric.cpp"

// Inheriting Metric class and overriding algo method
class InsertionSort : public Metric {
    public:
        void algo(json& data,int key) override{
            for (int i = 1; i< data.size(); i++){
                json saved_row = data[i];

                auto elem = saved_row[key]; // picking field of saved rowto sort the data with 
                int j = i-1;
                this->assigns++;

                while (j >= 0){
                    this->comps++;
                    if (elem < data[j][key]){
                        assign(data,j,j+1); // custom assign function for json
                        this->assigns++;
                        j--;
                    } else {
                        break;
                    }
                }
                assign(data,j+1,saved_row); 
                this->assigns++;
            }
        }
};

#endif