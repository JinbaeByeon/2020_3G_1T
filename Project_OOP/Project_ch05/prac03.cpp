// ������ ���� �� ������ ��ȯ�Ͽ� ���ϱ� �Լ��� ����ؼ� ȣ���� �� �ִ� ���α׷�
#include <iostream>
using namespace std;

class Accumulator {
	int value;
public:
	Accumulator(int value) { this->value = value; }
	Accumulator& add(int n);
	int get() { return value; }
};

int main()
{
	Accumulator acc(10);
	acc.add(5).add(6).add(7); // acc�� value ����� 28�� �ȴ�.
	cout << acc.get() << endl; // 28 ���
}

Accumulator& Accumulator::add(int n)
{
	value += n;	// value�� n�� ���Ѵ�.
	return *this;
}