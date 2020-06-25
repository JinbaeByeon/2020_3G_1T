// cin, cout 객체와 istream, ostream 멤버 함수를 사용한 입출력 프로그램
#include <iostream>
using namespace std;

int main()
{
	cout.write("how many lines?",sizeof("how many lines?"));
	char line = cin.get();
	cin.ignore(1);	// 스트림 버퍼에 남은 '\n'를 지움

	char str[9][80]{};	// 0~9 사이의 행, 한 행은 80 바이트 이하
	for (int i = 0; i < atoi(&line); ++i) {
		cout.write("input a line:",sizeof("input a line:"));
		cin.getline(str[i], 80);
	}

	for (int i = 0; i < atoi(&line); ++i) {
		cout.write(str[i], sizeof(str[i]));
		cout.put('\n');
	}
}