#include "analyzer.cpp"
#include "algos/MergeSort.cpp"

int main(){
    std::cout << "Installing python dependencies" << std::endl;
    runCommand("pip install -r requirements.txt");
    MergeSort ms;

    std::cout << "\n\nFirst Questions with Merge Sort" << std::endl;
    // first question
    Analyzer analyzer1("float,firstName","age,name",ms,"InsertionSortOnAge");
    analyzer1.analyze(0,"MergeSortOnAge"); // Merge sorting data on age 
    
    // second question
    Analyzer analyzer2("float,firstName","age,name",ms,"InsertionSortOnName");
    analyzer2.analyze(1,"MergeSortOnName"); // Merge sorting data on name
    
    // third question (with persmstent data)
    Analyzer analyzer3("float,firstName","age,name",ms,"InsertionSortOnAgeThenName",true);
    analyzer3.analyze(0,"MergeSortOnAgeThenName"); // Merge sorting data first on age
    analyzer3.analyze(1,"MergeSortOnAgeThenName"); // Merge sorting data then on name
    
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

    std::cout << "\n\nSecond (a) Questions with Merge Sort" << std::endl;
    std::cout << "Sorting(asc) cars based on thier horsepower" << std::endl;
    std::cout << "Fetching dataset from ucimlrepo dataset-id = 9" << std::endl;
    runCommand("python ./util/fetchDataset.py id:9 filename:cardata savefiletype:json");
    std::cout << "dataset fetched in data folder" << std::endl;
    
    Analyzer analyzer("","carname,horsepower,weight,cylinders,accelaration",ms,"CarHorsePowerSorting");
    analyzer.analyze(2,"CarHorsePowerMergeSorting","util/getcardata.py");
    
    std::cout << "\n\nResult of First and Second (a) Questions with Insertion Sort" << std::endl;
    // reading old insertion sort run data
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
    
    std::cout << "\n\nSecond (b) Questions with Merge Sort" << std::endl;
    
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
    
    std::cout << "\n\nResult of Second (b) Questions with Insertion Sort" << std::endl;
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