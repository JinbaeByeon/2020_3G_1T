#include <iostream>
#include <memory>
using namespace std;

class Dog {
	int n;
public:

	 Dog() { cout << "����" << endl; }
	 ~Dog() { cout << "�Ҹ�" << endl; }
	void show() {
		cout << "Dog�Դϴٸ�" << endl;
	}

};

int main()
{

	{
		auto dog = make_unique<Dog>();
	}

	unique_ptr<Dog[]> dogs{ new Dog[3] };
	
}