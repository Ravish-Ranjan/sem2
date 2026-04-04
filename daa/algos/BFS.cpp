#ifndef BFS_CPP
#define BFS_CPP

#include "./Graph.cpp"
#include <queue>

template <typename WeightType,bool directed = false,bool weighted = false>
class BFS{
    public:
        Graph<WeightType,directed,weighted>* graph;
        Node* src;

        BFS(Graph<WeightType,directed,weighted>* graph,Node* src): graph(graph), src(src){}
        
        void run(){
            src->color = NodeColor::GRAY;
            src->level = 0;
        
            std::queue<Node*> q;
            Graph<WeightType,directed,weighted> tree;
            tree.addNode(src);
            q.push(src);
        
            while (!q.empty()){
                Node* node = q.front();
                q.pop();
                node->color = NodeColor::BLACK;
                for(Node* neighbour : node->neighbours){
                    if (neighbour->color == NodeColor::WHITE) {
                        neighbour->color = NodeColor::GRAY;
                        neighbour->level = node->level + 1;
                        neighbour->parent = node;
                        q.push(neighbour);
                        tree.addNode(neighbour);
                        if (weighted) {
                            tree.edges.push_back(new Edge<WeightType>(node, neighbour, 
                                graph->getEdge(node, neighbour).weight, directed));
                        } else {
                            tree.edges.push_back(new Edge<WeightType>(node, neighbour, 0.0, directed));
                        }
                    }
                }
            }
            tree.plot("p7_bfs","bfs",true,false,weighted);
        }
};

#endif