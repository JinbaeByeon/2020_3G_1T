/*
문자열을 하나 입력받고 문자열의 부분 문자열을 길이를 1씩 늘리며 출력하는 프로그램 
예)	hello를 입력받으면 다음과 같이 출력된다.
	h
	he
	hel
	hell
	hello
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s_input, s_output;					// 입력받는 문차열과 출력하는 문자열을 구분

	cout << "문자열 입력>>";
	cin >> s_input;

	int cnt = 0;								// 입력받은 문자열의 첫번째 문자부터 순서대로 받기 위한 카운트
	while (cnt < s_input.length()) {			// 입력받은 문자열의 크기만큼 받아오면 반복문을 끝낸다.
		s_output.push_back(s_input.at(cnt++));	// 입력받은 문자열의 현재 cnt 위치에 해당하는 값을 출력 문자열의 맨 뒤에 추가한다.
		cout << s_output << endl;
	}
}