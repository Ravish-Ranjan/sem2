#include <iostream>
using namespace std;

class cls_overload{
    private:
        int height;
        int width;
    public:
        cls_overload(){
            this->height = 0;
            this->width = 0;
        }
        cls_overload(int h,int w){
            this->height = h;
            this->width = w;
        }
        int area(){
            return this->height*this->width;
        }
};

int main(){
    cls_overload obj1;
    cls_overload obj2(10,20);
    cout << "Area of first object : " << obj1.area() << endl;
    cout << "Area of second object : " << obj2.area() << endl;
    return 0;
}