/* 1~9 ������ �� ���� �Է¹ް� 1���� ������������ n�࿡ n���� ���ڸ� �̾ ����
(�� ���ڴ� �����Ѵ�, 1~9 ������ ���� �Էµ��� ������ �ٽ� �Է�)
��)	1
	2 3
	4 5 6
	7 8 9 10
	11 12 13 14 15
*/
#include <iostream>
using namespace std;

int main()
{
	int num_line = 0;	// ���� ��
	int num_cur = 0;	// ���� ����

	while (num_line < 1 || num_line >9) {
		cout << "�� ���Դϱ�? (1~9 �Է�) ";
		cin >> num_line;
	}
	for (int i = 1; i <= num_line; ++i) {

		for (int j = 0; j < i; ++j)
			cout << ++num_cur << " ";

		cout << endl;
	}
}