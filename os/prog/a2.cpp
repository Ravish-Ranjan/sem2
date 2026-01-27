#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>
using namespace std;

void func(int num){
    std::cout << "function run : " << num << std::endl;
}

int main(){
    int number = 6;
    int waitStatus;
    cout << "program start" << endl;
    
    pid_t pid = fork();
    if (pid < 0) {
        cerr << "Fork failed!" << endl;
        return 1;
    } 
    else if (pid == 0) {
        cout << "child :  process started. PID: " << getpid() << endl;
        cout << "child :  running function " << number << "..." << endl;

        func(number);
        
        cout << "child : Task complete. Exiting with status code 10." << endl;
        exit(10); 
    } 
    else {
        cout << "parent : Created child with PID: " << pid << endl;
        cout << "parent : Executing independent tasks..." << endl;

        for (int i = 1; i <= 3; ++i) {
            cout << "parent : working... (" << i << "s)" << endl;
            sleep(1);
        }

        cout << "parent : Work done. Waiting for child to terminate..." << endl;

        wait(&waitStatus);
        if (WIFEXITED(waitStatus)) {
            int exitCode = WEXITSTATUS(waitStatus);
            cout << "parent : Child terminated normally." << endl;
            cout << "parent : Child Exit Status: " << exitCode << endl;
        } else {
            cout << "parent : Child terminated abnormally." << endl;
        }
    }
    return 0;
}