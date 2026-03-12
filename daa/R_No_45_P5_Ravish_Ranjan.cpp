#include "analyzer.cpp"
#include "algos/RandomQuickSort.cpp"
#include "graph.cpp"
#include <chrono>

int main(){
    std::cout << "Installing python dependencies" << std::endl;
    runCommand("pip install -r requirements.txt");
    RandomQuickSort rqs;

    std::cout << "\n\nFirst Questions with Random Quick Sort" << std::endl;
    // first question
    Analyzer analyzer1("float,firstName","age,name",rqs,"SortOnAge",true);
    json ana1 = analyzer1.analyze(0,"RandomQuickSortOnAge"); // RandomQuick sorting data on age 
    
    // second question
    Analyzer analyzer2("float,firstName","age,name",rqs,"SortOnName",true);
    json ana2 = analyzer2.analyze(1,"RandomQuickSortOnName"); // RandomQuick sorting data on name
    
    // third question (with persmstent data)
    Analyzer analyzer3("float,firstName","age,name",rqs,"SortOnAgeThenName",true,true);
    analyzer3.analyze(0,"RandomQuickSortOnAgeThenName"); // RandomQuick sorting data first on age
    json ana3 = analyzer3.analyze(1,"RandomQuickSortOnAgeThenName"); // RandomQuick sorting data then on name

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

    std::cout << "\n\nSecond (a) Questions with Random Quick Sort" << std::endl;
    std::cout << "Sorting(asc) cars based on thier horsepower" << std::endl;
    std::cout << "Fetching dataset from ucimlrepo dataset-id = 9" << std::endl;
    runCommand("python ./util/fetchDataset.py id:9 filename:cardata savefiletype:json");
    std::cout << "dataset fetched in data folder" << std::endl;
    
    Analyzer analyzer("","carname,horsepower,weight,cylinders,accelaration",rqs,"CarHorsePowerSorting",true);
    json ana4 = analyzer.analyze(2,"CarHorsePowerRandomQuickSorting","util/getcardata.py");

    std::cout << "\n\nResult of First and Second (a) Questions with Quick Sort" << std::endl;
    Output read("");
    json r1 = read.getSavedOutput("QuickSortOnAge");
    json r2 = read.getSavedOutput("QuickSortOnName");
    json r3 = read.getSavedOutput("QuickSortOnAgeThenName");
    json r4 = read.getSavedOutput("CarHorsePowerQuickSorting");
    
    Graph g("p5_random_quick_sort_assignments");
    g.genGraph(
        {
            ana1["assigns"],ana2["assigns"],ana3["assigns"],ana4["assigns"],
            r1["assigns"],r2["assigns"],r3["assigns"],r4["assigns"]
        },
        {
            "on_age","on_name","on_age_then_name","p2a_car_hp",
            "quic_on_age","quic_on_name","quic_on_age_then_name","quic_p2a_car_hp"
        }
    );

    g.graphName = "p5_random_quick_sort_comparisions";
    g.genGraph(
        {
            ana1["comps"],ana2["comps"],ana3["comps"],ana4["comps"],
            r1["comps"],r2["comps"],r3["comps"],r4["comps"]
        },
        {
            "on_age","on_name","on_age_then_name","p2a_car_hp",
            "quic_on_age","quic_on_name","quic_on_age_then_name","quic_p2a_car_hp"
        }
    );

    g.graphName = "p5_random_quick_sort_time_microsec";
    g.genGraph(
        {
            ana1["time"],ana2["time"],ana3["time"],ana4["time"],
            r1["c-time"],r2["c-time"],r3["c-time"],r4["c-time"]
        },
        {
            "on_age","on_name","on_age_then_name","p2a_car_hp",
            "quic_on_age","quic_on_name","quic_on_age_then_name","quic_p2a_car_hp"
        }
    );

    std::cout << "\n\nSecond (b) Questions with Random Quick Sort" << std::endl;
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
    rqs.algo(inp.input,columnMap["Perimeter"]);
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,std::micro> dur = stop-start;

    std::cout << "\nComparisions (Random Quick Sort): " << rqs.comps << std::endl;
    std::cout << "Assignments (Random Quick Sort): " << rqs.assigns << std::endl;
    std::cout << "Time (Random Quick Sort)(microsec): " << dur.count() << std::endl;

    Output readOld("");
    json isData = readOld.getSavedOutput("DryBeanDataQuickSort");
    std::cout << "Comparisions (Quick Sort): " << isData["comps"][0] << std::endl;
    std::cout << "Assignments (Quick Sort): " << isData["assigns"][0] << std::endl;
    std::cout << "Time (Quick Sort)(microsec): " << isData["c-time"][0] << std::endl;

    Output out("DryBeanDataRandomQuickSort");
    out.outputs["data"] = inp.input;
    out.outputs["comps"] = {rqs.comps};
    out.outputs["assigns"] = {rqs.assigns};
    out.outputs["c-time"] = {dur.count()};
    out.saveOutput();
    return 0;
}