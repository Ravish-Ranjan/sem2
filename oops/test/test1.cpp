#include <iostream>
using namespace std;

int calc(int a=10){
    return 10; 
}

int calc(float a){
    return 11;
}

int main(){
    cout << calc() << endl;
    return 0;
}