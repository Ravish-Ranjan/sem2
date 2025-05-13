#include <iostream>
using namespace std;

int binarySearch(int* arr, int l, int h, int item){
   if (l > h){
        return -1;
    }
    int mid = (l+h)/2;
    if (arr[mid] == item){
        return mid;
    } else if (arr[mid] < item){
        l = mid + 1;
    } else if (arr[mid] > item){
        h = mid - 1;
    }
    return binarySearch(arr,l,h,item);
}

int main(){
    int s = 0,item;
    cout << "Enter the size of the array : ";
    cin >> s;
    int arr[s];
    cout << "Enter the items in sorted format" << endl;
    for (int i = 0; i < s; i++){
        cout << "arr[" << i+1 << "] : ";
        cin >> arr[i];
    }
    cout << "Enter the element you want to search : ";
    cin >> item;

    int res = binarySearch(arr,0,4,10);

    if(res < 0)
        cout << "Item " << item << " not found" << endl;
    else 
        cout << "Item " << item << " found at index : " << res << endl;

    return 0;
}   