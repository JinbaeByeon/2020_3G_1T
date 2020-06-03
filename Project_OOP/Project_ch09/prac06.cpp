#include <iostream>
using namespace std;

class Shape {
protected:
	string name; // ������ �̸�
	int width, height; // ������ �����ϴ� �簢���� �ʺ�� ����
public:
	Shape(string n = "", int w = 0, int h = 0) { name = n; width = w; height = h; }
	virtual double getArea() = 0; // ���� ���� �Լ�. ���̸� ����
	string getName() { return name; } // �̸� ����
};

class Oval :public Shape {
public:
	Oval(string n, int w, int h) :Shape(n, w, h) {}
	double getArea() {
		return 3.14 * width * height;
	}
};

class Rect :public Shape {
public:
	Rect(string n, int w, int h) :Shape(n, w, h) {}
	double getArea() {
		return (double)width * height;
	}

};

class Triangular :public Shape {
public:
	Triangular(string n, int w, int h) :Shape(n, w, h) {}
	double getArea() {
		return (double)width * height / 2;
	}

};

int main() {
	Shape* p[3];
	p[0] = new Oval("��붱", 10, 20);
	p[1] = new Rect("����", 30, 40);
	p[2] = new Triangular("�佺Ʈ", 30, 40);
	for (int i = 0; i < 3; i++)
		cout << p[i]->getName() << " ���̴� " << p[i]->getArea() << endl;

	for (int i = 0; i < 3; i++) delete p[i];
}