// prac03의 Calendar 클래스의 코드에 인라인 함수를 적절히 활용
// 선언부 안에서 함수 구현을 하면 자동으로 인라인 함수로 처리되지만
// 일단 게터와 세터는 구현부 선언부를 나누어서 인라인으로 처리했습니다.

#include <iostream>
using namespace std;

class Calendar {
	// 생성자 및 소멸자
public:
	Calendar() {}
	Calendar(int y) :year{ y } {}
	Calendar(int y, int m, int d) :year{ y }, month{ m }, day{ d } {}
	~Calendar() { cout << "소멸자가 호출되었습니다." << endl; }
	// 멤버변수
private:
	int year = 0;
	int month = 0;
	int day = 0;
	// getter 및 setter
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