<<<<<<< HEAD
// Point 클래스를 상속받는 ColorPoint 클래스
#include <iostream>
using namespace std;

// 2차원 좌표값을 가지는 Point 클래스
class Point {
protected:
	int x, y;
public:
	Point() :x(0), y(0) {}
	Point(int x,int y) :x(x), y(y) {}
	void setPoint(const int& x,const int& y) {
		this->x = x;
		this->y = y;
	}
	void show() const {
		cout << "(" << x << ", " << y << ")에 위치한 점입니다." << endl;
	}
};

// Point 클래스를 상속받아 2차원 좌표와 색깔 데이터를 갖는 ColorPoint 클래스
class ColorPoint : public Point {
	string color;
public:
	ColorPoint() :color{ "BLACK" } {}
	ColorPoint(const int& x,const int& y) : Point(x, y), color{ "BLACK" } {}
	void setColor(string color) {
		this->color = color;
	}
	void show() const{
		cout << color << "색으로 ";
		Point::show();
	}
};

int main() {
	ColorPoint zeroPoint; // BLACK에 (0, 0) 위치의 점
	zeroPoint.show(); // zeroPoint를 출력한다. 

	ColorPoint cp(5, 5);
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show(); // cp를 출력한다.
=======
// Point 클래스를 상속받는 ColorPoint 클래스
#include <iostream>
using namespace std;

// 2차원 좌표값을 가지는 Point 클래스
class Point {
protected:
	int x, y;
public:
	Point() :x(0), y(0) {}
	Point(int x,int y) :x(x), y(y) {}
	void setPoint(const int& x,const int& y) {
		this->x = x;
		this->y = y;
	}
	void show() const {
		cout << "(" << x << ", " << y << ")에 위치한 점입니다." << endl;
	}
};

// Point 클래스를 상속받아 2차원 좌표와 색깔 데이터를 갖는 ColorPoint 클래스
class ColorPoint : public Point {
	string color;
public:
	ColorPoint() :color{ "BLACK" } {}
	ColorPoint(const int& x,const int& y) : Point(x, y), color{ "BLACK" } {}
	void setColor(string color) {
		this->color = color;
	}
	void show() const{
		cout << color << "색으로 ";
		Point::show();
	}
};

int main() {
	ColorPoint zeroPoint; // BLACK에 (0, 0) 위치의 점
	zeroPoint.show(); // zeroPoint를 출력한다. 

	ColorPoint cp(5, 5);
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show(); // cp를 출력한다.
>>>>>>> 2174a0e0abf3e7dbefabad3f38dc2d9f05616872
}