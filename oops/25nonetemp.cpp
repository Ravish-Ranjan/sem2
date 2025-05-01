#include <iostream>
using namespace std;

template <typename S, int size>
class Score{
    private:
        S arr[size];
    public:
        Score(S scores[]) {
            for (int i = 0; i < size; i++) {
                arr[i] = scores[i];
            }
        }
        void show(){
            for (int i = 0; i < size; i++){
                cout << arr[i] << " ,";
            }
            cout << endl;
        }
};

int main(){
    int s1[] = {90,91,92,93,94};
    double s2[] = {90.1,90.2,90.3,90.4,90.5,90.6};
    char s3[] = {'A','B','C','A'};

    Score<int,5> S1(s1);
    Score<double,6> S2(s2);
    Score<char,4> S3(s3);
    
    cout << "First array : ";
    S1.show();
    cout << "Second array : ";
    S2.show();
    cout << "Third array : ";
    S3.show();
    return 0;
}