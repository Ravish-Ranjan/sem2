#include <iostream>
using namespace std;

class cls_first
    {
        public:
            void fun_show_first()
                {
                    cout << "First parent function" << endl;
                }
    };

class cls_second
    {
        public:
            void fun_show_second()
                {
                    cout << "Second parent function" << endl;
                }
    };

class cls_child:public cls_first,public cls_second
    {
        public:
            void fun_show_child()
                {
                    cout << "Child function" << endl;
                }
    };

int main()
    {
        cls_child obj;

        obj.fun_show_first();
        obj.fun_show_second();
        obj.fun_show_child();
        return 0;
    }