#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Student{
    private:
        string name;
        int rollno;
    public:
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
    return 0;
}