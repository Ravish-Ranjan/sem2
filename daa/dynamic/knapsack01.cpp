#include <iostream>
using namespace std;

int n = 0,W = 0 ;

int knapsackRec(int W, int wt[], int val[], int n, int** memo) {
    if (n == 0 || W == 0)
        return 0;

    if (memo[n][W] != -1)
        return memo[n][W];

    int pick = 0;
    if (wt[n-1] <= W)
        pick = val[n-1] + knapsackRec(W-wt[n-1],wt,val,n-1,memo);
    
    int notPick = knapsackRec(W,wt,val,n-1,memo);
    memo[n][W] = max(pick,notPick);
    return max(pick,notPick);
}

int knapsack(int W,int wt[], int val[]){
    int** memo = new int*[n+1];
    for (int i = 0; i <= n; i++) {
        memo[i] = new int[W+1];
        for (int j = 0; j <= W; j++)
            memo[i][j] = -1;
    }
    int res = knapsackRec(W, wt, val, n, memo);
    for (int i = 0; i <= n; i++) {
        delete[] memo[i];
    }
    delete[] memo;
    return res;
}

int main(){
    cout << "Enter the size of the sack : ";
    cin >> W;
    cout << "Enter the no. of nodes : ";
    cin >> n;

    int wt[n],val[n];

    cout << "--------------------" << endl;
    for (int i = 0; i < n; i++){
        cout << "Enter the weight of " << i+1 << "th item : ";
        cin >> wt[i];
        cout << "Enter the prize of " << i+1 << "th item : ";
        cin >> val[i];
        cout << "--------------------" << endl;
    }
    
    int res = knapsack(W,wt,val);
    cout << "Maximum achievable profit : " << res << endl;
    return 0;
}