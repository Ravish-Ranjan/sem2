#include <iostream>
using namespace std;

class cls_second;

class cls_first{
    void show(){
        cout << "This is first class"<< endl;
    }
    friend void fun_friend(cls_first obj1, cls_second obj2);
};

class cls_second{
    void show(){
        cout << "This is second class"<< endl;
    }
    friend void fun_friend(cls_first obj1, cls_second obj2);
};

void fun_friend(cls_first obj1, cls_second obj2){
    obj1.show();
    obj2.show();
}

int main(){
    cls_first obj1;
    cls_second obj2;

    fun_friend(obj1,obj2);

    return 0;
}