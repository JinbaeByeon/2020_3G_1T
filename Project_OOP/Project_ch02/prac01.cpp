/*
반복문을 사용하여
*****
****
***
**
*
형태를 출력하는 프로그램
*/
#include<iostream>
using namespace std;

int main()
{
	for (int i = 5; i > 0; i--) {		// 행의 별 개수
		for (int j = 1; j <= i; j++) {	// 현재 행 위치
			cout << "*";
		}
		cout << endl;
	}
}