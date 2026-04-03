#include "./algos/BFS.cpp"
#include "./algos/DFS.cpp"

int main(){
    Graph<int,true,true>* g = new Graph<int,true,true>();

    Node* A = new Node("A");
    Node* B = new Node("B");
    Node* C = new Node("C");
    Node* D = new Node("D");
    Node* E = new Node("E");
    Node* F = new Node("F");
    Node* G = new Node("G");

    g->addNode(A);
    g->addNode(B);
    g->addNode(C);
    g->addNode(D);
    g->addNode(E);
    g->addNode(F);
    g->addNode(G);

    g->addEdge(A,B,1);
    g->addEdge(A,C,2);
    g->addEdge(B,D,3);
    g->addEdge(B,E,4);
    g->addEdge(C,F,5);
    g->addEdge(E,F,6);
    g->addEdge(F,G,7);


    BFS<int,true,true> bfs(g,A);
    bfs.run();

    A->reset();B->reset();C->reset();D->reset();
    E->reset();F->reset();G->reset();

    DFS<int,true,true> dfs(g,A);
    dfs.run();

    return 0;
}