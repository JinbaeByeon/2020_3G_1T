/* "yes"�� �Էµ� ������ �������� �ʴ� ���α׷� */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s_input;

	while (s_input.compare("yes")) {	// "yes"�� �Է¹��� ��� �ݺ��� ����
		cout << "�����ϰ� ������ yes�� �Է��ϼ���>>";
		getline(cin, s_input, '\n');	// ���๮�ڸ� �Է¹��� �������� ���ڿ��� s_input�� �޴´�.
	}
	cout << "�����մϴ�..." << endl;
}