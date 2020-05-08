// �� ���� string�� ���� ������ �����Ͽ� ���ڿ��� ũ�⸸ŭ ������ �޴� ���α׷�
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
	// s_sort�� s1�� s2�� ��ģ ���ڿ��� �Է�
	string s_sort{ s1 + s2 };
	// s_sort ����
	sort(s_sort.begin(), s_sort.end());

	// s_sort���� s1��ŭ�� ������ �պκ��� s1�� �ִ´�.
	s1 = s_sort.substr(0, s1.length());
	// s_sort���� s1 ���� ������ �޺κ��� s2�� �ִ´�.
	s2 = s_sort.substr(s1.length());
}