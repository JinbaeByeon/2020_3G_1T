#include <iostream>
#include <fstream>
using namespace std;
#define 읽기
#define 쓰기
int main() {
	char name[10], dept[20];
	int sid;

#ifdef 쓰기
	// 키보드로부터 읽기
	cout << "이름>>";
	cin >> name; // 키보드에서 이름 입력 받음
	cout << "학번>>";
	cin >> sid; // 키보드에서 학번 입력 받음
	cout << "학과>>";
	cin >> dept; // 키보드에서 학과 입력 받음
	// 파일 열기. student.txt 파일을 열고, 출력 스트림 생성
	ofstream fout("student.txt",ios::out | ios::app);
	if (!fout) { // 열기 실패 검사
		cout << "student.txt 파일을 열 수 없다";
		return 0;
	}

	// 파일 쓰기
	fout << name << endl; // name 쓰기
	fout << sid << endl; // sid 쓰기
	fout << dept << endl; // dept 쓰기

	fout.close(); // 파일 닫기
#endif

#ifdef 읽기
	ifstream fin; 	// 스트림 객체 생성 및 파일 열기
	fin.open("student.txt");
	if (!fin) {  // 파일 열기 실패 확인
		cout << "파일을 열 수 없다";
		return 0;
	}
	while (true) {
		// 파일 읽기
		fin >> name; // 파일에 있는 문자열을 읽어서 name 배열에 저장
		fin >> sid; // 정수를 읽어서 sid 정수형 변수에 저장
		fin >> dept; // 문자열을 읽고 dept 배열에 저장
		if (fin.eof())break;
		// 읽은 텍스트를 화면에 출력
		cout << name << endl;
		cout << sid << endl;
		cout << dept << endl;
	}
	fin.close(); // 파일 읽기를 마치고 파일을 닫는다.
#endif
}