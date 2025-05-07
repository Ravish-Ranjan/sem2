#include <iostream>
using namespace std;

void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int* deadline,int* profit,int c){
    for (int i = 0; i < c; i++){
        for (int j = 0; j < c-i-1; j++){
            if (profit[j] < profit[j+1]){
                swap(&profit[j],&profit[j+1]);
                swap(&deadline[j],&deadline[j+1]);
            }
        }
    }
}

int* jobSeq(int* deadline, int* profit, int j) {
    int count = 0, totalProfit = 0;
    sort(deadline, profit, j);

    int* slot = new int[j];
    for (int i = 0; i < j; i++)
        slot[i] = 0;

    for (int i = 0; i < j; i++) {
        int start = min(j, deadline[i]) - 1;
        for (int k = start; k >= 0; k--) {
            if (slot[k] == 0) {
                slot[k] = 1;
                count++;
                totalProfit += profit[i];
                break;
            }
        }
    }

    int* res = new int[2]{count, totalProfit};
    delete[] slot;
    return res;
}

int main(){
    int j = 0;
    cout << "Enter the no. of jobs : ";
    cin >> j;
    int deadline[j],profit[j];

    for (int i = 0; i < j; i++){
        cout << "Enter the deadline of " << i+1 << "th job : ";
        cin >> deadline[i];
        cout << "Enter the profit of " << i+1 << "th job : ";
        cin >> profit[i];
    }

    int* res = jobSeq(deadline,profit,j);

    cout << "Total schedulable jobs : " << res[0] << endl;
    cout << "Maximum achievable profit : " << res[1] << endl;
    return 0;
}