#ifndef GRAPH_CPP
#define GRAPH_CPP

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "../util/command.cpp"
#include "../graph.cpp"

enum NodeColor {WHITE,BLACK,GRAY};

class Node{
    public:
        std::string name;
        double cost;
        bool visited = false;
        NodeColor color = NodeColor::WHITE;
        std::vector<Node*> neighbours;
        int level = 0;
        Node* parent = nullptr;

        Node(const std::string& name,double cost=0.0):name(name),cost(cost){}

        void reset(){
            cost = 0.0;
            visited = false;
            color = NodeColor::WHITE;
            level = 0;
            parent = nullptr;
        }
};

template <typename WeightType>
class Edge{
    public:
        WeightType weight;
        Node* from;
        Node* to;
        bool directed;

        Edge(Node* from,Node* to,WeightType weight = 0.0,bool directed = false): from(from),to(to){
            this->weight = weight;
            this->directed = directed;
        }
};

template <typename WeightType,bool directed = false,bool weighted = false>
class Graph{
    public:
        std::vector<Node*> nodes;
        std::vector<Edge<WeightType>*> edges;

        Graph(){}

        void addNode(Node* node){
            this->nodes.push_back(node);
        }

        void addEdge(Node* from,Node* to,WeightType weight=0.0){
            Edge<WeightType>* edge = new Edge<WeightType>(from,to,weight,directed);
            this->edges.push_back(edge);
            edge->from->neighbours.push_back(edge->to);
            if(!edge->directed){
                edge->to->neighbours.push_back(edge->from);
            }
        }

        Edge<WeightType>& getEdge(Node* from,Node* to){
            for(Edge<WeightType>* edge : this->edges){
                if (directed){
                    if (edge->from->name == from->name && edge->to->name == to->name)
                        return *edge;
                } else {
                    if (
                        (edge->from->name == from->name && edge->to->name == to->name) || 
                        (edge->from->name == to->name && edge->to->name == from->name)
                    )
                        return *edge;
                }
            }
            throw std::runtime_error("Edge not found");
        }

        void getAdjacencyList(){
            for(Node* node : this->nodes){
                std::cout << node->name << ": ";
                for(Node* neighbour : node->neighbours){
                    std::cout << neighbour->name << " ";
                }
                std::cout << std::endl;
            }
        }

        std::string plot(
            const std::string& filename,
            const std::string& title,
            bool isTree=false,
            bool showNodeWeight = false,
            bool showEdgeWeight = false
        ){
            std::stringstream ss;
            std::cout << filename << title << std::endl;
            ss << "python ./util/plotgraph.py filename:" << filename << " title:" << title << " ";
            if (directed)
                ss << "directed:true ";
            
            if (isTree)
                ss << "istree:true ";
            
            ss << "nodes:";

            for (int i = 0; i < this->nodes.size(); i++){
                if (i > 0) ss << ",";
                ss << this->nodes.at(i)->name;

                if (showNodeWeight)
                    ss << "~" << this->nodes.at(i)->cost;
            }
            
            ss << " edges:";

            for (int i = 0; i < this->edges.size(); i++){
                if (i > 0) ss << ",";
                ss << this->edges.at(i)->from->name << "~" << this->edges.at(i)->to->name;

                if (showEdgeWeight)
                    ss << "~" << this->edges.at(i)->weight;
            }
            std::string res = runCommand(ss.str());
            openImageInNativeViewer(res);
            return res;
        }
};

#endif