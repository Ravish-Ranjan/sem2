#include <iostream>
using namespace std;

class cls_constructor
	{
		private:
			int num;
		public:
			cls_constructor(int n)
				{
					this->num = n;
				}
			void func_show()
				{
					cout << "Number : " << this->num << endl;
				}
	};
int main()
	{
		cls_constructor obj1(10);
		obj1.func_show();
		return 0;
	}
