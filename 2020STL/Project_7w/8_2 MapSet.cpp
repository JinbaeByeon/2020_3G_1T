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

/*맵 관련*/
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


/*Set 예제까지*/
//int main()
//{
//	/* Map 예제 (include: map,functional)*/
//	/*map<String, String, function<bool(const String&, const String)>> movies(StringCmp);
//
//	movies.insert(make_pair(" 터미네이터 2", " 제임스 카메론 "));
//	movies.insert(movies.begin(), pair<String, String>(" 인셉션 ", " 크리스토퍼 놀란 "));
//	movies.emplace(" 기생충 ", " 봉준호 ");
//	movies[" 어밴져스:엔드게임 "] = " 안소니 루소 , 조 루소 ";
//	movies[" 크리스마스의 악몽 "] = " 팀 버튼 ";
//	movies.insert_or_assign(" 인생은 아름다워 ", " 로베르토 베니니 ");
//	movies.try_emplace(movies.end(), " 쇼생크 탈출 ", " 프랭크 다라본트 ");
//
//	for (auto [제목,감독] : movies)
//		cout << 제목 << " - " << 감독 << endl;*/
//
//	/*이상한나라의앨리스 알파벳 맵 실습 (include: map,fstream,functional,iomanip)*/
//	/*ifstream in("이상한나라의앨리스.txt");
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
//	/*Set 예제 (include: set,random)*/
//	/*random_device rd;
//	default_random_engine dre(rd());
//	uniform_int_distribution<> uid{ 1,45 };
//
//	set<int> s;
//
//	while (s.size() < 6)
//		s.insert(uid(dre));
//	cout << "이번 주 당첨번호: ";
//	for (int n : s)
//		cout << n << ' ';
//	cout << endl;*/
//}

/*Set Dog 실습*/
Dog dog[10000];
multiset<Dog> dogs;
int main()
{
	ifstream in("Dog만마리", ios::binary);
	in.read((char*)dog, sizeof(dog));
//	set<Dog> dogs{ istream_iterator<Dog>(in),istream_iterator<Dog>() };

	for (int i = 0; i < 10000; ++i)
		dogs.insert(dog[i]);
	cout << dogs.size() << endl;
	for (const auto& dog : dogs)
		cout << dog.getName() << endl;

}