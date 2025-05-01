#include <iostream>
using namespace std;

void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[],int size){
    for (int  i = 0; i < size-1; i++){
        int min = i;
        for (int j = i+1; j < size; j++){
            if (arr[j] < arr[min])
                min = j;
        }
        swap(&arr[min],&arr[i]);
    }
    
}

void print(int arr[],int size){
    cout << "Array : ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int size=0;
    cout << "Enter the size of array : ";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++){
        cout << "Arr["<< i+1 <<"] : ";
        cin >> arr[i];
    }
    cout << "\nBefore sorting : ";
    print(arr,size);
    selectionSort(arr,size);
    cout << "After sorting : ";
    print(arr,size);
    return 0;
}