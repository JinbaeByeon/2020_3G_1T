// ������ �Է¹ް� �Է¹��� ���� 1 �����ְ� ����ϴ� ������ 3�� �ݺ��ϴ� ���α׷�
#include <iostream>
using namespace std;

void increase(int&);

int main() {
	int i;
	cin >> i;
	cout << i << endl;
	increase(i);
	cout << i << endl;
	increase(i);
	cout << i << endl;
	return 0;
}

// n�� 1�� �����ش�.
void increase(int& n) { ++n; }