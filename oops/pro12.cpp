#include <iostream>
using namespace std;

class cls_first{
    public:
        string first_name;
        void print_firstname(){
            cout << "First name : " << this->first_name << endl;
        }
};
class cls_second{
    public:
        string last_name;
        void print_lastname(){
            cout << "Last name : " << this->last_name << endl;
        }
};

class cls_third:public cls_first,public cls_second{
    public:
        void print_fullname(){
            cout << "Full name : " << this->first_name << " " << this->last_name << endl;
        }
};

int main(){
    cls_third obj1;
    obj1.first_name = "Ravish";
    obj1.last_name = "Ranjan";

    obj1.print_firstname();
    obj1.print_lastname();
    obj1.print_fullname();

    return 0;
}