// BaseArray Ŭ������ ��ӹ޾� �������� �۵��ϴ� MyStack Ŭ����
#include <iostream>
#include "BaseArray.h"
using namespace std;

// ���� �����͸� ���� �������� ó���ϴ� Ŭ����
class MyStack :public BaseArray {
private:
	// ���� ����ִ� �������� ����(����)
	int len = 0;
public:
	MyStack(int n) : BaseArray(n) {};

	// �迭�� ���� n�� �ִ´�
	void push(int n) {
		put(len++, n);
	}
	// �迭�� ���� �ִ� ���� ������ ���� ���� ��ȯ
	int pop() {
		int tmp = get(len - 1);
		put(--len, NULL);
		return tmp;
	}

	// �� �뷮
	int capacity() {
		return getCapacity();
	}
	// ���� ���� �������� ����(����)
	int length() {
		return len;
	}
};

int main() {
	MyStack mStack(100);
	int n;
	cout << "���ÿ� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n); // ���ÿ� Ǫ��
	}
	cout << "���� �뷮:" << mStack.capacity() << ", ���� ũ��:" << mStack.length() << endl;
	cout << "������ ��� ���Ҹ� ���Ͽ� ����Ѵ�>> ";
	while (mStack.length() != 0) {
		cout << mStack.pop() << ' '; // ���ÿ��� ��
	}
	cout << endl << "������ ���� ũ�� : " << mStack.length() << endl;
}
