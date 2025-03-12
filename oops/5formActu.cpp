#include <iostream>
using namespace std;

int sum(
    /* formal parameters */int a,int b,
    /* default parameters */int c = 10
    ){
    return a + b + c; 
}

int main(){
    int x,y;
    cout << "First number : ";
    cin >> x;
    cout << "Second number : ";
    cin >> y;
    cout << "Sum : " << sum(/* actual parameters */x,y);
    return 0;
}