/* 문자열을 두 개 입력 받고 두 개의 문자열이 동일한지 검사하는 프로그램 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string password1, password2;
	
	cout << "새 암호를 입력하세요>>";
	cin >> password1;

	cout << "새 암호를 다시 한 번 입력하세요>>";
	cin >> password2;

	if (password1 == password2) cout << "같습니다." << endl;	// password1과 password2이 같으면 "같습니다." 출력
	else cout << "같지 않습니다." << endl;		// password1과 password2가 같지 않으면 "같지 않습니다." 출력
}