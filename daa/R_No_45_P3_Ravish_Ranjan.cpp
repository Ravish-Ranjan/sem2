#include "analyzer.cpp"
#include "algos/MergeSort.cpp"

int main(){
    std::cout << "Installing python dependencies" << std::endl;
    runCommand("pip install -r requirements.txt");
    MergeSort ms;

    // first question
    Analyzer analyzer1("float,firstName","age,name",ms,"MergeSortOnAge");
    analyzer1.analyze(0); // Merge sorting data on age 
    
    // second question
    Analyzer analyzer2("float,firstName","age,name",ms,"MergeSortOnName");
    analyzer2.analyze(1); // Merge sorting data on name
    
    // third question (with persmstent data)
    Analyzer analyzer3("float,firstName","age,name",ms,"MergeSortOnAgeThenName",true);
    analyzer3.analyze(0); // Merge sorting data first on age
    analyzer3.analyze(1); // Merge sorting data then on name

    // // given example
    json data = json::array({
        json::array({"Reeta",18.5}),
        json::array({"Geeta",17.8}),
        json::array({"Reeta",18.3})
    });
    std::cout << "Original Data" << std::endl;
    printJson(data);
    MergeSort ms2;
    ms2.algo(data,0);
    ms2.algo(data,1);
    std::cout << std::endl;
    printJson(data);

    std::cout << "Sorting(asc) dry bean data based on thier perimeter" << std::endl;
    std::cout << "Fetching dataset from ucimlrepo dataset-id = 602" << std::endl;
    runCommand("python ./util/fetchDataset.py id:602 filename:drybean savefiletype:json");
    
    std::unordered_map<std::string,int> columnMap;
    columnMap["Area"] = 0;
    columnMap["Perimeter"] = 1;
    columnMap["MajorAxisLength"] = 2;
    columnMap["MinorAxisLength"] = 3;
    columnMap["AspectRatio"] = 4;


    std::cout << "dataset fetched in data folder" << std::endl;
    std::cout << "estimated time of completion is around 3.5 mins" << std::endl;

    Input inp;
    inp.inputFile = "./data/drybean.json";
    inp.getInput();

    MergeSort ms3;

    ms3.algo(inp.input,columnMap["Perimeter"]);
    std::cout << "Comparisions : " << ms3.comps << std::endl;
    std::cout << "Assignments : " << ms3.assigns << std::endl;

    Output out("DryBeanData");
    out.outputs = inp.input;
    out.saveOutput();
    return 0;
}