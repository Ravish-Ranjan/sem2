#include "runner.cpp"
#include <iostream>
#include <string>

template <typename T>
void bubbleSort(std::vector<T>& arr){
    for (int i = 0; i < arr.size() -1; i++){
        for (int j = 0; j < arr.size() - i -1; j++){
            if (arr[j] > arr[j+1]){
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

template <typename T>
void insertionSort(std::vector<T>& arr){
    for (int i = 1; i< arr.size(); i++){
        T key = arr[i];
        int j = i-1;
        while (key < arr[j] && j >= 0){
            arr[j+1] = arr[j];
            j-=1;
        }
        arr[j+1] = key;
    }
}

int main(){
    std::vector<double> res = analyzer<std::string>("name",insertionSort<std::string>,"InsertionSort");

    std::cout << "Avg. Time (age1) : ";
    for(double time:res){
        std::cout << time << ",";
    }
    std::cout << std::endl;

    return 0;
}