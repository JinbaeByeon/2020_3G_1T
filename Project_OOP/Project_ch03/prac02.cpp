// 연, 월, 일을 가지는 달력 클래스
#include <iostream>
using namespace std;

class Calendar {
public:
	int year = 0;
	int month = 0;
	int day = 0;

	Calendar() {}
	Calendar(int y) :year{ y } {}
	Calendar(int y, int m, int d) :year{ y }, month{ m }, day{ d } {}
	~Calendar() { cout << "소멸자가 호출되었습니다." << endl; }
};