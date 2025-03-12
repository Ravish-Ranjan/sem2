#include <iostream>
using namespace std;

class cls_first{
    public:
        void print_first(){
            cout << "first object" << endl;
        }
};
class cls_second:public cls_first{
    public:
        void print_second(){
            cout << "second object" << endl;
        }
};
class cls_third:public cls_second{
    public:
        void print_third(){
            cout << "third object" << endl;
        }
};

int main(){
    cls_first obj1;
    cls_second obj2;
    cls_third obj3;
    
    // first object
    cout << "---From first object" << endl;
    obj1.print_first();
    // second object
    cout << "\n---From second object" << endl;
    obj2.print_first();
    obj2.print_second();
    // third object
    cout << "\n---From third object" << endl;
    obj3.print_first();
    obj3.print_second();
    obj3.print_third();

    return 0;
}