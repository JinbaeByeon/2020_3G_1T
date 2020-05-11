#include<iostream>
#include<map>
#include <functional>
#include <fstream>
#include <iomanip>
#include <set>
#include <random>
#include <iterator>
#include "String.h"
#include "Dog.h"
using namespace std;

/*�� ����*/
//template<>
//struct less<String>
//{
//	bool operator()(const String& a, const String& b) const {
//		return a.getString() < b.getString();
//	}
//};
bool StringCmp(const String& a, const String& b) {
	return a.size() < b.size();
}
bool IntCmp(const int& a, const int& b) {
	return a > b;
}


/*Set ��������*/
//int main()
//{
//	/* Map ���� (include: map,functional)*/
//	/*map<String, String, function<bool(const String&, const String)>> movies(StringCmp);
//
//	movies.insert(make_pair(" �͹̳����� 2", " ���ӽ� ī�޷� "));
//	movies.insert(movies.begin(), pair<String, String>(" �μ��� ", " ũ�������� ��� "));
//	movies.emplace(" ����� ", " ����ȣ ");
//	movies[" �������:������� "] = " �ȼҴ� ��� , �� ��� ";
//	movies[" ũ���������� �Ǹ� "] = " �� ��ư ";
//	movies.insert_or_assign(" �λ��� �Ƹ��ٿ� ", " �κ����� ���ϴ� ");
//	movies.try_emplace(movies.end(), " ���ũ Ż�� ", " ����ũ �ٶ�Ʈ ");
//
//	for (auto [����,����] : movies)
//		cout << ���� << " - " << ���� << endl;*/
//
//	/*�̻��ѳ����Ǿٸ��� ���ĺ� �� �ǽ� (include: map,fstream,functional,iomanip)*/
//	/*ifstream in("�̻��ѳ����Ǿٸ���.txt");
//	if (!in) {
//		return 0;
//	}
//	vector<char> v{ istreambuf_iterator<char>(in),istreambuf_iterator<char>() };
//	map<char, int> alphabet;
//
//	for (char c : v) {
//		if (isalpha(c)) {
//			++alphabet[tolower(c)];
//		}
//	}
//	int cnt = 0;
//	for (auto [alpha, num] : alphabet) {
//		cout << alpha << " - " << left << setw(7) << num;
//		if (++cnt % 5 == 0)
//			cout << endl;
//	}
//	cout << endl;
//	
//	map<int, char,function<bool(const int&,const int&)>> alphabet_sortbynum(IntCmp);
//
//	for (auto [alpha, num] : alphabet) {
//		alphabet_sortbynum[num] = alpha;
//	}
//
//	for (auto [num, alpha] : alphabet_sortbynum) {
//		cout << alpha << " - " << left << setw(7) << num;
//		if (++cnt % 5 == 0)
//			cout << endl;
//	}*/
//
//	/*Set ���� (include: set,random)*/
//	/*random_device rd;
//	default_random_engine dre(rd());
//	uniform_int_distribution<> uid{ 1,45 };
//
//	set<int> s;
//
//	while (s.size() < 6)
//		s.insert(uid(dre));
//	cout << "�̹� �� ��÷��ȣ: ";
//	for (int n : s)
//		cout << n << ' ';
//	cout << endl;*/
//}

/*Set Dog �ǽ�*/
Dog dog[10000];
multiset<Dog> dogs;
int main()
{
	ifstream in("Dog������", ios::binary);
	in.read((char*)dog, sizeof(dog));
//	set<Dog> dogs{ istream_iterator<Dog>(in),istream_iterator<Dog>() };

	for (int i = 0; i < 10000; ++i)
		dogs.insert(dog[i]);
	cout << dogs.size() << endl;
	for (const auto& dog : dogs)
		cout << dog.getName() << endl;

}