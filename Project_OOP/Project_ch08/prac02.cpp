// BaseArray를 상속받아 Queue 방식으로 작동하는 MyQueue 클래스
#include <iostream>
#include "BaseArray.h"
using namespace std;

// 정수 데이터를 Queue 방식으로 처리
class MyQueue :public BaseArray {
private:
	// 현재 데이터의 길이(개수)
	int len = 0;
public:
	MyQueue(int n) : BaseArray(n) {};
	// 배열의 끝에 데이터 입력
	void enqueue(int n) {
		put(len++, n);
	}
	// 배열의 첫 번째 원소를 제거하고 그 값을 반환
	int dequeue() {
		int tmp = get(0);
		for (int i = 0; i < len - 1; ++i)
			put(i, get(i + 1));
		--len;
		return tmp;
	}

	// 적재 가능한 용량
	int capacity() {
		return getCapacity();
	}
	// 적재된 데이터 길이
	int length() {
		return len;
	}
};

int main() {
	MyQueue mQ(100);
	int n;
	cout << "큐에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n); // 큐에 삽입
	}
	cout << "큐의 용량:" << mQ.capacity() << ", 큐의 크기:" << mQ.length() << endl;
	cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' '; // 큐에서 제거하여 출력
	}
	cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;
}