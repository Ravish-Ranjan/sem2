#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
using namespace std;

atomic<int> s = 3;
int score = 10;

void criticalSection(int& score){
    int scr = score;
    this_thread::sleep_for(chrono::seconds(3));
    scr = scr+3;
    score = scr;
}

void wait(){
    while(s<=0);
    s--;
}

void signal(){
    s++;
}

void semaphoreSolution(int id){
    int times_run = 3;

    while(times_run > 0){
        // entry section
        wait();
        // critical section
        cout << "Process P" << id << " enters critical section" << endl;

        criticalSection(score);
        cout << "P" << id << " score : " << score << endl;

        cout << "Process P" << id << " exits critical section" << endl;
        // exit section
        signal();
        // remainder section
        times_run--;
    }
}

int main(){
    thread t1(semaphoreSolution,1);
    thread t2(semaphoreSolution,2);
    thread t3(semaphoreSolution,3);
    thread t4(semaphoreSolution,4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    cout << "Final Score : " << score << endl;

    return 0;
}