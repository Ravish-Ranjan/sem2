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

int main(){
    Sorting s;
    std::cout << "Installing python dependencies (pip venv is required)" << std::endl;
    runCommand("pip install -r requirements.txt");
    std::cout << "Sorting(asc) cars based on thier horsepower" << std::endl;
    std::cout << "Fetching dataset from ucimlrepo dataset-id = 9" << std::endl;
    runCommand("python ./util/fetchcardata.py");
    std::cout << "dataset fetched in data folder" << std::endl;

    Analyzer analyzer("","carname,horsepower",s,"CarHorsePowerSorting");
    analyzer.analyze("horsepower","util/getcardata.py");

    return 0;
}