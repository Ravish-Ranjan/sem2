#include "ticTacToeLogic.cpp"
#include "strats/stratBFS.cpp"

int main(){
    std::vector<Play> board(9,Play::_);
    printState(board);

    Play player = Play::O;

    while(!gameOver(board)){
        int bestmove = bestMove(board,player);
        board[bestmove] = player;
        std::cout << getVal(player) << " is playing" << std::endl;
        printState(board);
        if (player == Play::O) player = Play::X;
        else player = Play::O;
        PlayerPlaysAs = player;
    }

    if (gameOver(board)) {
        int winner = value(board);
        if (winner == 0) std::cout << "Draw" << std::endl;
        else std::cout << (winner == 1? "Ai wins":"You win") << std::endl;
    }
    return 0;
}