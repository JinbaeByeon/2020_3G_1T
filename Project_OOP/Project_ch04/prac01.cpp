// ���� ���� 5���� �迭�� ���� �Ҵ�ް� ������ 5�� �Է¹޾� ����� ���ϰ� ����ϴ� ���α׷�

#include <iostream>
using namespace std;

int main()
{
	int* n = new int[5];	// ���� 5�� �����Ҵ�
	if (!n) return;
	double average{0};		// ����� �Է¹��� �Ǽ� ��

	cout << "���� 5�� �Է�>>";
	for (int i = 0; i < 5; ++i) {
		cin >> n[i];
		average += n[i];
	}
	average /= 5;
	cout << "��� " << average << endl;

	delete[] n;
}