#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <set>
#include <map>
using namespace std;

class Name {
	string first{};
	string last{};

public:
	Name() = default;
	Name(string first, string last) : first(first), last(last) {}
	string& getFirst() {
		return first;
	}
	string getFirst() const {
		return first;
	}

	string getLast() const {
		return last;
	}
	void setLast(const string& name) {
		last = name;
	}
	void show() const {
		cout << first << " " << last << endl;
	}
	friend ostream& operator<<(ostream& out,const Name& name);
	friend istream& operator>>(istream& in, Name& name);

	bool operator<(const Name& name) const{
		return last < name.last;
	}
};


inline ostream& operator<<(ostream& out, const Name& name)
{
	return out << name.first << name.last;
}
inline istream& operator>>(istream& in, Name& name)
{
	return in >> name.first >> name.last;
}

string file1{ "고객1.txt" }, file2{ "고객2.txt" };

void makeData();

template<>
struct less<Name> {
	bool operator()(const Name& lhs, const Name& rhs) const {
		return lhs.getFirst() < rhs.getFirst();
	}
};

void makeUpper(vector<Name>& v);
int main()
{
	{
		makeData();
	}
	/*문제 1*/
	ifstream in{ file1 };
	if (!in) {
		cout << file1 << "파일이 존재하지 않습니다.";
		return 0;
	}
	vector<Name> v{ istream_iterator<Name>(in),istream_iterator<Name>() };
	in.close();
	/*문제 2*/
	Name Kim;
	for (auto i : v)
		if (i.getLast().compare("kim")==0)
			i.show();
	/*문제 3*/
	/*sort(v.begin(), v.end(), [](const Name& a, const Name& b) {
		return a.getFirst() < b.getFirst();
		});*/

	/*문제 4*/
	//makeUpper(v);

	/*문제 5*/
	sort(v.begin(), v.end());

	/*문제 6*/
	ifstream in2{ file2 };
	if (!in2) {
		cout << file2 << "파일이 존재하지 않습니다.";
		return 0;
	}
	set<Name> s{ istream_iterator<Name>(in2),istream_iterator<Name>() };
	in2.close();
	for (const auto& i : v) {
		s.insert(i);
	}
	v.clear();

	cout << s.size();

	/*for (auto i : s)
		i.show();*/

}

void makeUpper(vector<Name>& v)
{
	char c;
	for (auto& i : v)
		i.getFirst()[0] = toupper(i.getFirst()[0]);
}

void makeData()
{
	ofstream out1(file1);
	ofstream out2(file2);

	default_random_engine dre;
	uniform_int_distribution<> uiNameLen{ 3,12 };
	uniform_int_distribution<> uiName{ 'a','z' };

	for (int i = 0; i < 10000; ++i) {
		string first;
		for (int i = 0; i < uiNameLen(dre); ++i)
			first += uiName(dre);
		string second;
		for (int i = 0; i < 3; ++i)
			second += uiName(dre);
		Name name(first, second);
		out1 << name.getFirst() << "\t" << name.getLast() << endl;

	}

	for (int i = 0; i < 20000; ++i) {
		string first;
		for (int i = 0; i < uiNameLen(dre); ++i)
			first += uiName(dre);
		string second;
		for (int i = 0; i < 3; ++i)
			second += uiName(dre);
		Name name(first, second);
		out1 << name.getFirst() << "\t" << name.getLast() << endl;

	}
}