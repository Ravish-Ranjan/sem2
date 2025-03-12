#include <iostream>
using namespace std;

class cls_student{
    private:
        string name;
        int rollno;
    public:
        cls_student(string name,int roll){
            this->name = name;
            this->rollno = roll;
        }
        void fun_show(){
            cout << "Name : "<< name << " | RollNo. : "<< rollno << endl;
        }
};


int main(){
    cls_student first("Ravish Ranjan",240484);
    first.fun_show();
    return 0;
}