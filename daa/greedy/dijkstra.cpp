#include <iostream>
using namespace std;

int V = 0;

int* dijkstra(int V, int** edges, int src, int e) {
    int** adj = new int*[V];
    for (int i = 0; i < V; i++) {
        adj[i] = new int[V];
        for (int j = 0; j < V; j++)
            adj[i][j] = (i == j) ? 0 : INT32_MAX;
    }
    int from, to, cost;
    for (int i = 0; i < e; i++) {
        from = edges[i][0] - 1;
        to = edges[i][1] - 1;
        cost = edges[i][2];
        adj[from][to] = adj[to][from] = cost;;
    }
    int* dist = new int[V];
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT32_MAX;
        visited[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int minDist = INT32_MAX, u = -1;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }
        if (u == -1) break;
        visited[u] = true;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && adj[u][v] != INT32_MAX && dist[u] != INT32_MAX &&
                dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    for (int i = 0; i < V; i++)
        delete[] adj[i];
    delete[] adj;
    delete[] visited;
    return dist;
}

int main(){
    cout << "Enter the no. of vertices : ";
    cin >> V;
    int s = 0,e = 0;
    cout << "Enter the source vertex(1-" << V << ") : ";
    cin >> s;
    s--;
    cout << "Enter the no. of edges : ";
    cin >> e;

    int** edges = new int*[e];
    cout << "------------" << endl;
    for (int i = 0; i < e; i++){
        edges[i] = new int[3];
        cout << "Enter the source of edge : ";
        cin >> edges[i][0];
        cout << "Enter the destination of edge : ";
        cin >> edges[i][1];
        cout << "Enter the cost of edge : ";
        cin >> edges[i][2];
    }
    
    int* res = dijkstra(V,edges,s,e);

    cout << "Distance to all other vertices : ";
    for (int i = 0; i < V; i++){
        cout << res[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < e; i++)
        delete[] edges[i];
    delete[] edges;    

    return 0;
}