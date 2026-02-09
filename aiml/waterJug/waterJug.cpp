#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <stdlib.h>

int gcd(int a,int b){
    if (a > b) return gcd(a-b,b);
    else if (b > a) return gcd(a,b-a);
    return a;
}

int min(int a,int b){
    if (a <= b) return a;
    return b;
}

void printState(std::vector<int> s){
    std::cout << "(" << s[2] << "|" << s[3] << ") -> (" << s[0] << "|" << s[1] << ")" << std::endl;
}

void solveWaterJugProblem(int F,int S,int T){
    if (F <= 0 || S <= 0){
        std::cout << "jugs should have some capacity" << std::endl;
        return;
    }
    if (T > F && T > S){
        std::cout << "T should be atleast be keepable in either jug" << std::endl;
        return;
    }
    if (T%gcd(F,S) != 0){
        std::cout << "no solution exists" << std::endl;
        return;
    }

    if (F < S){
        std::cout << "swapping jugs to keep big one first" << std::endl;
        F = F ^ S;
        S = F ^ S;
        F = F ^ S;
    };
    std::cout << "First jug cap : " << F << " | second jug cap : " << S << std::endl;

    std::set<std::vector<int>> visited;
    std::deque<std::vector<int>> dq;
    dq.push_back({0,0});

    while(!dq.empty()){
        std::vector<int> s = dq.front();
        dq.pop_front();
        
        if (s[0] == T || s[1] == T){
            printState(s);
            std::cout << (s[0] == T? "first":"second") << " jug have target " << T << " unit water" << std::endl;
            return;
        }

        if (visited.find({s[0],s[1]}) != visited.end()) continue;
        visited.insert({s[0],s[1]});
        printState(s);
        

        if (F != s[0]){
            dq.push_back({F,s[1],s[0],s[1]});
        }

        if (s[1] != 0) {
            dq.push_back({s[0],0,s[0],s[1]});
        }
        
        int FtoS = min(s[0],S - s[1]);
        if (FtoS != 0){
            dq.push_back({s[0] - FtoS,s[1] + FtoS,s[0],s[1]});
        }
    }
    std::cout << "no Solution found" << std::endl;
}

int main(int argc,char* argv[]){
    if (argc < 4 ){
        std::cout << "Not enough arguments\n\n\tUsage : ./waterJug <jug1 capacity> <jug2 capacity> <target capacity>" << std::endl;
        return 1;
    }
    solveWaterJugProblem(std::atoi(argv[1]),std::atoi(argv[2]),std::atoi(argv[3]));
    return 0;
}