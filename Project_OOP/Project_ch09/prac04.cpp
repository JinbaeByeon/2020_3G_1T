// 추상클래스 LoopAdder를 상속받아 각각 while문과 do-while문으로 calculate()함수를 오버라이딩한 클래스 작성
#include <iostream>
using namespace std;

class LoopAdder { // 추상 클래스
	string name; // 루프의 이름
	int x, y, sum;
	void read(); // x, y 값을 읽어 들이는 함수
	void write(); // sum을 출력하는 함수
protected:
	LoopAdder(string name = "") { // 루프의 이름을 받는다. 초깃값은 ""
		this->name = name;
	}
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0; // 순수 가상 함수. 루프를 돌면서 합을 구하는 함수
public:
	void run(); // 연산을 진행하는 함수
};

void LoopAdder::read() { // x, y 입력
	cout << name << ":" << endl;
	cout << "처음 수에서 두번째 수까지 더합니다. 두 수를 입력하세요 >> ";
	cin >> x >> y;
}
void LoopAdder::write() { // 결과 sum 출력
	cout << x << "에서 " << y << "까지의 합 = " << sum << " 입니다" << endl;
}

void LoopAdder::run() {
	read(); // x, y를 읽는다.
	sum = calculate(); // 루프돌면서 계산한다.
	write(); // 결과 sum을 출력한다.
}

class WhileLoopAdder :public LoopAdder {
	int calculate() {	// while문을 이용하여 합을 구한다.
		int sum = 0, num = getX();

		while (num <= getY()) {
			sum += num++;
		}
		return sum;
	}
public:
	WhileLoopAdder(string name) :LoopAdder(name) {}
};

class DoWhileLoopAdder :public LoopAdder {
	int calculate() {	// do-while문을 이용하여 합을 구한다.
		int sum = 0, num = getX();

		do {
			sum += num++;
		} while (num <= getY());
		return sum;
	}
public:
	DoWhileLoopAdder(string name) :LoopAdder(name) {}
};

int main()
{
	WhileLoopAdder whileLoop("While Loop");
	DoWhileLoopAdder doWhileLoop("Do while Loop");

	whileLoop.run();
	doWhileLoop.run();
}