#include <iostream>
using namespace std;

int* expo(int num){
    int* res = new int[2];
    res[0] = num*num;
    res[1] = num*num*num;
    return res;
}

int main(){
    int num;
    cout << "Enter a number : ";
    cin >> num;
    int* res = expo(num);
    cout << "Square of " << num << " is " << res[0] << endl;
    cout << "Cube of " << num << " is " << res[1];
    return 0;
}