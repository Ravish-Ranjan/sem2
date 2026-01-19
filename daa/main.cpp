#include "metric.cpp"
#include <iostream>
#include <string>

class Algo : public Metric {
    public:
        void algo(json data,std::string key) override{
            for (int i = 2; i< data[key].size(); i++){
                auto elem = data[key][i];
                int j = i-1;
                this->assigns++;
                while (j >= 0){
                    this->comps++;
                    if (elem < data[key][j]){
                        data[key][j+1] = data[key][j];
                        this->assigns++;
                        j--;
                    } else {
                        break;
                    }
                }
                data[key][j+1] = elem;
                this->assigns++;
            }
        }
};

json analyer(std::string inpTp,std::string inpNm,std::string key,Algo& algoObj,std::string inpFN = "input-data"){
    std::vector<double> comps,assigns;
    for (int size = 10; size <= 100; size+=10){
        Input inp(inpTp,inpNm,size,inpFN);
        double totalComps = 0;
        double totalAssigns = 0;
        for (int rep = 0; rep<10; rep++){
            inp.genInput();
            json copy = inp.input;
            algoObj.algo(copy,key);
            totalComps += algoObj.comps;
            totalAssigns += algoObj.assigns;
            algoObj.reset();
        }
        comps.push_back(totalComps/(double)10.0);
        assigns.push_back(totalAssigns/(double)10.0);
    }
    Output out(inpFN);
    out.genGraph(comps,assigns);
    json ret = {{"comps",comps},{"assigns",assigns}};
    return ret;
}

int main(){
    Algo a;
    analyer("int","age","age",a,"Check");

    return 0;
}