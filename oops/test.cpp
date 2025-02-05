#include <iostream>
using namespace std;

namespace first{
    void add();
}

namespace second{
    void sub(int a,int b);
}

namespace third{
    void mul(int a,int b);
}
int main()
{
    int a, b;
    cout << "Enter 1st Number: \n";
    cin >> a;
    cout << "Enter 2nd Number: \n";
    cin >> b;
    first::add(a, b);
    second::sub(a, b);
    third::mul(a, b);
    return 0;
}

void first::add(int a, int b)
{
    cout << "Add = " << a + b;
}

void second::sub(int a, int b)
{
    cout << "Sub = " << a - b;
}

void third::mul(int a, int b)
{
    cout << "Mul = " << a * b;
}