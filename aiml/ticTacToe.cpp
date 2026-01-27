#include <iostream>
#include <vector>
#include <limits>

enum Play {X,O,_};

int value(const std::vector<Play>& state){
    if (
        (state[0] == Play::O && state[1] == Play::O && state[2] == Play::O) || 
        (state[3] == Play::O && state[4] == Play::O && state[5] == Play::O) || 
        (state[6] == Play::O && state[7] == Play::O && state[8] == Play::O) || 

        (state[0] == Play::O && state[3] == Play::O && state[6] == Play::O) || 
        (state[1] == Play::O && state[4] == Play::O && state[7] == Play::O) || 
        (state[2] == Play::O && state[5] == Play::O && state[8] == Play::O) || 
        
        (state[0] == Play::O && state[4] == Play::O && state[8] == Play::O) || 
        (state[2] == Play::O && state[4] == Play::O && state[6] == Play::O) 
    ) return 1;
    if (
        (state[0] == Play::X && state[1] == Play::X && state[2] == Play::X) || 
        (state[3] == Play::X && state[4] == Play::X && state[5] == Play::X) || 
        (state[6] == Play::X && state[7] == Play::X && state[8] == Play::X) || 

        (state[0] == Play::X && state[3] == Play::X && state[6] == Play::X) || 
        (state[1] == Play::X && state[4] == Play::X && state[7] == Play::X) || 
        (state[2] == Play::X && state[5] == Play::X && state[8] == Play::X) || 
        
        (state[0] == Play::X && state[4] == Play::X && state[8] == Play::X) || 
        (state[2] == Play::X && state[4] == Play::X && state[6] == Play::X) 
    ) return -1;
    return 0;
}

char getVal(Play p){
    if (p == Play::O) return 'O';
    if (p == Play::X) return 'X';
    return ' ';
}

bool isFull(const std::vector<Play>& state){
    for (Play elem:state){
        if (elem == Play::_) return false;
    }
    return true;
}

void printState(const std::vector<Play>& s){
    std::cout << "------------" << std::endl;
    std::cout << getVal(s[0]) << "|" << getVal(s[1]) << "|" << getVal(s[2]) << std::endl;
    std::cout << getVal(s[3]) << "|" << getVal(s[4]) << "|" << getVal(s[5]) << std::endl;
    std::cout << getVal(s[6]) << "|" << getVal(s[7]) << "|" << getVal(s[8]) << std::endl;
    std::cout << "------------" << std::endl;
    // for (Play elem:s){
    //     std::cout << getVal(elem) << " ";
    // }
    // std::cout << std::endl;
}

int bestValue(std::vector<Play>& state,bool maxPlays){
    int score = value(state);
    if (score != 0) return score;
    if (isFull(state)) return 0;

    if (maxPlays){
        int maxVal = std::numeric_limits<int>::min();
        for (int i=0; i<9; i++) {
            if (state[i] == Play::_){
                state[i] = Play::O;
                maxVal = std::max(maxVal , bestValue(state,false));
                state[i] = Play::_;
            }
        }
        return maxVal;
    } else {
        int minVal = std::numeric_limits<int>::max();
        for (int i=0; i<9; i++) {
            if (state[i] == Play::_){
                state[i] = Play::X;
                minVal = std::min(minVal , bestValue(state,true));
                state[i] = Play::_;
            }
        }
        return minVal;
    }
}

int bestMove(std::vector<Play>& state,Play AiPlays){
    int bestVal = -10000;
    int bestMove = -1;

    for(int i=0; i<9; i++){
        if (state[i] == Play::_){
            state[i] = AiPlays;
            int moveVal = bestValue(state,AiPlays == Play::X);
            state[i] = Play::_;
            if (moveVal > bestVal){
                bestMove = i;
                bestVal = moveVal;
            }
        }
    }
    return bestMove;
}

bool gameOver(const std::vector<Play>& state){
    if (value(state) != 0) return true;
    if (isFull(state)) return true;
    return false;
}

int main(){
    std::vector<Play> board(9,Play::_);
    std::cout << "You play first (X)" << std::endl;
    printState(board);
    int place = 1;

    do{
        std::cout << "Enter playing position : ";
        std::cin >> place;
        if (board[place-1] != Play::_){
            std::cout << "Can't play their, already filled" << std::endl;
            continue; 
        }
        board[place-1] = Play::X;
        printState(board);
        int bestmov = bestMove(board,Play::O);
        if (bestmov <0) break;
        board[bestmov] = Play::O;
        printState(board);
    }while(!gameOver(board));

    if (gameOver(board)) {
        int winner = value(board);
        if (winner == 0) std::cout << "Draw" << std::endl;
        else std::cout << (winner == 1? "Ai wins":"You win") << std::endl;
    }

    return 0;
}