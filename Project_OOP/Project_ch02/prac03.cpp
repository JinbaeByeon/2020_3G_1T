// 키보드로부터 2개의 정수를 입력받아 큰 수를 화면에 출력하는 프로그램

#include <iostream>

using namespace std;

int main()
{
	int num1 = 0, num2 = 0;

	cout << "두 수를 입력하라>>";
	cin >> num1 >> num2;

	if (num1 > num2)	// num1이 num2 보다 클 경우 num1을 출력하고
		cout << "큰 수 = " << num1;
	else				// 반대의 경우 num2를 출력함
		cout << "큰 수 = " << num2;
}