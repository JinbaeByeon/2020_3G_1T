#include <iostream>
#include <iterator>
#include <algorithm>
#include "String.h"

#include <fstream>
#include <vector>

using namespace std;

//#define 교시1
#define 교시2

#ifdef 교시1
template<class In,class Out>
Out my_copy(In b, In e, Out d)
{
	while (b != e) {

	}
}

class Ins {
	String& s;
public:
	explicit Ins(String& s) :s(s) {}
	Ins& operator*() {
		return *this;
	}
	Ins& operator=(const Ins& rhs) {
		s = rhs.s;
		return *this;
	}
	Ins& operator=(char c) {
		s.push_back(c);
		return *this;
	}
	void operator++() {

	}

};

int main()
{
	String s;
	copy(istream_iterator<char>(cin), {}, Ins(s));
	cout << s << endl;
}
#endif

#ifdef 교시2

struct PS : pair<string, string> {
	PS(string s) :pair(s, s) {
		sort(first.begin(), first.end());
	}
};

int main()
{
	ifstream in("단어들.txt");
	vector<PS> v{ istream_iterator<string>(in),{} };
	
	for (int i = 0; i < 10000; ++i)
		cout << v[i].first << " " << v[i].second << endl;

	cout << "------------------------" << endl;
	cout << "애너그램을 찾아드립니다." << endl;
	cout << "------------------------" << endl;

	
	cout << "찾을 단어를 입력하세요: ";
	string word;
	cin >> word;
	
	sort(word.begin(), word.end());
	
	do {
		cout << word << "\r";
		//if (binary_search(v.begin(), v.end(), word))
		//	cout << "사전에서 찾을 단어 - " << word << endl << "\r";
	} while (next_permutation(word.begin(),word.end()));
	// 찾는 단어가 사전에 있는 단어인가?
}
#endif