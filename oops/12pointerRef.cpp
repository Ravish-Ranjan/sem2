#include <iostream>
using namespace std;

int main(){
    int a;
    cout << "Enter a number : ";
    cin >> a;
    int *p = &a;
    cout << "a  : " << a << endl;
    cout << "&a : " << &a << endl;
    cout << "p  : " << p << endl;
    cout << "*p : " << *p << endl;
    cout << "&p : " << &p << endl;
    return 0;
}