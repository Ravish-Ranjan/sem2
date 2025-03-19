#include <iostream>
using namespace std;

int min(int a,int b){
    if (a < b) return a;
    return b;
}

int max(int a,int b){
    if (a < b) return b;
    return a;
}

int* minmax(int arr[],int l,int h){
    if (l == h){
        int* res = new int[2]{arr[l],arr[l]};
        return res;
    } else if (h == l+1) {
        int* res = new int[2]{arr[l],arr[h]};
        return res;
    }
    int mid = (l+h)/2;
    int* left = minmax(arr,l,mid);
    int* right = minmax(arr,mid+1,h);
    int* res = new int[2]{min(left[0],right[0]),max(left[1],right[1])};
    return res;
}

int main(){
    int size = 0;
    cout << "Enter the size of the array : ";
    cin >> size;
    int arr[size];
    for(int i=0;i<size;i++){
        cout << "Enter arr[" << i << "] : ";
        cin >> arr[i];
    }
    int* res = minmax(arr,0,size-1);
    cout << "Minimum : " << res[0] << endl;
    cout << "Maximum : " << res[1] << endl;
    return 0;
}