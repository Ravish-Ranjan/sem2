#include <iostream>
using namespace std;

// inline functions are that functions that the processor should be compiled directly for insertion into the code where the function that are used in it called inline function. they are used for small functions and are called frequenlty no reccursion should be done in it

// inline function

inline int summa(int n){
    return n*(n+1)/2;
}

int main(){
    int num;
    cout << "Enter a number : ";
    cin >> num;
    int res = summa(num);
    cout << "Summation : " << res;
    return 0;
}
