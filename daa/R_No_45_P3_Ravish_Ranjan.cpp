#include "analyzer.cpp"
#include "algos/MergeSort.cpp"

int main(){
    MergeSort ms;
    Analyzer analyzer("name,float","name,age",ms,"MergeSortGenData");
    analyzer.analyze("age");
    
    return 0;
}