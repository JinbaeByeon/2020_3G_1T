/* ���ڿ��� �� �� �Է� �ް� �� ���� ���ڿ��� �������� �˻��ϴ� ���α׷� */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string password1, password2;
	
	cout << "�� ��ȣ�� �Է��ϼ���>>";
	cin >> password1;

	cout << "�� ��ȣ�� �ٽ� �� �� �Է��ϼ���>>";
	cin >> password2;

	if (password1 == password2) cout << "�����ϴ�." << endl;	// password1�� password2�� ������ "�����ϴ�." ���
	else cout << "���� �ʽ��ϴ�." << endl;		// password1�� password2�� ���� ������ "���� �ʽ��ϴ�." ���
}