#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Human{
    public:
        string name;
};

class Student:Human{
    public:
        int rollno;
        Student(string name,int roll){
            this->name = name;
            this->rollno = roll;
        }
        void show(){
            cout << "Name : "<< name << " | RollNo. : "<< rollno << endl;
        }
};


int main(){
    Student first("Ravish Ranjan",240484);
    first.show();

    Student*  second = new Student("Ram Singh",240482);
    second->show();

    return 0;
}