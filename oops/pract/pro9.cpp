#include <iostream>
using namespace std;

class cls_parent{
    public:
        string name;
        void printName(){
            cout << "Name : " << this->name << endl;
        }
};

class cls_child: public cls_parent{
    private:
        int age;
    public:
        cls_child(string n,int a){
            this->name = n;
            this->age = a;   
        }
        int getAge(){
            return this->age;
        }
};

int main(){
    string name;
    int age;
    cout << "Enter name : ";
    cin >> name;
    cout << "Enter age : ";
    cin >> age;

    cls_child obj1(name,age);
    obj1.printName();
    cout << "Age : " << obj1.getAge();
    return 0;
}