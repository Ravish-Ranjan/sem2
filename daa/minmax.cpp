#include <iostream>
using namespace std;

int* minmax(int arr[],int size){
    if (size < 1) {
        cout << "Array should not be empty";
        exit(1);
    }
    int* res = new int[2]{arr[0], arr[0]};
    for (int i = 0; i < size; i++){
        if (arr[i] < res[0]){
            res[0] = arr[i];
        }
        if (arr[i] > res[1]){
            res[1] = arr[i];
        }
    }
    return res;
}

int main(){
    int size = 0;
    cout << "Enter the size of the array : " ;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++){
        cout << "Enter arr[" << i << "] : " ;
        cin >> arr[i];
    }
    int* res = minmax(arr, size);
    cout << "Minimum: " << res[0] << ", Maximum: " << res[1] << endl;
    
    return 0;
}