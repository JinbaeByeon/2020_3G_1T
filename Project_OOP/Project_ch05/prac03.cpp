// 정수를 더한 뒤 참조를 반환하여 더하기 함수를 계속해서 호출할 수 있는 프로그램
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
	acc.add(5).add(6).add(7); // acc의 value 멤버가 28이 된다.
	cout << acc.get() << endl; // 28 출력
}

Accumulator& Accumulator::add(int n)
{
	value += n;	// value에 n을 더한다.
	return *this;
}