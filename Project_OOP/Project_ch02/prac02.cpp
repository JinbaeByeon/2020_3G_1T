/* 1~9 사이의 행 수를 입력받고 1부터 오름차순으로 n행에 n개씩 숫자를 이어서 나열
(각 숫자는 띄어쓰기한다, 1~9 사이의 수가 입력되지 않으면 다시 입력)
예)	1
	2 3
	4 5 6
	7 8 9 10
	11 12 13 14 15
*/
#include <iostream>
using namespace std;

int main()
{
	int num_line = 0;	// 행의 수
	int num_cur = 0;	// 현재 숫자

	while (num_line < 1 || num_line >9) {
		cout << "몇 행입니까? (1~9 입력) ";
		cin >> num_line;
	}
	for (int i = 1; i <= num_line; ++i) {

		for (int j = 0; j < i; ++j)
			cout << ++num_cur << " ";

		cout << endl;
	}
}