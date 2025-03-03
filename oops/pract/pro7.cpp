#include <iostream>
using namespace std;

class cls_rect{
    private:
        int height;
        int width;
    public:
        cls_rect(int h,int w){
            this->height = h;
            this->width = w;
        }
        int area(){
            return this->height*this->width;
        }
};

int main(){
    cls_rect obj1(10,15);
    cout << "Area of rectangle : " << obj1.area();
    return 0;
}