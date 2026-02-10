#include "analyzer.cpp"
#include "algos/RandomQuickSort.cpp"

int main(){
    std::cout << "Installing python dependencies" << std::endl;
    runCommand("pip install -r requirements.txt");
    RandomQuickSort rqs;

    // first question
    Analyzer analyzer7("float,firstName","age,name",rqs,"RandomQuickSortOnAge");
    analyzer7.analyze(0); // RandomQuick sorting data on age 
    
    // second question
    Analyzer analyzer8("float,firstName","age,name",rqs,"RandomQuickSortOnName");
    analyzer8.analyze(1); // RandomQuick sorting data on name
    
    // third question (with persmstent data)
    Analyzer analyzer9("float,firstName","age,name",rqs,"RandomQuickSortOnAgeThenName",true);
    analyzer9.analyze(0); // RandomQuick sorting data first on age
    analyzer9.analyze(1); // RandomQuick sorting data then on name

    Output read("");
    json r1 = read.getSavedOutput("QuickSortOnAge");
    json r2 = read.getSavedOutput("QuickSortOnName");
    json r3 = read.getSavedOutput("QuickSortOnAgeThenName");
    Graph g1("QuickSortOnAge");
    Graph g2("QuickSortOnName");
    Graph g3("QuickSortOnAgeThenName");
    g1.genGraph(r1["comps"],r1["assigns"]);
    g2.genGraph(r2["comps"],r2["assigns"]);
    g3.genGraph(r3["comps"],r3["assigns"]);

    json data = json::array({
        json::array({"Reeta",18.5}),
        json::array({"Geeta",17.8}),
        json::array({"Reeta",18.3})
    });
    std::cout << "Original Data (Random Quick Sort)" << std::endl;
    printJson(data);
    rqs.algo(data,0);
    rqs.algo(data,1);
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

    rqs.algo(inp.input,columnMap["Perimeter"]);
    std::cout << "\nComparisions (Random Quick Sort): " << rqs.comps << std::endl;
    std::cout << "Assignments (Random Quick Sort): " << rqs.assigns << std::endl;

    Output readOld("");
    json isData = readOld.getSavedOutput("DryBeanDataQuickSort");
    std::cout << "Comparisions (Quick Sort): " << isData["comps"][0] << std::endl;
    std::cout << "Assignments (Quick Sort): " << isData["assigns"][0] << std::endl;

    Output out("DryBeanDataRandomQuickSort");
    out.outputs["data"] = inp.input;
    out.outputs["comps"] = {rqs.comps};
    out.outputs["assigns"] = {rqs.assigns};
    out.saveOutput();
    return 0;
}