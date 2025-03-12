#include <iostream>
using namespace std;

class first;
class second{
    private:
        int num2;
        friend void fun_friend(first obj1,second obj2);
};
class first{
    private:
        int num1;
        friend void fun_friend(first obj1,second obj2);
};
void fun_friend(first obj1,second obj2){
    obj1.num1 = 10;
    obj2.num2 = 20;
    cout << "First : " << obj1.num1 << endl;
    cout << "Second : " << obj2.num2 << endl;
}

int main(){
    first obj1;
    second obj2;
    fun_friend(obj1,obj2);
    return 0;
}