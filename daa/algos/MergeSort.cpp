#ifndef MERGESORT_CPP
#define MERGESORT_CPP

#include "../metric.cpp"

class MergeSort: public Metric{
    public:
        void merge(json& data,int low,int mid,int high,int key){
            int n1 = mid-low+1, n2 = high-mid;
            json L,R;

            for(int i = 0; i<n1; i++){
                assign(L,i,data[low+i]);
                this->assigns++;
            }
            
            for(int i = 0; i<n2; i++){
                assign(R,i,data[mid+1+i]);
                this->assigns++;
            }

            int i = 0,j = 0,k = low;

            while (i<n1 && j<n2){
                this->comps++;
                if (L[i][key] < R[j][key]){
                    assign(data,k,L[i]);
                    this->assigns++;
                    i++;
                } else{
                    assign(data,k,R[j]);
                    this->assigns++;
                    j++;
                }
                k++;
            }

            while (i<n1){
                assign(data,k,L[i]);
                this->assigns++;
                i++;
                k++;
            }

            while (j<n2){
                assign(data,k,R[j]);
                this->assigns++;
                j++;
                k++;
            }

        }
        void mergeSort(json& data,int low,int high,int key){
            if (low < high){
                int mid = low+((high-low)/2);
                mergeSort(data,low,mid,key);
                mergeSort(data,mid+1,high,key);
                merge(data,low,mid,high,key);
            }
        }
        void algo(json& data,int key) override{
            this->mergeSort(data,0,data.size()-1,key);
        }
};


#endif