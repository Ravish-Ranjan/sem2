#include "analyzer.cpp"
#include "algos/RadixSort.cpp"
#include "graph.cpp"

int main(){
    std::cout << "Installing python dependencies" << std::endl;
    runCommand("pip install -r requirements.txt");
    RadixSort rxs;

    std::cout << "\n\nFirst Questions with Radix Sort" << std::endl;
    // first question
    Analyzer analyzer7("int,firstName","age,name",rxs,"RadixSortOnAge",false,true);
    analyzer7.analyze(0,"RadixSortOnAge","util/genradixdata.py"); // Radix sorting data on age 
    
    // second question
    Analyzer analyzer8("int,firstName","age,name",rxs,"RadixSortOnName",false,true);
    analyzer8.analyze(1,"RadixSortOnName","util/genradixdata.py"); // Radix sorting data on name
    
    // third question (with persmstent data)
    Analyzer analyzer9("int,firstName","age,name",rxs,"RadixSortOnAgeThenName",true,true);
    analyzer9.analyze(0,"RadixSortOnAgeThenName","util/genradixdata.py"); // Radix sorting data first on age
    analyzer9.analyze(1,"RadixSortOnAgeThenName","util/genradixdata.py"); // Radix sorting data then on name

    json data = json::array({
        json::array({"Reeta",18}),
        json::array({"Geeta",17}),
        json::array({"Reeta",18})
    });
    std::cout << "Original Data (Radix Sort)" << std::endl;
    printJson(data);
    rxs.algo(data,0);
    rxs.algo(data,1);
    std::cout << std::endl;
    printJson(data);

    std::cout << "\n\nSecond (a) Questions with Radix Sort" << std::endl;
    std::cout << "Sorting(asc) cars based on thier horsepower" << std::endl;
    std::cout << "Fetching dataset from ucimlrepo dataset-id = 9" << std::endl;
    runCommand("python ./util/fetchDataset.py id:9 filename:cardata savefiletype:json");
    std::cout << "dataset fetched in data folder" << std::endl;
    
    Analyzer analyzer("","carname,horsepower,weight,cylinders,accelaration",rxs,"CarHorsePowerSorting",false,true);
    analyzer.analyze(1,"CarHorsePowerRadixSorting","util/getcardata.py");

    // std::cout << "\n\nResult of First and Second (a) Questions with Quick Sort" << std::endl;
    // Output read("");
    // json r1 = read.getSavedOutput("QuickSortOnAge");
    // json r2 = read.getSavedOutput("QuickSortOnName");
    // json r3 = read.getSavedOutput("QuickSortOnAgeThenName");
    // json r4 = read.getSavedOutput("CarHorsePowerQuickSorting");
    // Graph g("QuickSortOnAge");
    // g.genGraph({r1["comps"],r1["assigns"]},{"comparisions","assignments"});
    
    // g.graphName = "QuickSortOnName";
    // g.genGraph({r2["comps"],r2["assigns"]},{"comparisions","assignments"});
    
    // g.graphName = "QuickSortOnAgeThenName";
    // g.genGraph({r3["comps"],r3["assigns"]},{"comparisions","assignments"});
    
    // g.graphName = "CarHorsePowerQuickSorting";
    // g.genGraph({r4["comps"],r4["assigns"]},{"comparisions","assignments"});

    std::cout << "\n\nSecond (b) Questions with Radix Sort" << std::endl;
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

    rxs.algo(inp.input,columnMap["Perimeter"]);
    std::cout << "\nComparisions (Radix Sort): " << rxs.comps << std::endl;
    std::cout << "Assignments (Radix Sort): " << rxs.assigns << std::endl;

    // Output readOld("");
    // json isData = readOld.getSavedOutput("DryBeanDataQuickSort");
    // std::cout << "Comparisions (Quick Sort): " << isData["comps"][0] << std::endl;
    // std::cout << "Assignments (Quick Sort): " << isData["assigns"][0] << std::endl;

    Output out("DryBeanDataRadixSort");
    out.outputs["data"] = inp.input;
    out.outputs["comps"] = {rxs.comps};
    out.outputs["assigns"] = {rxs.assigns};
    out.saveOutput();
    return 0;
}