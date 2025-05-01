#include <iostream>
using namespace std;

class Number{
    private:
        int num;
    public:
        Number(int n): num(n){};
        Number operator-(){ // unary overloading
            return Number(-num);
        }
        Number operator-(const Number&obj){ // binary overloading   
            return Number(this->num - obj.num);
        }
        void print(){
            cout << "Number : " << num << endl;
        }
};

int main(){
    Number n1(10);
    Number n2(25);
    Number n3 = -n1;
    Number n4 = n2 - n1;
    n3.print();
    n4.print();
    return 0;
}