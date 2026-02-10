#include "analyzer.cpp"
#include "algos/MergeSort.cpp"
#include "algos/InsertionSort.cpp"

int main(){
    std::cout << "Installing python dependencies" << std::endl;
    runCommand("pip install -r requirements.txt");
    MergeSort ms;
    InsertionSort is;

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
    
    // reading old insertion sort run data
    Output read("");
    json r1 = read.getSavedOutput("InsertionSortOnAge");
    json r2 = read.getSavedOutput("InsertionSortOnName");
    json r3 = read.getSavedOutput("InsertionSortOnAgeThenName");
    Graph g1("InsertionSortOnAge");
    Graph g2("InsertionSortOnName");
    Graph g3("InsertionSortOnAgeThenName");
    g1.genGraph(r1["comps"],r1["assigns"]);
    g2.genGraph(r2["comps"],r2["assigns"]);
    g3.genGraph(r3["comps"],r3["assigns"]);

    json data = json::array({
        json::array({"Reeta",18.5}),
        json::array({"Geeta",17.8}),
        json::array({"Reeta",18.3})
    });
    std::cout << "Original Data (Merge Sort)" << std::endl;
    printJson(data);
    ms.algo(data,0);
    ms.algo(data,1);
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

    ms.algo(inp.input,columnMap["Perimeter"]);
    std::cout << "Comparisions (Merge Sort): " << ms.comps << std::endl;
    std::cout << "Assignments (Merge Sort): " << ms.assigns << std::endl;
    
    Output readOld("");
    json isData = readOld.getSavedOutput("DryBeanDataInsertionSort");
    std::cout << "Comparisions (Insertion Sort): " << isData["comps"][0] << std::endl;
    std::cout << "Assignments (Insertion Sort): " << isData["assigns"][0] << std::endl;

    Output out("DryBeanDataMergeSort");
    out.outputs["data"] = inp.input;
    out.outputs["comps"] = {ms.comps};
    out.outputs["assigns"] = {ms.assigns};
    out.saveOutput();
    return 0;
}