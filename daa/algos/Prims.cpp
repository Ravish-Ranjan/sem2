#ifndef PRIMS_CPP
#define PRIMS_CPP

#include "./Graph.cpp"
#include <queue>

template <typename WeightType,bool directed = false,bool weighted = false>
class Prims{
    private:
        struct compare{
            bool operator()(Edge<WeightType>* a, Edge<WeightType>* b){
                return a->weight > b->weight;
            }
        };
    public:
        Graph<WeightType,directed,weighted>* graph;

        Prims(Graph<WeightType,directed,weighted>* graph): graph(graph){}
        
        WeightType run(){
            std::priority_queue<Edge<WeightType>*, std::vector<Edge<WeightType>*>, compare> pq;
            std::queue<Node*> q;

            Graph<WeightType,directed,weighted>* mst = new Graph<WeightType,directed,weighted>();

            mst->addNodes(this->graph->nodes);

            q.push(this->graph->nodes.at(0));

            WeightType totalCost = 0.0;

            while (!q.empty()){
                Node* node = q.front();
                q.pop();

                node->visited = true;

                for(Edge<WeightType>* edge:this->graph->getEdgesFromNode(node)){
                    if (!edge->to->visited){
                        pq.push(edge);
                    }
                }
                
                while (!pq.empty()){
                    Edge<WeightType>* edge = pq.top();
                    pq.pop();

                    if (!edge->to->visited){
                        mst->addEdge(edge->from,edge->to,edge->weight);
                        q.push(edge->to);
                        totalCost += edge->weight;
                        break;
                    }
                }
            }

            mst->plot("p7_prims","Prims_MST",true,false,true);

            return totalCost;
        }
};

#endif