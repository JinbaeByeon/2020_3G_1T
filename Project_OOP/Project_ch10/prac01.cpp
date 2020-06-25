// �� ���� �迭�� �ϳ��� �迭�� ��ġ�� ���α׷�
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// ũ�Ⱑ ���� ���� ���ĵ� �� int �迭�� �Է� �ް�, 
// �� �迭�� �����Ͽ� ���ĵ� �� �迭�� �����Ѵ�.
int* merge(int src1[], int src2[], int size) {
	int* arr = new int[size * 2];
	for (int i = 0; i < size; ++i) {
		arr[2 * i] = src1[i];
		arr[2 * i + 1] = src2[i];
	}
	sort(arr, arr + size * 2);
	return arr;
}

template <class T>
void print(T arr[], int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

int main() {
	int a[] = { 2, 3, 5, 7, 9 };
	int b[] = { 1, 4, 6, 8, 12 };
	int* c = merge(a, b, 5);
	print(c, 10);
	delete[] c;
	return 0;
}