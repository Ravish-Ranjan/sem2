#include <iostream>
#include "analyzer.cpp"

class Sorting : public Metric {
    public:
        void algo(json& data,const std::string& key) override{
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

    std::cout << "Sorting(asc) dry bean data based on thier perimeter" << std::endl;
    std::cout << "Fetching dataset from ucimlrepo dataset-id = 602" << std::endl;
    runCommand("python ./util/fetchDataset.py id:602 filename:drybean columnscount:5 savefiletype:json");
    
    std::cout << "dataset fetched in data folder" << std::endl;
    std::cout << "estimated time of completion is around 7 mins" << std::endl;

    Input inp;
    inp.inputFile = "./data/drybean.json";
    inp.getInput();

    s.algo(inp.input,"Perimeter");
    std::cout << "Comparisions : " << s.comps << std::endl;
    std::cout << "Assignments : " << s.assigns << std::endl;

    Output out("DryBeanData");
    out.outputs = inp.input;
    out.saveOutput();
    
    return 0;
}