#include <iostream>
using namespace std;

class Parent{
    public:
        virtual void show(){
            cout << "This is the Parent class " << endl;
        }
};

class Child:public Parent{
    public:
        void show() {
            cout << "This is the Child class " << endl;
        }
};

int main(){
    Parent* obj1;
    Child obj2;

    obj1 = &obj2;
    cout << "---------------------------------" << endl;
    cout << "This is run time polymorphism" << endl;
    cout << "---------------------------------" << endl;
    obj1->show();
    obj2.show();

    return 0;
}