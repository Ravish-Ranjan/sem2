#include <iostream>
using namespace std;

int main(){
    int v = 0,e = 0;
    cout << "Enter the no. of vertices : ";
    cin >> v;
    cout << "vertex {";
    
    for (int i = 0; i < v; i++)
        cout << char(65+i) << ",";
    
    int adj[v][v];
    cout << "}\nNow enter edge cost from and to (0 if no edge)" << endl;
    int c = 0;
    for (int i = 0; i < v; i++){
        for (int j = i+1; j < v; j++){
            cout << "cost from " << char(65+i) << " to " << char(65+j) << " : ";
            cin >> c;
            adj[i][j] = adj[j][i] = c;
        }
    }
    


    return 0;
}