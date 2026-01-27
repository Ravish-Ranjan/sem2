#include "analyzer.cpp" // analyzer class file import


// Inheriting Metric class and overriding algo method
class InsertionSort : public Metric {
    public:
        void algo(json& data,std::string key) override{
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

int main(){
    std::cout << "Installing python dependencies" << std::endl;
    runCommand("pip install -r requirements.txt");
    InsertionSort is;

    // first question
    Analyzer analyzer1("float,firstName","age,name",is,"InsertionSortOnAge");
    analyzer1.analyze("age"); // insertion sorting data on age 
    
    // second question
    Analyzer analyzer2("float,firstName","age,name",is,"InsertionSortOnName");
    analyzer2.analyze("name"); // insertion sorting data on name
    
    // third question (with persistent data)
    Analyzer analyzer3("float,firstName","age,name",is,"InsertionSortOnAgeThenName",true);
    analyzer3.analyze("age"); // insertion sorting data first on age
    analyzer3.analyze("name"); // insertion sorting data then on name

    // // given example
    json data = {
        {"age",{18.5,17.8,18.3}},
        {"name",{"Reeta","Reeta","Geet"}}
    };
    std::cout << "Original Data" << std::endl;
    printJson(data);
    InsertionSort is2;
    is2.algo(data,"age");
    is2.algo(data,"name");
    std::cout << std::endl;
    printJson(data);

    return 0;
}