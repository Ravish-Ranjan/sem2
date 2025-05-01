#include <iostream>
using namespace std;

int max(int a,int b){
    return (a>b)? a:b;
}

int knapsack(int W,int wt[],int val[],int n){
    if (n == 0 || W == 0)
        return 0;
    
    int pick = 0;
    if (wt[n-1] <= W)
        pick = val[n-1] + knapsack(W-wt[n-1],wt,val,n-1);
    
    int notPick = knapsack(W,wt,val,n-1);
    return max(pick,notPick);
}

int main(){
    int n = 0,W = 0 ;
    cout << "Enter the size of the sack : ";
    cin >> W;
    cout << "Enter the no. of nodes : ";
    cin >> n;
    int wt[n],val[n];
    cout << "------------" << endl;
    for (int i = 0; i < n; i++){
        cout << "Enter the weight of " << i+1 << "th item : ";
        cin >> wt[i];
        cout << "Enter the prize of " << i+1 << "th item : ";
        cin >> val[i];
        cout << "------------" << endl;
    }
    int res = knapsack(W,wt,val,n);
    cout << "Maximum achivable profit : " << res << endl;
    return 0;
}