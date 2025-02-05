#include <iostream>
using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}   

void heapify(int arr[],int size,int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int largest = i;

    if (l<size && arr[l] > arr[largest])
        largest = l;

    if (r<size && arr[r] > arr[largest])
        largest = r;
    
    if (largest != i){
        swap(&arr[i],&arr[largest]);
        heapify(arr,size,largest);
    }
}

void heapsort(int arr[],int size){
    for (int i = (size/2) - 1; i >= 0; i--){
        heapify(arr,size,i);
    }
    for (int i = size-1; i >=0; i--){
        swap(&arr[i],&arr[0]);
        heapify(arr,i,0);
    }    
}

void print(int arr[],int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){
    int size=0;
    cout << "Enter the size of array : ";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++){
        cout << "Arr["<< i <<"] : ";
        cin >> arr[i];
    }
    cout << "\nBefore sorting : ";
    print(arr,size);
    heapsort(arr,size);
    cout << "After sorting : ";
    print(arr,size);
    return 0;
}
