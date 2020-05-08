// prac02에서 작성한 Calendar 클래스의 각 멤버 변수에 대해 getter,setter를 작성하고
// 접근지시자로 각 멤버들에 대한 공개/비공개를 구분
#include <iostream>
using namespace std;

class Calendar {
	//생성자 및 소멸자
public:
	Calendar() {}
	Calendar(int y) :year{ y } {}
	Calendar(int y, int m, int d) :year{ y }, month{ m }, day{ d } {}
	~Calendar() { cout << "소멸자가 호출되었습니다." << endl; }
	//멤버변수
private:
	int year = 0;
	int month = 0;
	int day = 0;
	// 게터 및 세터
public:
	void setYear(int y) { year = y; }
	void setMonth(int m) { month = m; }
	void setDay(int d) { day = d; }

	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }

};