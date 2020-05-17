#include "Dog.h"
#include <iostream>
#include <string>
#include <random>
using namespace std;
int gid{};

default_random_engine dre;
uniform_int_distribution<int> uidAge(1, 12);
uniform_int_distribution<int> uidName('a', 'z');
uniform_int_distribution<int> uidNameLen(3, 15);

Dog::Dog() :id(++gid) {
	int len = uidNameLen(dre);
	for (int i = 0; i < len; ++i)
		name += uidName(dre);
	age = uidAge(dre);
}

Dog::Dog(string name, int age) : name{ name }, age{ age }, id{ ++gid }{};


ostream& operator<<(ostream& os, const Dog& dog)
{
	os << dog.name << ", " << dog.age << ", " << dog.id;
	return os;
}
istream& operator>>(istream& is, Dog& dog)
{
	is.read((char*)&dog, sizeof(dog));
	return is;
}
bool Compare(const Dog& a, const Dog& b)
{
	return a.name.compare(b.name) == -1;
}

bool Dog::operator<(const Dog& rhs) const
{
	return name < rhs.name;
}