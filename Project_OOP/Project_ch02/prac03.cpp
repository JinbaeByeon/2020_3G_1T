// Ű����κ��� 2���� ������ �Է¹޾� ū ���� ȭ�鿡 ����ϴ� ���α׷�

#include <iostream>

using namespace std;

int main()
{
	int num1 = 0, num2 = 0;

	cout << "�� ���� �Է��϶�>>";
	cin >> num1 >> num2;

	if (num1 > num2)	// num1�� num2 ���� Ŭ ��� num1�� ����ϰ�
		cout << "ū �� = " << num1;
	else				// �ݴ��� ��� num2�� �����
		cout << "ū �� = " << num2;
}