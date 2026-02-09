#include <iostream>

class Jug{
    public:
        int capacity;
        int water = 0;
        
        Jug(int capacity):capacity(capacity){}
        
        void empty(){
            this->water = 0;
        }
        
        void fill(){
            this->water = this->capacity;
        }

        bool isFull(){
            return this->water == this->capacity;
        } 

        bool isEmpty(){
            return this->water == 0;
        }

        void transfer(Jug &otherJug){
            int leftCap = otherJug.capacity - otherJug.water;
            if (leftCap >= this->water){
                otherJug.water += this->water;
                this->water = 0;
            } else {
                otherJug.water = otherJug.capacity;
                this->water -= leftCap;
            }
        }
};

int gcd(int a,int b){
    if (a > b) return gcd(a-b,b);
    else if (b > a) return gcd(a,b-a);
    return a;
}

void solveWaterJug(int F,int S,int T){
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

    Jug x(F),y(S);

    while (x.water != T && y.water != T){
        if (x.water == 0){
            x.fill();
            std::cout << "Filling first : (" << x.water << "|" << y.water << ")\n";
        } else {
            if (y.isFull()){
                y.empty();
                std::cout << "Empting second : (" << x.water << "|" << y.water << ")\n";
            }
            else{ 
                x.transfer(y);
                std::cout << "Transfering form first to second : (" << x.water << "|" << y.water << ")\n";
            }
        }
    }
    if (x.water == T || y.water == T){
        std::cout << "Target reached : " << (x.water == T? "first":"second") << " jug have " << T << " quantity water" << std::endl;
    }

}

int main(){
    solveWaterJug(10,9,2);
    return 0;
}