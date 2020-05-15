/* 정수 배열을 항상 증가 순으로 유지하는 SortedArray 클래스*/
#include <iostream>

using namespace std;

class SortedArray {
	int size; // 현재 배열의 크기
	int* p; // 정수 배열에 대한 포인터
	void sort(); // 정수 배열을 오름차순으로 정렬
public:
	SortedArray() : p{ NULL }, size{ 0 } {} // p는 NULL로 size는 0으로 초기화
	SortedArray(SortedArray& src);	// 복사 생성자
	SortedArray(int p[], int size); // 생성자. 정수 배열과 크기를 전달받음
	~SortedArray() { // 소멸자
		if(p)
			delete[] p;
	}
	SortedArray operator + (SortedArray& op2);
	SortedArray& operator = (const SortedArray& op2); // 현재 배열에 op2 배열을 복사
	void show(); // 배열의 원소 출력
};

int main() {
	int n[] = { 2, 20, 6 };
	int m[] = { 10, 7, 8, 30 };
	SortedArray a(n, 3), b(m, 4), c;

	c = a + b;

	a.show();
	b.show();
	c.show();
}

void SortedArray::sort()
{
	for (int i = 0; i < size; ++i)
		for (int j = i; j < size; ++j) {
			if (p[i] > p[j]) {
				swap(p[i], p[j]);
				j = i;
			}
		}
}
SortedArray::SortedArray(SortedArray& src) : size{ src.size },p{new int[size]}
{
	memcpy(p, src.p, size);
	sort();
}

SortedArray::SortedArray(int p[], int size) :size{ size }, p{ new int[size] }
{
	memcpy(this->p, p, sizeof(int)* size);
	sort();
}

SortedArray SortedArray::operator + (SortedArray& op2)
{
	SortedArray arr(new int[size + op2.size], size + op2.size);
	for (int i = 0; i < size; ++i)
		arr.p[i] = p[i];
	for (int i = 0; i < op2.size; ++i)
		arr.p[size+ i] = op2.p[i];
	return arr;
}

SortedArray& SortedArray::operator = (const SortedArray& op2)
{
	if (this != &op2) {
		if (p)
			delete[] p;
		size = op2.size;
		p = new int[size];
		memcpy(p, op2.p, sizeof(int)*size);
		sort();
	}
	return *this;
}

void SortedArray::show()
{
	cout << "배열 출력: ";
	for (int i = 0; i < size; ++i)
		cout << p[i] << " ";
	cout << endl;
}