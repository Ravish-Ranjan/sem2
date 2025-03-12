#include <iostream>
using namespace std;

class cls_default{
    private:
        int num;
    public:
        cls_default(){
            this->num = 0;
        }
        cls_default(int num){
            this->num = num;
        }
        int get(){
            return this->num;
        }
};

int main(){
    int num;
    cout << "Enter a number : ";
    cin >> num;

    cls_default obj1;
    cls_default obj2(num);

    cout << "Number of default constructed object : " << obj1.get() << endl;
    cout << "Number of user given object : " << obj2.get() << endl;

    return 0;
}