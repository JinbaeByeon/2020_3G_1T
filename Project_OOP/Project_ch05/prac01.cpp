// 정수를 입력받고 입력받은 값에 1 더해주고 출력하는 동작을 3번 반복하는 프로그램
#include <iostream>
using namespace std;

void increase(int&);

int main() {
	int i;
	cin >> i;
	cout << i << endl;
	increase(i);
	cout << i << endl;
	increase(i);
	cout << i << endl;
	return 0;
}

// n에 1을 더해준다.
void increase(int& n) { ++n; }