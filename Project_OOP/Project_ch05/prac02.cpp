// 두 개의 string을 사전 순으로 정렬하여 문자열의 크기만큼 나누어 받는 프로그램
#include <iostream>
#include <algorithm>

using namespace std;

void sort(string&, string&);

int main() {
	string str1("xyz");
	string str2("abc");
	sort(str1, str2);
	cout << str1 << endl;
	cout << str2 << endl;
	return 0;
}

void sort(string& s1, string& s2)
{
	// s_sort에 s1과 s2를 합친 문자열을 입력
	string s_sort{ s1 + s2 };
	// s_sort 정렬
	sort(s_sort.begin(), s_sort.end());

	// s_sort에서 s1만큼의 길이의 앞부분을 s1에 넣는다.
	s1 = s_sort.substr(0, s1.length());
	// s_sort에서 s1 길이 이후의 뒷부분을 s2에 넣는다.
	s2 = s_sort.substr(s1.length());
}