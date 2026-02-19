#include "algos/InsertionSort.cpp"
#include "util/command.cpp"
#include "analyzer.cpp"

int main(){
    std::cout << "Installing python dependencies" << std::endl;
    runCommand("pip install -r requirements.txt");
    InsertionSort is;

    // first question
    Analyzer analyzer1("float,firstName","age,name",is,"InsertionSortOnAge");
    analyzer1.analyze(0,"InsertionSortOnAge"); // insertion sorting data on age 
    
    // second question
    Analyzer analyzer2("float,firstName","age,name",is,"InsertionSortOnName");
    analyzer2.analyze(1,"InsertionSortOnName"); // insertion sorting data on name
    
    // third question (with persistent data)
    Analyzer analyzer3("float,firstName","age,name",is,"InsertionSortOnAgeThenName",true);
    analyzer3.analyze(0,"InsertionSortOnAgeThenName"); // insertion sorting data first on age
    analyzer3.analyze(1,"InsertionSortOnAgeThenName"); // insertion sorting data then on name

    return 0;
    // // given example
    json data = {
        {"Reeta",18.5},
        {"Geeta",17.8},
        {"Reeta",18.3}
    };
    std::cout << "Original Data" << std::endl;
    printJson(data);
    InsertionSort is2;
    is2.algo(data,0);
    is2.algo(data,1);
    std::cout << std::endl;
    printJson(data);

    return 0;
}