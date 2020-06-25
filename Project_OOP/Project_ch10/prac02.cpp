// 두 배열을 하나의 정렬된 배열로 병합시키는 제네릭 함수 구현
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 크기가 같고 각각 정렬된 두 배열을 입력 받고, 
// 두 배열을 병합하여 정렬된 새 배열을 리턴한다.
template <class T>
T* merge(T src1[], T src2[], int size) {
	T* arr = new T[size * 2];
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

	double d1[] = { 1.5, 2.7, 9.6, 1e+10 };
	double d2[] = { -3.8, 0, 1e-10, 100.0 };
	double* d3 = merge(d1, d2, 4);
	print(d3, 8);
	
	delete[] c;
	delete[] d3;
	return 0;
}