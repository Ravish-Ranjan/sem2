#include <iostream>
using namespace std;

double divide(int a,int b){
    if (b == 0){
        throw std::runtime_error("Can't divide by zero");
    } 
    return static_cast<double>(a)/b;
}

int main(){
    int n1 = 0,n2 = 0;
    cout << "Enter first number : ";
    cin >> n1;
    cout << "Enter second number : ";
    cin >> n2;
    try {
        double res = divide(n1,n2);
        cout << "first number / second number = " << res << endl;
    }
    catch(const std::exception& e){
        std::cerr << "Error occured : " << e.what() << '\n';
    }
    
    return 0;
}