// 추상클래스 Shape를 상속받는 Oval, Rect, Triangular 클래스 작성
#include <iostream>
using namespace std;

// 추상 클래스 Shape
class Shape {
protected:
	string name; // 도형의 이름
	int width, height; // 도형이 내접하는 사각형의 너비와 높이
public:
	Shape(string n = "", int w = 0, int h = 0) { name = n; width = w; height = h; }
	virtual double getArea() = 0; // 순수 가상 함수. 넓이를 리턴
	string getName() { return name; } // 이름 리턴
};

// Shape을 상속
class Oval :public Shape {
public:
	Oval(string n, int w, int h) :Shape(n, w, h) {}
	double getArea() {
		return 3.14 * width * height;	// 타원의 넓이 = 긴 반지름 * 짧은 반지름 * 3.14(파이)
	}
};

// Shape을 상속
class Rect :public Shape {
public:
	Rect(string n, int w, int h) :Shape(n, w, h) {}
	double getArea() {
		return (double)width * height;	// 사각형의 넓이 = 가로 * 세로
	}

};

// Shape을 상속
class Triangular :public Shape {
public:
	Triangular(string n, int w, int h) :Shape(n, w, h) {}
	double getArea() {
		return (double)width * height / 2;	// 삼각형의 넓이 = 가로 * 세로 / 2
	}

};

int main() {
	Shape* p[3];
	p[0] = new Oval("빈대떡", 10, 20);
	p[1] = new Rect("찰떡", 30, 40);
	p[2] = new Triangular("토스트", 30, 40);
	for (int i = 0; i < 3; i++)
		cout << p[i]->getName() << " 넓이는 " << p[i]->getArea() << endl;

	for (int i = 0; i < 3; i++) delete p[i];
}