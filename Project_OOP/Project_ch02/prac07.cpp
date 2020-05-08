/* "yes"가 입력될 때까지 종료하지 않는 프로그램 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s_input;

	while (s_input.compare("yes")) {	// "yes"를 입력받을 경우 반복문 종료
		cout << "종료하고 싶으면 yes를 입력하세요>>";
		getline(cin, s_input, '\n');	// 개행문자를 입력받을 때까지의 문자열을 s_input에 받는다.
	}
	cout << "종료합니다..." << endl;
}