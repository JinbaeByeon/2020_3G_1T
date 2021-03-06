#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <vector>
#include "save.h"
using namespace std;

random_device rd;
default_random_engine dre{ rd() };
uniform_int_distribution<> uidAge(1, 12);
uniform_int_distribution<> uidName('a', 'z');


class Dog {
	string name;
	int age;
public:
	Dog() {
		for (int i = 0; i < 10; ++i)
			name += uidName(dre);
		age = uidAge(dre);
	}
	void show() const{
		cout << name << ", " << age << endl;
	}
	string getName() const{ return name; }
};

int main()
{
	Dog dogs[1000];
	//for (auto dog : dogs)
	//	dog.show();
	//ofstream out("Dog천마리", ios::binary);
	//out.write((char*)dogs, sizeof(dogs));
	ifstream in("Dog천마리", ios::binary);
	vector<Dog> vDogs;
	vDogs.resize(1000);

	in.read((char*)vDogs.data(), sizeof(Dog)*1000);
	
	sort(vDogs.begin(), vDogs.end(), [](const Dog& a, const Dog& b) {
		return a.getName() < b.getName();
		});

	for (const Dog& dog : vDogs)
		dog.show();
	save("5월11일 강의.cpp", "5월11일 강의.txt");
}