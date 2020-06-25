// 3���� �л� ������ �Է��ϸ� ���˿� �°� ������ ����ϴ� ���α׷�
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
	cout << "�й�: ";
	is >> student.id;
	cout << "�̸�: ";
	is >> student.name;
	cout << "����: ";
	is >> student.score;
	return is;
}
ostream& operator<<(ostream& os, const Student& student)
{
	// �Ǽ� �ڷ����� ���� �Ҽ��� ��° �ڸ����� ǥ���ϵ��� ���� ����
	os.setf(ios::fixed);
	os << setprecision(2);

	os << setw(8) << student.name << "    ";
	os << setw(3) << setfill('0') << student.id;
	os << setw(8) << setfill(' ') << student.score << endl;
	return os;
}