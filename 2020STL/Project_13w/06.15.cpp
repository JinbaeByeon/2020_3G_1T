#include <iostream>
#include <iterator>
#include <algorithm>
#include "String.h"

#include <fstream>
#include <vector>

using namespace std;

//#define ����1
#define ����2

#ifdef ����1
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

#ifdef ����2

struct PS : pair<string, string> {
	PS(string s) :pair(s, s) {
		sort(first.begin(), first.end());
	}
};

int main()
{
	ifstream in("�ܾ��.txt");
	vector<PS> v{ istream_iterator<string>(in),{} };
	
	for (int i = 0; i < 10000; ++i)
		cout << v[i].first << " " << v[i].second << endl;

	cout << "------------------------" << endl;
	cout << "�ֳʱ׷��� ã�Ƶ帳�ϴ�." << endl;
	cout << "------------------------" << endl;

	
	cout << "ã�� �ܾ �Է��ϼ���: ";
	string word;
	cin >> word;
	
	sort(word.begin(), word.end());
	
	do {
		cout << word << "\r";
		//if (binary_search(v.begin(), v.end(), word))
		//	cout << "�������� ã�� �ܾ� - " << word << endl << "\r";
	} while (next_permutation(word.begin(),word.end()));
	// ã�� �ܾ ������ �ִ� �ܾ��ΰ�?
}
#endif