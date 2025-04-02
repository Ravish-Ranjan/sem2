#include <iostream>
using namespace std;


void showInfo(int age){
    cout << "Age : " << age << endl;
}

void showInfo(string name){
    cout << "Name : " << name << endl;
}

void showInfo(double salary){
    cout << "Salary : " << salary << endl;
}

int main(){
    cout << "This is compile time polymorphism" << endl;
    cout << "---------------------------------" << endl;
    showInfo(21);
    showInfo("Ravish Ranjan");
    showInfo("5467.8");
    return 0;
}