// cin, cout ��ü�� istream, ostream ��� �Լ��� ����� ����� ���α׷�
#include <iostream>
using namespace std;

int main()
{
	cout.write("how many lines?",sizeof("how many lines?"));
	char line = cin.get();
	cin.ignore(1);	// ��Ʈ�� ���ۿ� ���� '\n'�� ����

	char str[9][80]{};	// 0~9 ������ ��, �� ���� 80 ����Ʈ ����
	for (int i = 0; i < atoi(&line); ++i) {
		cout.write("input a line:",sizeof("input a line:"));
		cin.getline(str[i], 80);
	}

	for (int i = 0; i < atoi(&line); ++i) {
		cout.write(str[i], sizeof(str[i]));
		cout.put('\n');
	}
}