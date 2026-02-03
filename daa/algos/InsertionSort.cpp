#ifndef INSERTIONSORT_CPP
#define INSERTIONSORT_CPP

#include "../metric.cpp"

// Inheriting Metric class and overriding algo method
class InsertionSort : public Metric {
    public:
        void algo(json& data,const std::string& key) override{
            for (int i = 1; i< data[key].size(); i++){
                json saved_row;

                for (auto [k, v] : data.items()) saved_row[k] = v[i]; // getting key's indexed data for later  

                auto elem = saved_row[key]; // picking field of saved rowto sort the data with 
                int j = i-1;
                this->assigns++;

                while (j >= 0){
                    this->comps++;
                    if (elem < data[key][j]){
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