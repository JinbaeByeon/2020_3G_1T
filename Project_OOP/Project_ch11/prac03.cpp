// 3명의 학생 정보를 입력하면 포맷에 맞게 정보를 출력하는 프로그램
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student {
	int id;
	string name;
	double score;
public:
	// Student 클래스 추출 연산자
	friend istream& operator>>(istream& is, Student& student);
	// Student 클래스 삽입 연산자
	friend ostream& operator<<(ostream& os, const Student& student);
};

int main() {
	Student s[3];
	for (int i = 0; i < 3; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < 3; i++) {
		cout << s[i];
	}
	return 0;
}


istream& operator>>(istream& is, Student& student)
{
	cout << "학번: ";
	is >> student.id;
	cout << "이름: ";
	is >> student.name;
	cout << "점수: ";
	is >> student.score;
	return is;
}
ostream& operator<<(ostream& os, const Student& student)
{
	// 실수 자료형에 대해 소수점 둘째 자리까지 표기하도록 포맷 지정
	os.setf(ios::fixed);
	os << setprecision(2);

	os << setw(8) << student.name << "    ";
	os << setw(3) << setfill('0') << student.id;
	os << setw(8) << setfill(' ') << student.score << endl;
	return os;
}