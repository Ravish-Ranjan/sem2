#include <iostream>
using namespace std;

int N = 0;

bool isSafe(int** board,int r,int c){
    for (int i = 0; i < c; i++){
        if (board[r][i] == 1)
            return false;
    }
    for (int x = r,y = c; x>=0 && y>=0; x--,y--){
        if (board[x][y] == 1)
            return false;
    }
    for (int x = r,y = c; x<N && y>=0; x++,y--){
        if (board[x][y] == 1)
            return false;
    }
    return true;
}

bool solve8Queens(int** board,int col){
    if (col == N){
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        return true;
    }
    for (int i = 0; i < N; i++){
        if(isSafe(board,i,col)){
            board[i][col] = 1;
            if(solve8Queens(board,col+1))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}

int main(){
    cout << "Enter the size of the chess board(1-8) : ";
    cin >> N;

    if (N > 8 || N < 1){
        cout << "Board size not in range :(" << endl;
        return 0;
    }

    int** board = new int*[N];
    for (int i = 0; i < N; i++) {
        board[i] = new int[N];
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }
    if (!solve8Queens(board, 0)) {
        cout << "No solution found" << endl; 
    }
    for (int i = 0; i < N; i++) {
        delete[] board[i];
    }
    delete[] board;
    return 0;
}