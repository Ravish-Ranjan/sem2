#include "analyzer.cpp"
#include "graph.cpp"
#include "algos/RadixSort.cpp"

int main(){
    std::cout << "Installing python dependencies" << std::endl;
    runCommand("pip install -r requirements.txt");
    RadixSort rxs;

    std::cout << "\n\nFirst Questions with Radix Sort" << std::endl;
    // first question
    Analyzer analyzer1("int,firstName","age,name",rxs,"RadixSortOnAge",true);
    json ana1 = analyzer1.analyze(0,"RadixSortOnAge","util/genradixdata.py"); // Radix sorting data on age 
    
    // second question
    Analyzer analyzer2("int,firstName","age,name",rxs,"RadixSortOnName",true);
    json ana2 = analyzer2.analyze(1,"RadixSortOnName","util/genradixdata.py"); // Radix sorting data on name
    
    // third question (with persmstent data)
    Analyzer analyzer3("int,firstName","age,name",rxs,"RadixSortOnAgeThenName",true,true);
    analyzer3.analyze(0,"RadixSortOnAgeThenName","util/genradixdata.py"); // Radix sorting data first on age
    json ana3 = analyzer3.analyze(1,"RadixSortOnAgeThenName","util/genradixdata.py"); // Radix sorting data then on name


    std::cout << "\n\nResult of First Questions with all previous" << std::endl;
    Output read("");
    json r1 = read.getSavedOutput("InsertionSortOnAge");
    json r2 = read.getSavedOutput("InsertionSortOnName");
    json r3 = read.getSavedOutput("InsertionSortOnAgeThenName");
    
    json r4 = read.getSavedOutput("MergeSortOnAge");
    json r5 = read.getSavedOutput("MergeSortOnName");
    json r6 = read.getSavedOutput("MergeSortOnAgeThenName");
    
    json r7 = read.getSavedOutput("QuickSortOnAge");
    json r8 = read.getSavedOutput("QuickSortOnName");
    json r9 = read.getSavedOutput("QuickSortOnAgeThenName");
    
    json r10 = read.getSavedOutput("RandomQuickSortOnAge");
    json r11 = read.getSavedOutput("RandomQuickSortOnName");
    json r12 = read.getSavedOutput("RandomQuickSortOnAgeThenName");
    
    Graph g("p6_radix_sort_assignments_on_age");
 
    // g.genGraph(
    //     {ana1["assigns"],r1["assigns"],r4["assigns"],r7["assigns"],r10["assigns"]},
    //     {"on_age","ins_on_age","mrg_on_age","quic_on_age","rand_quic_on_age"}
    // );
    
    // g.graphName = "p6_radix_sort_assignments_on_name";
    // g.genGraph(
    //     {ana2["assigns"],r2["assigns"],r5["assigns"],r8["assigns"],r11["assigns"]},
    //     {"on_name","ins_on_name","mrg_on_name","quic_on_name","rand_quic_on_name"}
    // );

    // g.graphName = "p6_radix_sort_assignments_on_age_then_name";
    // g.genGraph(
    //     {ana3["assigns"],r3["assigns"],r6["assigns"],r9["assigns"],r12["assigns"]},
    //     {"on_age_then_name","ins_on_age_then_name","mrg_on_age_then_name","quic_on_age_then_name","rand_quic_on_age_then_name"}
    // );
    
    // // ----------------------------------------------------------------------------
    // g.graphName = "p6_radix_sort_comparisions_on_age";
    // g.genGraph(
    //     {ana1["comps"],r1["comps"],r4["comps"],r7["comps"],r10["comps"]},
    //     {"on_age","ins_on_age","mrg_on_age","quic_on_age","rand_quic_on_age"}
    // );
    
    // g.graphName = "p6_radix_sort_comparisions_on_name";
    // g.genGraph(
    //     {ana2["comps"],r2["comps"],r5["comps"],r8["comps"],r11["comps"]},
    //     {"on_name","ins_on_name","mrg_on_name","quic_on_name","rand_quic_on_name"}
    // );

    // g.graphName = "p6_radix_sort_comparisions_on_age_then_name";
    // g.genGraph(
    //     {ana3["comps"],r3["comps"],r6["comps"],r9["comps"],r12["comps"]},
    //     {"on_age_then_name","ins_on_age_then_name","mrg_on_age_then_name","quic_on_age_then_name","rand_quic_on_age_then_name"}
    // );
    
    // ----------------------------------------------------------------------------
    g.graphName = "p6_radix_sort_time_microsec_on_age";
    g.genGraph(
        {ana1["time"],r1["c-time"],r4["c-time"],r7["c-time"],r10["c-time"]},
        {"on_age","ins_on_age","mrg_on_age","quic_on_age","rand_quic_on_age"}
    );
    
    g.graphName = "p6_radix_sort_time_microsec_on_name";
    g.genGraph(
        {ana2["time"],r2["c-time"],r5["c-time"],r8["c-time"],r11["c-time"]},
        {"on_name","ins_on_name","mrg_on_name","quic_on_name","rand_quic_on_name"}
    );

    g.graphName = "p6_radix_sort_time_microsec_on_age_then_name";
    g.genGraph(
        {ana3["time"],r3["c-time"],r6["c-time"],r9["c-time"],r12["c-time"]},
        {"on_age_then_name","ins_on_age_then_name","mrg_on_age_then_name","quic_on_age_then_name","rand_quic_on_age_then_name"}
    );

    
    
    return 0;
}