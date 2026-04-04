#ifndef KRUSKALS_H
#define KRUSKALS_H

#include "./Graph.cpp"
#include <algorithm>

template <typename WeightType,bool directed = false,bool weighted = false>
class Kruskal{
    
    public:
        Graph<WeightType,directed,weighted>* graph;

        Kruskal(Graph<WeightType,directed,weighted>* graph): graph(graph){}

        WeightType run(){
            std::vector<Edge<WeightType>*> edges;
            std::vector<std::vector<Node*>> sets;

            for (Node* node:this->graph->nodes){
                sets.push_back({node});
            }

            for (Edge<WeightType>* edge:this->graph->edges){
                edges.push_back(edge);
            }

            std::sort(edges.begin(),edges.end(),[](Edge<WeightType>* a, Edge<WeightType>* b){
                return a->weight < b->weight;
            });

            Graph<WeightType,directed,weighted>* mst = new Graph<WeightType,directed,weighted>();
            mst->addNodes(this->graph->nodes);
            
            WeightType totalCost = 0.0;

            for(Edge<WeightType>* edge:edges){
                int setA = -1, setB = -1;

                for (int i = 0; i < sets.size(); i++){
                    if (std::find(sets[i].begin(),sets[i].end(),edge->from) != sets[i].end()){
                        setA = i;
                    }
                    if (std::find(sets[i].begin(),sets[i].end(),edge->to) != sets[i].end()){
                        setB = i;
                    }
                }

                if (setA != setB){
                    mst->addEdge(edge->from,edge->to,edge->weight);
                    totalCost += edge->weight;

                    if (sets[setA].size() < sets[setB].size()){
                        std::swap(setA,setB);
                    }
                    sets[setA].insert(sets[setA].end(),sets[setB].begin(),sets[setB].end());
                    sets.erase(sets.begin() + setB);
                }
            }

            mst->plot("p7_kruskal","Kruskal_MST",true,false,true);
            return totalCost;
        }

};

#endif