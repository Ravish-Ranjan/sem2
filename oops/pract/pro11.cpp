#include <iostream>
using namespace std;

class cls_first{
    public:
        void fun_first(){
            cout << "First class" << endl;
        }
};
class cls_second:public cls_first{
    public:
        void fun_second(){
            cout << "Second class" << endl;
        }
};
class cls_third:public cls_second{
    public:
        void fun_third(){
            cout << "Third class" << endl;
        }
};
int main(){
    cls_first obj1;
    cls_second obj2;
    cls_third obj3;

    obj1.fun_first();

    obj2.fun_first();
    obj2.fun_second();

    obj3.fun_first();
    obj3.fun_second();
    obj3.fun_third();

    return 0;
    
}