#ifndef DIJKSTRA_CPP
#define DIJKSTRA_CPP

#include "./Graph.cpp"
#include <unordered_map>
#include <limits>

template <typename WeightType,bool directed=false>
class Dijkstra{
    public:
        Graph<WeightType,directed,true>* graph;
        Node* src;

        Dijkstra(Graph<WeightType,directed,true>* graph,Node* src):graph(graph),src(src){}

        std::unordered_map<Node*,WeightType> run(){
            std::unordered_map<Node*,WeightType> dist;

            for (Node* node:graph->nodes){
                dist[node] = std::numeric_limits<WeightType>::max();
            }

            dist[src] = 0;

            Node* minNode = src;
            src->visited = true;
            int count = graph->nodes.size() -1;

            while (count > 0){
                for(Node* neighbour:minNode->neighbours){
                    Edge<WeightType> edge = graph->getEdge(minNode,neighbour);
                    if (dist[neighbour] > dist[minNode] + edge.weight){
                        dist[neighbour] = dist[minNode] + edge.weight;
                    }
                }
                
                minNode = nullptr;
                for (Node* node:graph->nodes){
                    if (!node->visited){
                        if (minNode == nullptr || dist[node] < dist[minNode]){
                            minNode = node;
                        }
                    }
                }

                if (minNode == nullptr) break;
                minNode->visited = true;
                count--;
            }
            
            return dist;
        }
        
};

#endif