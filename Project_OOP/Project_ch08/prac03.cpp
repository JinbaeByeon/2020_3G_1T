// BaseArray 클래스를 상속받아 스택으로 작동하는 MyStack 클래스
#include <iostream>
#include "BaseArray.h"
using namespace std;

// 정수 데이터를 스택 형식으로 처리하는 클래스
class MyStack :public BaseArray {
private:
	// 현재 들어있는 데이터의 길이(개수)
	int len = 0;
public:
	MyStack(int n) : BaseArray(n) {};

	// 배열의 끝에 n을 넣는다
	void push(int n) {
		put(len++, n);
	}
	// 배열의 끝에 있는 값을 꺼내고 꺼낸 값을 반환
	int pop() {
		int tmp = get(len - 1);
		put(--len, NULL);
		return tmp;
	}

	// 총 용량
	int capacity() {
		return getCapacity();
	}
	// 현재 쌓인 데이터의 길이(개수)
	int length() {
		return len;
	}
};

int main() {
	MyStack mStack(100);
	int n;
	cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n); // 스택에 푸시
	}
	cout << "스택 용량:" << mStack.capacity() << ", 스택 크기:" << mStack.length() << endl;
	cout << "스택의 모든 원소를 팝하여 출력한다>> ";
	while (mStack.length() != 0) {
		cout << mStack.pop() << ' '; // 스택에서 팝
	}
	cout << endl << "스택의 현재 크기 : " << mStack.length() << endl;
}
