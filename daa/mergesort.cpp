#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int h){
    int n1 = mid - l + 1;
    int n2 = h - mid;
    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];

    for (int i = 0; i < n2; i++)
        right[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2){
        if (left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int l, int h){
    if (l < h){
        int mid = (l + h) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, h);
        merge(arr, l, mid, h);
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
    cout << "Enter the size of array :";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++){
        cout << "Arr["<< i+1 <<"] : ";
        cin >> arr[i];
    }
    cout << "\nBefore sorting : ";
    print(arr,size);
    mergesort(arr,0,size-1);
    cout << "After sorting : ";
    print(arr,size);
    return 0;
}