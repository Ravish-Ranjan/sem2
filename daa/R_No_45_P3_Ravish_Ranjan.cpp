#include "analyzer.cpp"

class MergeSort: public Metric{
    public:
        void merge(json& data,int low,int mid,int high,const std::string& key){
            int n1 = mid-low+1, n2 = high-mid;
            json L,R;
            for (auto& it:data.items()){
                L[it.key()] = {};
                R[it.key()] = {};
            }

            for(int i = 0; i<n1; i++){
                json savedObj = {};
                for (auto& it:data.items()){
                    savedObj[it.key()] = data[it.key()][low+i];
                }
                assign(L,i,savedObj);
                this->assigns++;
            }
            
            for(int i = 0; i<n2; i++){
                json savedObj = {};
                for (auto& it:data.items()){
                    savedObj[it.key()] = data[it.key()][mid+1+i];
                }
                assign(R,i,savedObj);
                this->assigns++;
            }

            int i = 0,j = 0,k = low;

            while (i<n1 && j<n2){
                this->comps++;
                if (L[key][i] < R[key][j]){
                    json savedObj = {};
                    for (auto& it:data.items()){
                        savedObj[it.key()] = L[it.key()][i];
                    }
                    assign(data,k,savedObj);
                    this->assigns++;
                    i++;
                } else{
                    json savedObj = {};
                    for (auto& it:data.items()){
                        savedObj[it.key()] = R[it.key()][j];
                    }
                    assign(data,k,savedObj);
                    this->assigns++;
                    j++;
                }
                k++;
            }

            while (i<n1){
                json savedObj = {};
                for (auto& it:data.items()){
                    savedObj[it.key()] = L[it.key()][i];
                }
                assign(data,k,savedObj);
                this->assigns++;
                i++;
                k++;
            }

            while (j<n2){
                json savedObj = {};
                for (auto& it:data.items()){
                    savedObj[it.key()] = R[it.key()][j];
                }
                assign(data,k,savedObj);
                this->assigns++;
                j++;
                k++;
            }

        }
        void mergeSort(json& data,int low,int high,const std::string& key){
            if (low < high){
                int mid = low+((high-low)/2);
                mergeSort(data,low,mid,key);
                mergeSort(data,mid+1,high,key);
                merge(data,low,mid,high,key);
            }
        }
        void algo(json& data,const std::string& key) override{
            this->mergeSort(data,0,data.begin().value().size()-1,key);
        }
};

int main(){
    MergeSort ms;
    Analyzer analyzer("name,float","name,age",ms,"MergeSortGenData");
    analyzer.analyze("age");
    
    return 0;
}