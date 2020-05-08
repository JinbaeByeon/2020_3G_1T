// prac03�� Calendar Ŭ������ �ڵ忡 �ζ��� �Լ��� ������ Ȱ��
// ����� �ȿ��� �Լ� ������ �ϸ� �ڵ����� �ζ��� �Լ��� ó��������
// �ϴ� ���Ϳ� ���ʹ� ������ ����θ� ����� �ζ������� ó���߽��ϴ�.

#include <iostream>
using namespace std;

class Calendar {
	// ������ �� �Ҹ���
public:
	Calendar() {}
	Calendar(int y) :year{ y } {}
	Calendar(int y, int m, int d) :year{ y }, month{ m }, day{ d } {}
	~Calendar() { cout << "�Ҹ��ڰ� ȣ��Ǿ����ϴ�." << endl; }
	// �������
private:
	int year = 0;
	int month = 0;
	int day = 0;
	// getter �� setter
public:
	void setYear(int y);
	void setMonth(int m);
	void setDay(int d);

	int getYear();
	int getMonth();
	int getDay();

};

inline void Calendar::setYear(int y) { year = y; }
inline void Calendar::setMonth(int m) { month = m; }
inline void Calendar::setDay(int d) { day = d; }

inline int Calendar::getYear() { return year; }
inline int Calendar::getMonth() { return month; }
inline int Calendar::getDay() { return day; }