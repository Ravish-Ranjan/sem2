#include <iostream>
using namespace std;

class cls_rect{
    private:
        int side;
    public:
        cls_rect(int s){
            this->side = s;
        }
        int area(){
            return this->side*this->side;
        }
};

int main(){
    cls_rect obj1(15);
    cout << "Area of square : " << obj1.area();
    return 0;
}