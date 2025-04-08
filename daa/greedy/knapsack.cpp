#include <iostream>
using namespace std;

class Object{
    public:
        double weight;
        double prize;
        string name;
        Object() : weight(0), prize(0), name("") {}
        Object(double w, double p, string n) : weight(w), prize(p),name(n) {}
};

class Sack{
    private:
        int capacity = 0;
        Object* objects = nullptr;
        int count = 0;
        int prize = 0;
    public:
        Sack(int size) : objects(nullptr) {
            if (size >= 0) {
                capacity = size;
                objects = new Object[size];
            }
        }
        ~Sack(){
            delete objects;
        }
        int add(Object obj){
            if ((obj.weight <= capacity) && (capacity > 0)){
                count += 1;
                objects[count-1] = obj;
                prize += obj.prize;
                capacity -= obj.weight;
                return 1;
            } else if ((obj.weight > capacity) && (capacity > 0)){
                count += 1;
                objects[count-1] = obj;
                prize += capacity * obj.prize / obj.weight;
                capacity = 0;
                return 0;
            } else {
                cout << "Sack is full" << endl;
                return -1;
            }
        }
        void show(){
            cout << "----------------\nSack : {" ;
            for (int i = 0; i < count; i++){
                cout << "(" << objects[i].name << ")";
                if (i != count -1) cout << ",";
            }
            cout << "}" << endl;
            cout << "Total prize : " << prize << endl;
            cout << "Capacity left : " << capacity << endl;
            cout << "Objects picked : " << count << "\n----------------";
        }
};

void swap(Object* a,Object* b){
    Object temp = *a;
    *a = *b;
    *b = temp;
}

void sortObjects(Object* objects, int obj_count){
    for (int  i = 0; i < obj_count; i++){
        for (int j = 0; j < obj_count-i-1; j++){
            if (objects[j].prize/objects[j].weight < objects[j+1].prize/objects[j+1].weight){
                swap(objects[j],objects[j+1]);
            }
        }
    }
}

int main(){
    int sack_size = 0;
    int obj_count = 0;
    
    cout << "Enter the sack capacity : ";
    cin >> sack_size;
    Sack sk(sack_size);
    
    cout << "Enter the count of object you want to enter : ";
    cin >> obj_count;
    cout << endl;
    
    Object objects[obj_count];
    string name;
    double weight;
    double prize;

    for (int i = 0; i < obj_count; i++){
        cout << "Object name : ";
        cin >> objects[i].name;
        cout <<"Object weight(double) : ";
        cin >> objects[i].weight;
        cout << "Object prize(double) : ";
        cin >> objects[i].prize;
        cout << endl;
    }
    
    sortObjects(objects,obj_count);
    
    int res = true;
    int at = 0;

    do{
        res = sk.add(objects[at]);
        if (res > 0 ){
            cout << "Object  " << objects[at].name << " added fully" << endl;
        } else if(res == 0){
            cout << "Object  " << objects[at].name << " added partially" << endl;
        } else if (res < 0){
            cout << "Object  " << objects[at].name << " not added" << endl;
        }
        at++;
    } while (res && at < obj_count);

    sk.show();
    
    return 0;
}