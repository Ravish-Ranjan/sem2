#include "algos/InsertionSort.cpp"
#include "util/command.cpp"
#include "analyzer.cpp"
#include "graph.cpp"

int main(){
    std::cout << "Installing python dependencies" << std::endl;
    runCommand("pip install -r requirements.txt");
    InsertionSort is;

    // first question
    Analyzer analyzer1("float,firstName","age,name",is,"SortOnAge",true);
    json ana1 = analyzer1.analyze(0,"InsertionSortOnAge"); // insertion sorting data on age 
    
    // second question
    Analyzer analyzer2("float,firstName","age,name",is,"SortOnName",true);
    json ana2 = analyzer2.analyze(1,"InsertionSortOnName"); // insertion sorting data on name
    
    // third question (with persistent data)
    Analyzer analyzer3("float,firstName","age,name",is,"SortOnAgeThenName",true,true);
    analyzer3.analyze(0,"InsertionSortOnAgeThenName"); // insertion sorting data first on age
    json ana3 = analyzer3.analyze(1,"InsertionSortOnAgeThenName"); // insertion sorting data then on name

    Graph g("p1_insersion_sort_comparsions");
    g.genGraph(
        {ana1["comps"],ana2["comps"],ana3["comps"]},
        {"on_age","on_name","on_age_then_name"}
    );

    g.graphName = "p1_insersion_sort_assignments";
    g.genGraph(
        {ana1["assigns"],ana2["assigns"],ana3["assigns"]},
        {"on_age","on_name","on_age_then_name"}
    );

    g.graphName = "p1_insersion_sort_time_microsec";
    g.genGraph(
        {ana1["time"],ana2["time"],ana3["time"]},
        {"on_age","on_name","on_age_then_name"}
    );

    // // given example
    json data = json::array({
        json::array({"Reeta",18.5}),
        json::array({"Geeta",17.8}),
        json::array({"Reeta",18.3})
    });
    std::cout << "Original Data" << std::endl;
    printJson(data);
    InsertionSort is2;
    is2.algo(data,0);
    is2.algo(data,1);
    std::cout << std::endl;
    printJson(data);

    return 0;
}