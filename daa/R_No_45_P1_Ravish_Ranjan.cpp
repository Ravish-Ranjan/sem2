#include "algos/InsertionSort.cpp"
#include "util/command.cpp"
#include "analyzer.cpp"

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