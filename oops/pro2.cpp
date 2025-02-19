#include <iostream>
using namespace std;

int main(){
    int till, sum = 0;
    cout << "Enter the number till you want the sum for : ";
    cin >> till;
    for (int i = 1; i <= till ;i++) sum += i;
    cout << "Sum till number : " << sum << endl;
    return 0;
}