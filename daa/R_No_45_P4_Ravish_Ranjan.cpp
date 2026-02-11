#include "analyzer.cpp"
#include "algos/QuickSort.cpp"

int main(){
    std::cout << "Installing python dependencies" << std::endl;
    runCommand("pip install -r requirements.txt");
    QuickSort qs;

    std::cout << "\n\nFirst Questions with Quick Sort" << std::endl;
    // first question
    Analyzer analyzer7("float,firstName","age,name",qs,"QuickSortOnAge");
    analyzer7.analyze(0); // Quick sorting data on age 
    
    // second question
    Analyzer analyzer8("float,firstName","age,name",qs,"QuickSortOnName");
    analyzer8.analyze(1); // Quick sorting data on name
    
    // third question (with persmstent data)
    Analyzer analyzer9("float,firstName","age,name",qs,"QuickSortOnAgeThenName",true);
    analyzer9.analyze(0); // Quick sorting data first on age
    analyzer9.analyze(1); // Quick sorting data then on name

    json data = json::array({
        json::array({"Reeta",18.5}),
        json::array({"Geeta",17.8}),
        json::array({"Reeta",18.3})
    });
    std::cout << "Original Data (Quick Sort)" << std::endl;
    printJson(data);
    qs.algo(data,0);
    qs.algo(data,1);
    std::cout << std::endl;
    printJson(data);

    std::cout << "\n\nSecond (a) Questions with Quick Sort" << std::endl;
    std::cout << "Sorting(asc) cars based on thier horsepower" << std::endl;
    std::cout << "Fetching dataset from ucimlrepo dataset-id = 9" << std::endl;
    runCommand("python ./util/fetchDataset.py id:9 filename:cardata savefiletype:json");
    std::cout << "dataset fetched in data folder" << std::endl;
    
    Analyzer analyzer("","carname,horsepower,weight,cylinders,accelaration",qs,"CarHorsePowerQuickSorting");
    analyzer.analyze(2,"util/getcardata.py");

    std::cout << "\n\nResult of First and Second (a) Questions with Insertion Sort & Merge Sort" << std::endl;
    Output read("");
    json r1 = read.getSavedOutput("InsertionSortOnAge");
    json r2 = read.getSavedOutput("InsertionSortOnName");
    json r3 = read.getSavedOutput("InsertionSortOnAgeThenName");
    json r4 = read.getSavedOutput("CarHorsePowerSorting");
    Graph g1("InsertionSortOnAge");
    Graph g2("InsertionSortOnName");
    Graph g3("InsertionSortOnAgeThenName");
    Graph g4("CarHorsePowerSorting");
    g1.genGraph(r1["comps"],r1["assigns"]);
    g2.genGraph(r2["comps"],r2["assigns"]);
    g3.genGraph(r3["comps"],r3["assigns"]);
    g4.genGraph(r4["comps"],r4["assigns"]);

    r1 = read.getSavedOutput("MergeSortOnAge");
    r2 = read.getSavedOutput("MergeSortOnName");
    r3 = read.getSavedOutput("MergeSortOnAgeThenName");
    r4 = read.getSavedOutput("CarHorsePowerMergeSorting");
    Graph g5("MergeSortOnAge");
    Graph g6("MergeSortOnName");
    Graph g7("MergeSortOnAgeThenName");
    Graph g8("CarHorsePowerMergeSorting");
    g5.genGraph(r1["comps"],r1["assigns"]);
    g6.genGraph(r2["comps"],r2["assigns"]);
    g7.genGraph(r3["comps"],r3["assigns"]);
    g8.genGraph(r4["comps"],r4["assigns"]);

    std::cout << "\n\nSecond (b) Questions with Quick Sort" << std::endl;
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

    qs.algo(inp.input,columnMap["Perimeter"]);
    std::cout << "\nComparisions (Quick Sort): " << qs.comps << std::endl;
    std::cout << "Assignments (Quick Sort): " << qs.assigns << std::endl;

    Output readOld("");
    json isData = readOld.getSavedOutput("DryBeanDataInsertionSort");
    std::cout << "Comparisions (Insertion Sort): " << isData["comps"][0] << std::endl;
    std::cout << "Assignments (Insertion Sort): " << isData["assigns"][0] << std::endl;

    isData = readOld.getSavedOutput("DryBeanDataMergeSort");
    std::cout << "Comparisions (Merge Sort): " << isData["comps"][0] << std::endl;
    std::cout << "Assignments (Merge Sort): " << isData["assigns"][0] << std::endl;

    Output out("DryBeanDataQuickSort");
    out.outputs["data"] = inp.input;
    out.outputs["comps"] = {qs.comps};
    out.outputs["assigns"] = {qs.assigns};
    out.saveOutput();
    return 0;
}