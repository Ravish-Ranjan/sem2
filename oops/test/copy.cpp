#include <iostream>
using namespace std;

class Test{
        int num;
    public:
        Test(){
            num = 100;
        }
        Test(int a){
            num = a;
        }
        Test(Test &obj){
            num = obj.num;
        }
        void show(){
            cout << "Num : " << num << endl;
        }
};

int main(){
    Test obj1(10);
    Test obj2(obj1);
    Test obj3 = obj2;

    Test obj4;
    obj4 = obj1;

    obj1.show();
    obj2.show();
    obj3.show();
    obj4.show();
    return 0;
}