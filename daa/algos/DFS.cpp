#ifndef DFS_CPP
#define DFS_CPP

#include "./Graph.cpp"
#include <stack>

template <typename WeightType,bool directed = false,bool weighted = false>
class DFS{
    public:
        Graph<WeightType,directed,weighted>* graph;
        Node* src;

        DFS(Graph<WeightType,directed,weighted>* graph,Node* src): graph(graph), src(src){}


        void run(){
            Graph<WeightType,directed,weighted>* tree = new Graph<WeightType,directed,weighted>();
            tree->addNode(src);
            dfs(src,tree);
            tree->plot("p7_dfs","DFS",true,false,weighted);
        }
    private:
        void dfs(Node* src,Graph<WeightType,directed,weighted>* tree){
            src->color = NodeColor::GRAY;
            for(Node* neighbour:src->neighbours){
                if (neighbour->color == NodeColor::WHITE){
                    neighbour->color = NodeColor::GRAY;
                    neighbour->level = src->level + 1;
                    neighbour->parent = src;
                    tree->addNode(neighbour);
                    if (weighted){
                        tree->edges.push_back(new Edge<WeightType>(src,neighbour,this->graph->getEdge(src,neighbour).weight,directed));
                    } else {
                        tree->edges.push_back(new Edge<WeightType>(src,neighbour,0.0,directed));
                    }
                    dfs(neighbour,tree);
                }
            }
            src->color = NodeColor::BLACK;
        }
};

#endif