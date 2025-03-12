#include <iostream>
using namespace std;

class Bottle{
    private:
        string color;
        double volume;
    public:
        Bottle(string color,double volume){
            this->color = color;
            this->volume = volume;
        }
        ~Bottle(){
            cout << this->color << " colored bottle with " << this->volume << " ml volume destructed" << endl;

        }
        void show(){
            cout << "Color : " << this->color << "\t Volume : " << this->volume << endl;
        }
};

int main(){
    Bottle b1("red",1000.0);
    b1.show();
    Bottle b2("blue",2000.0);
    b2.show();
    return 0;
}