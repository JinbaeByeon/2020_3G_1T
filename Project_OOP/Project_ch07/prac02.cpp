/* ���� �迭�� �׻� ���� ������ �����ϴ� SortedArray Ŭ����*/
#include <iostream>

using namespace std;

class SortedArray {
	int size; // ���� �迭�� ũ��
	int* p; // ���� �迭�� ���� ������
	void sort(); // ���� �迭�� ������������ ����
public:
	SortedArray() : p{ NULL }, size{ 0 } {} // p�� NULL�� size�� 0���� �ʱ�ȭ
	SortedArray(SortedArray& src);	// ���� ������
	SortedArray(int p[], int size); // ������. ���� �迭�� ũ�⸦ ���޹���
	~SortedArray() { // �Ҹ���
		if(p)
			delete[] p;
	}
	SortedArray operator + (SortedArray& op2);
	SortedArray& operator = (const SortedArray& op2); // ���� �迭�� op2 �迭�� ����
	void show(); // �迭�� ���� ���
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
	cout << "�迭 ���: ";
	for (int i = 0; i < size; ++i)
		cout << p[i] << " ";
	cout << endl;
}