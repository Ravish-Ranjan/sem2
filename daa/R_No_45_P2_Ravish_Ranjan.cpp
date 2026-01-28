#include <iostream>
#include "analyzer.cpp"

class Sorting : public Metric {
    public:
        void algo(json& data,std::string key) override{
            for (int i = 1; i< data[key].size(); i++){
                json saved_row;

                for (auto [k, v] : data.items()) saved_row[k] = v[i];

                auto elem = saved_row[key];
                int j = i-1;
                this->assigns++;

                while (j >= 0){
                    this->comps++;
                    if (elem < data[key][j]){
                        assign(data,j,j+1);
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

int main(){
    Sorting s;

    Analyzer analyzer("name,float","websiteName,responseTime",s,"WebsiteResponseTimeSorting");
    analyzer.repetitions = 1;
    analyzer.analyze("responseTime");

    return 0;
}