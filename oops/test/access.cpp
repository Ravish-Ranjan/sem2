#include <iostream>
using namespace std;

class Base{
    private:
        int private_data = 10;
        void private_mem(){
            cout << "private mem" << endl;
        }
    protected:
        int protected_date = 20;
        void protected_mem(){
            cout << "protected mem" << endl;
        }
    public:
        int public_data = 30;
        void public_mem(){
            cout << "public mem" << endl;
        }
};

class PublicClass: public Base{
    public:
        PublicClass(){
            cout << "PublicClass public: " << this->public_data << endl;
            cout << "PublicClass protected: " << this->protected_date << endl;
            this->public_mem();
            this->protected_mem();
        }
};

class ProtectedClass : protected Base{
    public:
        ProtectedClass(){
            cout << "ProtectedClass protected" << this->public_data << endl;
            cout << "ProtectedClass protected" << this->protected_date << endl;
            this->public_mem();
            this->protected_mem();
        }
};

class PrivateClass : private Base{
    public:
        PrivateClass(){
            cout << "PrivateClass private" << this->public_data << endl;
            cout << "PricateClass private" << this->protected_date << endl;
            this->public_mem();
            this->protected_mem();
        }
};

int main(){
    Base obj_base;
    PublicClass obj_public;
    ProtectedClass obj_protected;
    PrivateClass obj_private;
    return 0;
}