// String 클래스를 이용하여 사용자가 입력한 영문 한 줄을 문자열로 입력받고 거꾸로 출력하는 프로그램
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string text;	// 입력받을 문자열
	
	cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다)" << endl;
	while (true) {
		cout << ">>";
		getline(cin, text, '\n');	// 개행 문자가 나올 때까지 입력가능

		if (text == "exit") break;	//exit를 입력하면 반복문 종료
		
		// 거꾸로 출력
		for (int i = 0; i < text.length(); ++i)
			cout << text.at(text.length() - i - 1);
		cout << endl;
	}

}