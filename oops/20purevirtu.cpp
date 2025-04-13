#include <iostream>
using namespace std;

class Base{
    public:
        virtual void show()=0;
};

class Deri:public Base{
    public:
        void show(){
            cout << "virtual function" << endl;
        }
};

int main(){
    Base * ptr;
    Deri obj;
    ptr = &obj;
    ptr->show();
    return 0;
}