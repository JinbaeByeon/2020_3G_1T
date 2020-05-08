#include <iostream>
#include <fstream>
using namespace std;

void save(string);		// save 선언

int main()
{
	cout << "이 파일을 하드디스크에 저장하도록 하자" << endl;
	
	save("소스_1주2일차 예재.cpp");		// 하드디스크에 저장하는 함수
}

void save(string s)			// save 정의
{
	// 내용을 읽을 파일을 연다 -> "소스.cpp"
	ifstream in(s);

	// 읽은 내용을 저장할 파일을 연다 -> 저장할 파일이름을 "강의저장.txt" 라고 하자
	ofstream out("강의저장.txt", ios::app);

	// 소스.cpp의 모든 내용을 읽어 강의저장.txt 파일에 기록한다.
	int c;
	while ((c = in.get()) != EOF)
		out << (char)c;

	cout << "소스.cpp를 강의저장.txt에 저장하였습니다" << endl;
}
