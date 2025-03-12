#include <iostream>
using namespace std;

class cls_expo{
    private:
        int num;
    public:
        cls_expo(int n){
            this->num = n;
        }      
        int square(){
            return this->num*this->num;
        }
        int cube(){
            return this->num*this->num*this->num;
        }
};

int main(){
    int num;
    cout << "Enter a number : ";
    cin >> num;
    cls_expo obj(num);
    cout << "Square of " << num << " is " << obj.square() << endl;
    cout << "Cube of " << num << " is " << obj.cube();
    return 0;
}