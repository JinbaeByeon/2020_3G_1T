// BaseArray�� ��ӹ޾� Queue ������� �۵��ϴ� MyQueue Ŭ����
#include <iostream>
#include "BaseArray.h"
using namespace std;

// ���� �����͸� Queue ������� ó��
class MyQueue :public BaseArray {
private:
	// ���� �������� ����(����)
	int len = 0;
public:
	MyQueue(int n) : BaseArray(n) {};
	// �迭�� ���� ������ �Է�
	void enqueue(int n) {
		put(len++, n);
	}
	// �迭�� ù ��° ���Ҹ� �����ϰ� �� ���� ��ȯ
	int dequeue() {
		int tmp = get(0);
		for (int i = 0; i < len - 1; ++i)
			put(i, get(i + 1));
		--len;
		return tmp;
	}

	// ���� ������ �뷮
	int capacity() {
		return getCapacity();
	}
	// ����� ������ ����
	int length() {
		return len;
	}
};

int main() {
	MyQueue mQ(100);
	int n;
	cout << "ť�� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n); // ť�� ����
	}
	cout << "ť�� �뷮:" << mQ.capacity() << ", ť�� ũ��:" << mQ.length() << endl;
	cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' '; // ť���� �����Ͽ� ���
	}
	cout << endl << "ť�� ���� ũ�� : " << mQ.length() << endl;
}