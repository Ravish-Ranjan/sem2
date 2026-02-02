#include "ticTacToeLogic.cpp"
#include "strats/stratMinMax.cpp"

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