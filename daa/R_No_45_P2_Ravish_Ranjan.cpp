#include <iostream>
#include "analyzer.cpp"
#include "algos/InsertionSort.cpp"


int main(){
    InsertionSort s;
    std::cout << "Installing python dependencies (pip venv is required)" << std::endl;
    runCommand("pip install -r requirements.txt");
    std::cout << "Sorting(asc) cars based on thier horsepower" << std::endl;
    std::cout << "Fetching dataset from ucimlrepo dataset-id = 9" << std::endl;
    runCommand("python ./util/fetchDataset.py id:9 filename:cardata savefiletype:json");
    std::cout << "dataset fetched in data folder" << std::endl;

    Analyzer analyzer("","carname,horsepower,weight,cylinders,accelaration",s,"CarHorsePowerSorting");
    analyzer.analyze(2,"util/getcardata.py");

    return 0;
}