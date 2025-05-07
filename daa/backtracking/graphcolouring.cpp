#include <iostream>
using namespace std;

bool isSafe(int v,int c,int** adj,int* colours,int V){
    for (int i = 0; i < V; i++){
        if(adj[v][i] && c == colours[i])
            return false;
    }
    return true;
}

bool graphColouringRec(int** adj,int* colours,int count,int v,int V){
    if (v == V)
        return true;
    
    for (int c = 1; c < count+1; c++){
        if (isSafe(v,c,adj,colours,V)){
            colours[v] = c;
            if (graphColouringRec(adj,colours,count,v+1,V))
                return true;
            colours[v] = 0;
        }
    }
    return false;
}

bool graphColouring(int** adj,int V,int count){
    int colours[V];
    for (int i = 0; i < V; i++)
        colours[i] = 0;
    if (!graphColouringRec(adj,colours,count,0,V)){
        cout << "Solution doesn't exist" << endl;
        return false;
    }
    cout << "Solution exists : " ;
    for (int i = 0; i < V; i++)
        cout << colours[i] << " ";
    cout << endl;   
    delete[] colours; 
    return true;
}

int main(){
    int V = 0,c = 0;
    cout << "Enter the no. of vertices : ";
    cin >> V;
    cout << "Enter the no. of colours : ";
    cin >> c;

    int** adj = new int*[V];
    for (int i = 0; i < V; i++) {
        adj[i] = new int[V];
        for (int j = 0; j < V; j++)
            adj[i][j] = 0; 
    }

    int e;
    cout << "Enter 1 if edge exists else 0" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            cout << "from " << i + 1 << " to " << j + 1 << " : ";
            cin >> e;
            adj[i][j] = adj[j][i] = e;
        }
    }

    graphColouring(adj, V, c);

    for (int i = 0; i < V; i++)
        delete[] adj[i];
    delete[] adj;
    return 0;    
}