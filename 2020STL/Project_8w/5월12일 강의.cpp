#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <set>
#include <functional>
#include <map>
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
	Dog(int age) :age(age) {};
	void show() const {
		cout << name << ", " << age << endl;
	}
	string getName() const { return name; }
	int getAge() const { return age; }
	/*bool operator<(const Dog& rhs)const {
		return name < rhs.name;
	}*/
	void setAge(int age) { this->age = age; }
};

// 이름 기준
template<>
struct less<Dog> {
	bool operator()(const Dog& lhs, const Dog& rhs) const {
		return lhs.getName() > rhs.getName();
	}
};

bool CmpAge(const Dog& lhs, const Dog& rhs) {
	return lhs.getAge() > rhs.getAge();
}

int main()
{
	ifstream in("Dog천마리",ios::binary);

	/*set*/
	multiset<Dog,function<bool(const Dog& a,const Dog& b)>> sDogs(CmpAge);
	Dog tmp;
	for (int i = 0; i < 1000; ++i) {
		in.read((char*)&tmp, sizeof(Dog));
		sDogs.insert(tmp);
	}

	/*Dog d;
	for (int i = 0; i < 15; ++i) {
		d.setAge(i);
		cout << i << "살 - " << sDogs.count(d) << endl;
	}*/

	map<int, int> mDogs;

	for (const Dog& dog : sDogs)
		mDogs[dog.getAge()]++;
	for (auto [age, num] : mDogs)
		cout << age << " - " << num << endl;

	save("5월12일 강의.cpp", "5월12일 강의.txt");
}

class Name {
	string first{};
	string last{};
public:
	Name() = default;
	Name(string first, string last) :first{ first }, last{ last }{}
	string& getFirst() { return first; }
	string getFirst() const { return first; }
	string& getLast() { return last; }
	string getLast()const { return last; }
	void setLasg(const string& name) {
		last = name;
	}
	void show() const {
		cout << first << " " << last << endl;
	}
};

string file1{ "고객1.txt" }, file2{ "고객2.txt" };

void makeData();

//int main()
//{
//	makeData();
//}