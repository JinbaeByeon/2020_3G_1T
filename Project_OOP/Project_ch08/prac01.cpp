<<<<<<< HEAD
// Point Ŭ������ ��ӹ޴� ColorPoint Ŭ����
#include <iostream>
using namespace std;

// 2���� ��ǥ���� ������ Point Ŭ����
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
		cout << "(" << x << ", " << y << ")�� ��ġ�� ���Դϴ�." << endl;
	}
};

// Point Ŭ������ ��ӹ޾� 2���� ��ǥ�� ���� �����͸� ���� ColorPoint Ŭ����
class ColorPoint : public Point {
	string color;
public:
	ColorPoint() :color{ "BLACK" } {}
	ColorPoint(const int& x,const int& y) : Point(x, y), color{ "BLACK" } {}
	void setColor(string color) {
		this->color = color;
	}
	void show() const{
		cout << color << "������ ";
		Point::show();
	}
};

int main() {
	ColorPoint zeroPoint; // BLACK�� (0, 0) ��ġ�� ��
	zeroPoint.show(); // zeroPoint�� ����Ѵ�. 

	ColorPoint cp(5, 5);
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show(); // cp�� ����Ѵ�.
=======
// Point Ŭ������ ��ӹ޴� ColorPoint Ŭ����
#include <iostream>
using namespace std;

// 2���� ��ǥ���� ������ Point Ŭ����
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
		cout << "(" << x << ", " << y << ")�� ��ġ�� ���Դϴ�." << endl;
	}
};

// Point Ŭ������ ��ӹ޾� 2���� ��ǥ�� ���� �����͸� ���� ColorPoint Ŭ����
class ColorPoint : public Point {
	string color;
public:
	ColorPoint() :color{ "BLACK" } {}
	ColorPoint(const int& x,const int& y) : Point(x, y), color{ "BLACK" } {}
	void setColor(string color) {
		this->color = color;
	}
	void show() const{
		cout << color << "������ ";
		Point::show();
	}
};

int main() {
	ColorPoint zeroPoint; // BLACK�� (0, 0) ��ġ�� ��
	zeroPoint.show(); // zeroPoint�� ����Ѵ�. 

	ColorPoint cp(5, 5);
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show(); // cp�� ����Ѵ�.
>>>>>>> 2174a0e0abf3e7dbefabad3f38dc2d9f05616872
}