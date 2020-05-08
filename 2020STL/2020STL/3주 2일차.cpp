#include <iostream>
#include <memory>
using namespace std;

class Dog {
	int n;
public:

	 Dog() { cout << "생성" << endl; }
	 ~Dog() { cout << "소멸" << endl; }
	void show() {
		cout << "Dog입니다만" << endl;
	}

};

int main()
{

	{
		auto dog = make_unique<Dog>();
	}

	unique_ptr<Dog[]> dogs{ new Dog[3] };
	
}