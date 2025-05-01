#include <iostream>
using namespace std;

template <typename T>

class Student{
    private:
        string name;
        T score;
    public:
        Student(string n,T s):name(n),score(s){};
        T getScore(){
            return score;
        }
        string getName(){
            return name;
        }
};

int main(){
    Student<int> s1("Ravish",90);
    Student<double> s2("Ram",90.0);
    Student<char> s3("Rahul",'A');
    cout << "Name : " << s1.getName() << "\t | Score : " << s1.getScore() << endl;
    cout << "Name : " << s2.getName() << "\t | Score : " << s2.getScore() << endl;
    cout << "Name : " << s3.getName() << "\t | Score : " << s3.getScore() << endl;

    return 0;
}