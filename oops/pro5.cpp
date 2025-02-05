#include <iostream>
using namespace std;

int sum(int a,int b){
    return a + b; 
}

int main(){
    int x,y;
    cout << "First number : ";
    cin >> x;
    cout << "Second number : ";
    cin >> y;
    cout << "Sum : " << sum(x,y);
    return 0;
}