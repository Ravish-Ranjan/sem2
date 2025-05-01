#include <iostream>
using namespace std;

template <typename M>
M maximum(M a,M b){
    return (a > b)? a:b;
}

template <typename S>
S sum(S only){
    return only;
}
template <typename S, typename... Args>
S sum(S first,Args... args){
    return first + sum(args...);
}

template <typename I>
void print(I arr[],int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << ",";
    }
    cout << endl;
}

int main(){
    int arr1[] = {1,2,3,4,5};
    int size1  = sizeof(arr1) / sizeof(arr1[0]);
    char arr2[] = "ravish";
    int size2  = sizeof(arr2) / sizeof(arr2[0]);

    cout << "First array : ";
    print<int>(arr1,size1);
    cout << "Second array : ";
    print<char>(arr2,size2);

    cout << "Size of first array : " << size1;
    cout << "\nSize of second array : " << size2;
    
    cout << "\nMaximum of both : " << maximum<int>(size1,size2) << endl;

    cout << "Sum of first 5 natural numbers : " << sum<int>(1,2,3,4,5);

    return 0;
}