#include "analyzer.cpp"
#include "algos/QuickSort.cpp"
#include "graph.cpp"
#include <chrono>

int main(){
    std::cout << "Installing python dependencies" << std::endl;
    runCommand("pip install -r requirements.txt");
    QuickSort qs;

    std::cout << "\n\nFirst Questions with Quick Sort" << std::endl;
    // first question
    Analyzer analyzer1("float,firstName","age,name",qs,"SortOnAge",true);
    json ana1 = analyzer1.analyze(0,"QuickSortOnAge"); // Quick sorting data on age 
    
    // second question
    Analyzer analyzer2("float,firstName","age,name",qs,"SortOnName",true);
    json ana2 = analyzer2.analyze(1,"QuickSortOnName"); // Quick sorting data on name
    
    // third question (with persmstent data)
    Analyzer analyzer3("float,firstName","age,name",qs,"SortOnAgeThenName",true,true);
    analyzer3.analyze(0,"QuickSortOnAgeThenName"); // Quick sorting data first on age
    json ana3 = analyzer3.analyze(1,"QuickSortOnAgeThenName"); // Quick sorting data then on name

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
    
    Analyzer analyzer4("","carname,horsepower,weight,cylinders,accelaration",qs,"CarHorsePowerSorting",true);
    json ana4 = analyzer4.analyze(2,"CarHorsePowerQuickSorting","util/getcardata.py");

    std::cout << "\n\nResult of First and Second (a) Questions with Insertion Sort & Merge Sort" << std::endl;
    Output read("");
    json r1 = read.getSavedOutput("InsertionSortOnAge");
    json r2 = read.getSavedOutput("InsertionSortOnName");
    json r3 = read.getSavedOutput("InsertionSortOnAgeThenName");
    json r4 = read.getSavedOutput("CarHorsePowerSorting");
    json r5 = read.getSavedOutput("MergeSortOnAge");
    json r6 = read.getSavedOutput("MergeSortOnName");
    json r7 = read.getSavedOutput("MergeSortOnAgeThenName");
    json r8 = read.getSavedOutput("CarHorsePowerMergeSorting");

    GraphPlot g("p4_quick_sort_assignments");
    g.genGraph(
        {
            ana1["assigns"],ana2["assigns"],ana3["assigns"],ana4["assigns"],
            r1["assigns"],r2["assigns"],r3["assigns"],r4["assigns"],
            r5["assigns"],r6["assigns"],r7["assigns"],r8["assigns"]
        },
        {
            "on_age","on_name","on_age_then_name","on_p2a_car_hp",
            "ins_on_age","ins_on_name","ins_on_age_then_name","ins_on_p2a_car_hp",
            "mgr_on_age","mgr_on_name","mgr_on_age_then_name","mgr_on_p2a_car_hp",
        }
    );

    g.graphName = "p4_quick_sort_comparisions";
    g.genGraph(
        {
            ana1["comps"],ana2["comps"],ana3["comps"],ana4["comps"],
            r1["comps"],r2["comps"],r3["comps"],r4["comps"],
            r5["comps"],r6["comps"],r7["comps"],r8["comps"]
        },
        {
            "on_age","on_name","on_age_then_name","on_p2a_car_hp",
            "ins_on_age","ins_on_name","ins_on_age_then_name","ins_on_p2a_car_hp",
            "mgr_on_age","mgr_on_name","mgr_on_age_then_name","mgr_on_p2a_car_hp",
        }
    );

    g.graphName = "p4_quick_sort_time_microsec";
    g.genGraph(
        {
            ana1["time"],ana2["time"],ana3["time"],ana4["time"],
            r1["c-time"],r2["c-time"],r3["c-time"],r4["c-time"],
            r5["c-time"],r6["c-time"],r7["c-time"],r8["c-time"]
        },
        {
            "on_age","on_name","on_age_then_name","on_p2a_car_hp",
            "ins_on_age","ins_on_name","ins_on_age_then_name","ins_on_p2a_car_hp",
            "mgr_on_age","mgr_on_name","mgr_on_age_then_name","mgr_on_p2a_car_hp",
        }
    );
    

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

    auto start = std::chrono::high_resolution_clock::now();
    qs.algo(inp.input,columnMap["Perimeter"]);
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,std::micro> dur = stop-start;

    std::cout << "\nComparisions (Quick Sort): " << qs.comps << std::endl;
    std::cout << "Assignments (Quick Sort): " << qs.assigns << std::endl;
    std::cout << "Time (Quick Sort)(microsec): " << dur.count() << std::endl;

    Output readOld("");
    json isData = readOld.getSavedOutput("DryBeanDataInsertionSort");
    std::cout << "Comparisions (Insertion Sort): " << isData["comps"][0] << std::endl;
    std::cout << "Assignments (Insertion Sort): " << isData["assigns"][0] << std::endl;
    std::cout << "Time (Insertion Sort)(microsec): " << isData["c-time"][0] << std::endl;

    isData = readOld.getSavedOutput("DryBeanDataMergeSort");
    std::cout << "Comparisions (Merge Sort): " << isData["comps"][0] << std::endl;
    std::cout << "Assignments (Merge Sort): " << isData["assigns"][0] << std::endl;
    std::cout << "Time (Merge Sort)(microsec): " << isData["c-time"][0] << std::endl;

    Output out("DryBeanDataQuickSort");
    out.outputs["data"] = inp.input;
    out.outputs["comps"] = {qs.comps};
    out.outputs["assigns"] = {qs.assigns};
    out.outputs["c-time"] = {dur.count()};
    out.saveOutput();
    return 0;
}