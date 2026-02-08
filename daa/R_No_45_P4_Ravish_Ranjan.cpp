#include "analyzer.cpp"
#include "algos/MergeSort.cpp"
#include "algos/InsertionSort.cpp"
#include "algos/QuickSort.cpp"

int main(){
    std::cout << "Installing python dependencies" << std::endl;
    runCommand("pip install -r requirements.txt");
    MergeSort ms;
    // InsertionSort is;
    QuickSort qs;

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

    // // first question
    // Analyzer analyzer4("float,firstName","age,name",is,"InsertionSortOnAge");
    // analyzer4.analyze(0); // Insertion sorting data on age 
    
    // // second question
    // Analyzer analyzer5("float,firstName","age,name",is,"InsertionSortOnName");
    // analyzer5.analyze(1); // Insertion sorting data on name
    
    // // third question (with persmstent data)
    // Analyzer analyzer6("float,firstName","age,name",is,"InsertionSortOnAgeThenName",true);
    // analyzer6.analyze(0); // Insertion sorting data first on age
    // analyzer6.analyze(1); // Insertion sorting data then on name

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

    // // given example
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

    // data = json::array({
    //     json::array({"Reeta",18.5}),
    //     json::array({"Geeta",17.8}),
    //     json::array({"Reeta",18.3})
    // });
    // std::cout << "Original Data (Insertion Sort)" << std::endl;
    // printJson(data);
    // is.algo(data,0);
    // is.algo(data,1);
    // std::cout << std::endl;
    // printJson(data);

    data = json::array({
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
    inp.getInput();
    qs.algo(inp.input,columnMap["Perimeter"]);
    // inp.getInput();
    // is.algo(inp.input,columnMap["Perimeter"]);
    std::cout << "Comparisions (Merge Sort): " << ms.comps << std::endl;
    std::cout << "Assignments (Merge Sort): " << ms.assigns << std::endl;
    // std::cout << "\nComparisions (Insertion Sort): " << is.comps << std::endl;
    // std::cout << "Assignments (Insertion Sort): " << is.assigns << std::endl;
    std::cout << "\nComparisions (Quick Sort): " << qs.comps << std::endl;
    std::cout << "Assignments (Quick Sort): " << qs.assigns << std::endl;

    Output out("DryBeanData");
    out.outputs = inp.input;
    out.saveOutput();
    return 0;
}