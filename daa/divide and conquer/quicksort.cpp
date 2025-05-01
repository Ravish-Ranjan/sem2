#include <iostream>
using namespace std;

void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partiton(int arr[],int l,int h){
    int pivoit = arr[h];
    int i = l-1; // for lower elements
    for (int j = l;j <= h-1;j++){  // for current element
        if (arr[j] < pivoit){
            i++;
            swap(&arr[j],&arr[i]);
        }
    }   
    swap(&arr[i+1],&arr[h]);
    return i+1;
}

void quicksort(int arr[],int l,int h){
    if (l < h){
        int p = partiton(arr,l,h);
        quicksort(arr,l,p-1);
        quicksort(arr,p+1,h);
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
    quicksort(arr,0,size-1);
    cout << "After sorting : ";
    print(arr,size);
    return 0;
}