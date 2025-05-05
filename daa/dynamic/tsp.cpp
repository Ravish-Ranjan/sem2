#include <iostream>
using namespace std;

int tspRec(int mask, int pos, int v, int** cost, int** memo) {
    if (mask == (1 << v) - 1) 
        return cost[pos][0]; 
    
    if (memo[mask][pos] != -1)
        return memo[mask][pos];
    
    int ans = INT32_MAX;
    
    for (int i = 0; i < v; i++) {
        if ((mask & (1 << i)) == 0) { 
            int newAns = cost[pos][i] + tspRec(mask | (1 << i), i, v, cost, memo);
            ans = min(ans, newAns);
        }
    }
    
    return memo[mask][pos] = ans;
}

int tsp(int** cost, int v) {
    int rows = 1 << v;
    
    int** memo = new int*[rows];
    for (int i = 0; i < rows; i++) {
        memo[i] = new int[v];
        for (int j = 0; j < v; j++) {
            memo[i][j] = -1;
        }
    }
    
    int result = tspRec(1, 0, v, cost, memo);
    
    for (int i = 0; i < rows; i++)
        delete[] memo[i];
    delete[] memo;    
    return result;
}

int main() {
    int v = 0;
    cout << "Enter the no. of nodes : ";
    cin >> v;

    int** adj = new int*[v];
    for (int i = 0; i < v; i++) {
        adj[i] = new int[v];
        for (int j = 0; j < v; j++) {
            adj[i][j] = 0;
        }
    }

    int c;
    for (int i = 0; i < v; i++) {
        for (int j = i + 1; j < v; j++) {
            cout << "Cost from " << i + 1 << " to " << j + 1 << " : ";
            cin >> c;
            adj[i][j] = adj[j][i] = c;
        }
    }
    
    int res = tsp(adj, v);

    cout << "Minimum distance cost for salesman : " << res << endl;

    for (int i = 0; i < v; i++) {
        delete[] adj[i];
    }
    delete[] adj;

    return 0;
}