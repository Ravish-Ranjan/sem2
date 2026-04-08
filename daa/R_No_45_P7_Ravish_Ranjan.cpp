#include "./algos/BFS.cpp"
#include "./algos/DFS.cpp"
#include "./algos/Prims.cpp"
#include "./algos/Kruskals.cpp"
#include "./algos/Dijkstra.cpp"

int main(){
    Graph<int,true,true>* g = new Graph<int,true,true>();

    Node* A = new Node("A");
    Node* B = new Node("B");
    Node* C = new Node("C");
    Node* D = new Node("D");
    Node* E = new Node("E");
    Node* F = new Node("F");
    Node* G = new Node("G");

    std::vector<Node*> nodes = {A,B,C,D,E,F,G};

    g->addNodes(nodes);

    g->addEdge(A,B,1);
    g->addEdge(A,C,2);
    g->addEdge(B,D,3);
    g->addEdge(B,E,4);
    g->addEdge(C,F,5);
    g->addEdge(E,F,1);
    g->addEdge(F,G,7);

    g->plot("p7_original_graph","original_graph",false,false,true);


    BFS<int,true,true> bfs(g,A);
    bfs.run();

    for (Node* node:nodes) node->reset();
    
    DFS<int,true,true> dfs(g,A);
    dfs.run();
    
    for (Node* node:nodes) node->reset();
    
    Prims<int,true,true> prims(g);
    int primsMinCost = prims.run();
    
    for (Node* node:nodes) node->reset();
    
    Kruskal<int,true,true> kruskal(g);
    int kruskalMinCost = kruskal.run();
    
    std::cout << "Minimum cost of MST (Prims): " << primsMinCost << std::endl;
    std::cout << "Minimum cost of MST (Kruskal): " << kruskalMinCost << std::endl;
    
    for (Node* node:nodes) node->reset();

    Dijkstra<int,true> dijkstra(g,A);

    std::unordered_map<Node*,int> distances = dijkstra.run();

    for(const auto& pair:distances){
        std::cout << "Distance from A to " << pair.first->name << ": " << pair.second << std::endl;
    }

    return 0;
}