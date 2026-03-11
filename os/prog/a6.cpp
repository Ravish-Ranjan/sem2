#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

enum Process {P1,P2};
atomic<bool> flag[2];
atomic<int> turn;
int score = 0;

void firstCriticalSection(){
    int s = score;
    s += 10;
    score = s;
}

void secondCriticalSection(){
    int s = score;
    s -= 3;
    score = s;
}

void petersonSolution(int id){
    int count = 0;
    int otherId = id == 0?1:0;
    do{
        // entry section
        flag[id].store(true);
        turn.store(otherId);

        while(flag[otherId] && turn == otherId);

        // critical section
        cout << (id == 0? "P1":"P2") << " : enters critical section";
        if (id == 0)
        firstCriticalSection();
        else
        secondCriticalSection();
        
        cout << " | score is " << score;
        
        // exit section
        cout << " | exits critical section" << endl;
        flag[id] = false;
        count++;
    } while (count < 5);
    
}

int main(){
    cout << "Program Started" << endl;
    cout << "Initially Score : " << score << endl;
    flag[0] = false;
    flag[1] = false;
    turn = P1;

    thread t1(petersonSolution,0);
    thread t2(petersonSolution,1);

    t1.join();
    t2.join();

    cout << "\nFinal Score : " << score << endl;

    return 0;
}