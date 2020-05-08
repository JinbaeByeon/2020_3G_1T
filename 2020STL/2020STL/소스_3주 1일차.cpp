#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include<algorithm>

using namespace std;

int gid{};

default_random_engine dre;
uniform_int_distribution<int> uidAge(1, 12);
uniform_int_distribution<int> uidName('a', 'z');
uniform_int_distribution<int> uidNameLen(3, 15);

class Dog {
private:
	string name;
	int age;
	int id;

public:
	Dog() :id(++gid) {
		int len = uidNameLen(dre);
		for (int i = 0; i < len; ++i)
			name += uidName(dre);
		age = uidAge(dre);
	}
	Dog(string name, int age) : name{ name }, age{ age }, id{ ++gid }{};
	friend bool Compare(const Dog&, const Dog&);
	string getName() const { return name; }
	virtual ~Dog() {}
	friend ostream& operator<<(ostream&, const Dog&);
};

Dog dog[10000];

int main()
{
	ifstream in("Dog만마리", ios::binary);

	in.read((char*)dog, sizeof(Dog));
	
	sort(begin(dog), end(dog), [](const Dog& a, const Dog& b) {
		return Compare(a,b);
		//return a.getName() < b.getName();
		});
	
	cout << "첫 번째 Dog : " << dog[0] << endl;
	cout << "두 번째 Dog : " << dog[9999] << endl;
}


ostream& operator<<(ostream& os, const Dog& dog)
{
	os << dog.name << ", " << dog.age << ", " << dog.id;
	return os;
}

bool Compare(const Dog& a, const Dog& b)
{
	return a.name.compare(b.name) == -1;
}