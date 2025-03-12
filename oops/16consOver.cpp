#include <iostream>
using namespace std;

class cls_student{
    private:
        string name;
        int rollno;
    public:
        cls_student(string name,int rollno){
            this->name = name;
            this->rollno = rollno;
        }
        cls_student(int rollno,string name){
            this->name = name;
            this->rollno = rollno;
        }
        void show(){
            cout << "Name : " << this->name << " | Roll No. : " << this->rollno << endl;
        }
};

int main(){
    cls_student stu1("Ravish Ranjan",240484);
    cls_student stu2(240482,"Ram Singh");

    stu1.show();
    stu2.show();
    
    return 0;
}