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
    cout << "---------------------------------" << endl;
    cout << "This is compile time polymorphism" << endl;
    cout << "---------------------------------" << endl;
    showInfo(21);
    showInfo("Ravish Ranjan");
    showInfo("1234.5");
    return 0;
}