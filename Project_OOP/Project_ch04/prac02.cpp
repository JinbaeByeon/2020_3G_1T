// string Ŭ������ �̿��Ͽ� ��ĭ�� �����ϴ� ���ڿ��� �Է¹ް� ���ڿ����� ��a���� �� �� �ִ����� ����ϴ� ���α׷�
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string text;	// �Է¹��� ���ڿ�
	int nFound = 0;	// ������ ����

	cout << "���ڿ� �Է�>>";
	getline(cin,text,'\n');

	for (int i = 0; i < text.length(); ++i) {
		if (text.find('a', i) == -1) break;	// a�� ��ã���� �ݺ����� ����
		i = text.find('a', i);				// a�� ã�� �ε��� ��ġ�� i�� �̵�
		++nFound;								// a�� ã�����Ƿ� ���� ����
	}
	cout << "���� a�� " << nFound << "�� �ֽ��ϴ�." << endl;
} 