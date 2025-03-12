#include <iostream>
using namespace std;

int volume(int height,int width,int breadth){
    return height * width * breadth;
}

int volume(int side){
    return side * side * side;
}

double volume(double radius){
    return (4*(3.1415)*radius*radius*radius) / 3;
}

int main(){
    cout << "Volume of cuboid : " << volume(10,20,30) << endl;
    cout << "Volume of cube : " << volume(20) << endl;
    cout << "Volume of sphere : " << volume(10.0) << endl;
}