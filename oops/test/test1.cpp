#include <iostream>
using namespace std;

void over(int i){
    cout << "Integer : " << i << endl;
}
void over(float f){
    cout << "Float : " << f << endl;
}
void over(double d){
    cout << "double : " << d << endl;
}
void over(char c){
    cout << "Character : " << c << endl;
}
void over(string s){
    cout << "String : " << s << endl;
}

int main(){
    over(10);
    over(10.0f);
    over(10.0);
    over('a');
    over("abc");
    return 0;
}