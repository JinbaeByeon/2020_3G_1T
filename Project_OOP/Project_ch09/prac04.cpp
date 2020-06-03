// �߻�Ŭ���� LoopAdder�� ��ӹ޾� ���� while���� do-while������ calculate()�Լ��� �������̵��� Ŭ���� �ۼ�
#include <iostream>
using namespace std;

class LoopAdder { // �߻� Ŭ����
	string name; // ������ �̸�
	int x, y, sum;
	void read(); // x, y ���� �о� ���̴� �Լ�
	void write(); // sum�� ����ϴ� �Լ�
protected:
	LoopAdder(string name = "") { // ������ �̸��� �޴´�. �ʱ갪�� ""
		this->name = name;
	}
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0; // ���� ���� �Լ�. ������ ���鼭 ���� ���ϴ� �Լ�
public:
	void run(); // ������ �����ϴ� �Լ�
};

void LoopAdder::read() { // x, y �Է�
	cout << name << ":" << endl;
	cout << "ó�� ������ �ι�° ������ ���մϴ�. �� ���� �Է��ϼ��� >> ";
	cin >> x >> y;
}
void LoopAdder::write() { // ��� sum ���
	cout << x << "���� " << y << "������ �� = " << sum << " �Դϴ�" << endl;
}

void LoopAdder::run() {
	read(); // x, y�� �д´�.
	sum = calculate(); // �������鼭 ����Ѵ�.
	write(); // ��� sum�� ����Ѵ�.
}

class WhileLoopAdder :public LoopAdder {
	int calculate() {	// while���� �̿��Ͽ� ���� ���Ѵ�.
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
	int calculate() {	// do-while���� �̿��Ͽ� ���� ���Ѵ�.
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