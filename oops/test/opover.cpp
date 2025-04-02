#include <iostream>
using namespace std;

class Bottle{
    private:
        int volume;
        string color;
    public:
        Bottle(double v,string c) : volume(v),color(c){}

        Bottle operator+(const Bottle&vl){
            return Bottle(volume + vl.volume,color);
        }

        Bottle operator-(const Bottle&vl){
            if(volume >= vl.volume){
                return Bottle(volume - vl.volume,color);
            }
            return Bottle(0,color);
        }
        void show(){
            cout << "color : " << color << "\t volume : " << volume << endl;
        }
};

int main() {
    Bottle bt1(1000.0,"Red");
    Bottle bt2(700.0,"Blue");
    Bottle bt3 = bt1 + bt2;
    Bottle bt4 = bt1 - bt2;

    bt3.show();
    bt4.show();
    Bottle bt5 = bt2 - bt1;
    bt5.show();
    return 0;
}