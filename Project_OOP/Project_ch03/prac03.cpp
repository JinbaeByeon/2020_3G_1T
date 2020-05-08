// prac02���� �ۼ��� Calendar Ŭ������ �� ��� ������ ���� getter,setter�� �ۼ��ϰ�
// ���������ڷ� �� ����鿡 ���� ����/������� ����
#include <iostream>
using namespace std;

class Calendar {
	//������ �� �Ҹ���
public:
	Calendar() {}
	Calendar(int y) :year{ y } {}
	Calendar(int y, int m, int d) :year{ y }, month{ m }, day{ d } {}
	~Calendar() { cout << "�Ҹ��ڰ� ȣ��Ǿ����ϴ�." << endl; }
	//�������
private:
	int year = 0;
	int month = 0;
	int day = 0;
	// ���� �� ����
public:
	void setYear(int y) { year = y; }
	void setMonth(int m) { month = m; }
	void setDay(int d) { day = d; }

	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }

};