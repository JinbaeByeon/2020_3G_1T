// 학번 이름 점수를 입력하면 그에 맞게 학생 정보를 출력하는 프로그램
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
	friend ostream& operator<<(ostream& os,const Student& student);
};

int main() {
	Student s;
	cin >> s;
	cout << s;
	return 0;
}

istream& operator>>(istream& is, Student& student)
{
	cout << "학번: ";
	is >>student.id;
	cout << "이름: ";
	is >> student.name;
	cout << "점수: ";
	is >> student.score;
	return is;
}
ostream& operator<<(ostream& os,const Student& student)
{
	os << student.name << "(" << student.id << ")의 점수=" << student.score << endl;
	return os;
}