// string 클래스를 이용하여 빈칸을 포함하는 문자열을 입력받고 문자열에서 ‘a’가 몇 개 있는지를 출력하는 프로그램
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string text;	// 입력받을 문자열
	int nFound = 0;	// 문자의 개수

	cout << "문자열 입력>>";
	getline(cin,text,'\n');

	for (int i = 0; i < text.length(); ++i) {
		if (text.find('a', i) == -1) break;	// a를 못찾으면 반복문을 끝냄
		i = text.find('a', i);				// a를 찾은 인덱스 위치로 i를 이동
		++nFound;								// a를 찾았으므로 개수 증가
	}
	cout << "문자 a는 " << nFound << "개 있습니다." << endl;
} 