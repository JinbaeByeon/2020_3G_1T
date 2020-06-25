// �й� �̸� ������ �Է��ϸ� �׿� �°� �л� ������ ����ϴ� ���α׷�
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student {
	int id;
	string name;
	double score;
public:
	// Student Ŭ���� ���� ������
	friend istream& operator>>(istream& is, Student& student);
	// Student Ŭ���� ���� ������
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
	cout << "�й�: ";
	is >>student.id;
	cout << "�̸�: ";
	is >> student.name;
	cout << "����: ";
	is >> student.score;
	return is;
}
ostream& operator<<(ostream& os,const Student& student)
{
	os << student.name << "(" << student.id << ")�� ����=" << student.score << endl;
	return os;
}