#include <iostream>
using namespace std;

namespace Hispace{
    void show(){
        cout << "Hi" << endl;
    }
} 

namespace Hellospace{
    void show() {
        cout << "Hello" << endl;
    }
} 

int main(){
    cout << "Hispace show() : ";
    Hispace::show();
    cout << "Hellospace show() : ";
    Hellospace::show();
}