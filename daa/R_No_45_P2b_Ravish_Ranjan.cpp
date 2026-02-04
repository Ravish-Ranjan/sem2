#include <iostream>
#include "analyzer.cpp"
#include "algos/InsertionSort.cpp"

int main(){
    InsertionSort s;
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
    return 0;
    s.algo(inp.input,2);
    std::cout << "Comparisions : " << s.comps << std::endl;
    std::cout << "Assignments : " << s.assigns << std::endl;

    Output out("DryBeanData");
    out.outputs = inp.input;
    out.saveOutput();
    
    return 0;
}