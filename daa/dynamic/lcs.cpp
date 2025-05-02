#include <iostream>
using namespace std;

int lcsRec(string str1,string str2,int m,int n,int** memo){
    if(m == 0 || n == 0)
        return 0;
    
    if (memo[m][n] != -1)
        return memo[m][n];

    if (str1[m] == str2[n])
        return 1 + lcsRec(str1,str2,m-1,n-1,memo);

    memo[m][n] = max(lcsRec(str1,str2,m,n-1,memo),lcsRec(str1,str2,m-1,n,memo));
    return memo[m][n];
}

int lcs(string str1,string str2,int m,int n){
    int** memo = new int*[m+1];
    for (int i = 0; i <= n; i++) {
        memo[i] = new int[n+1];
        for (int j = 0; j <= n; j++)
            memo[i][j] = -1;
    }
    int res = lcsRec(str1,str2,m,n,memo);
    for (int i = 0; i <= n; i++) {
        delete[] memo[i];
    }
    delete[] memo;
    return res;
}

int main(){
    string s1 = "",s2 = "";
    cout << "Enter first string : ";
    cin >> s1;
    cout << "Enter second string : ";
    cin >> s2;
    int res = lcs(s1,s2,s1.length(),s2.length());

    cout << "Longest common substring size : " << res << endl;
    return 0;
}