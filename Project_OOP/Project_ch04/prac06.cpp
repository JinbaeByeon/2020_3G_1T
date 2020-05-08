// �̸��� �������� �Ӽ����� ���� Circle Ŭ������ �̵��� �迭�� �����ϴ� CircleManager Ŭ����
#include <iostream>
using namespace std;

#define PI 3.14

class Circle {
	int radius; // ���� ������ ��
	string name; // ���� �̸�
public:
	void setCircle(string name, int radius); // �̸��� ������ ����
	double getArea();
	string getName();
};

class CircleManager {
	Circle* p; // Circle �迭�� ���� ������
	int size = 0; // �迭�� ũ��
public:
	CircleManager(int size); // size ũ���� �迭�� ���� ����. ����ڷκ��� �Է� �Ϸ�
	virtual ~CircleManager();
	void searchByName(); // ����ڷκ��� ���� �̸��� �Է¹޾� ���� ���
	void searchByArea(); // ����ڷκ��� ������ �Է¹޾� �������� ū ���� �̸� ���
};

int main()
{
	int size{};	// ���� ����
	cout << "���� ���� >> ";
	cin >> size;
	CircleManager cManager(size);

	cManager.searchByName();
	cManager.searchByArea();
}

void Circle::setCircle(string name,int radius)
{
	this->name = name;
	this->radius = radius;
}

double Circle::getArea()
{
	return PI * radius * radius;
}

string Circle::getName()
{
	return name;
}

CircleManager::CircleManager(int size)
{
	this->size = size;
	p = new Circle[size];
	int rad;
	string name;
	for (int i = 0; i < size; ++i) {
		cout << "�� " << i + 1 << "�� �̸��� ������ >> ";
		cin >> name >> rad;
		p[i].setCircle(name, rad);
	}
}

CircleManager::~CircleManager()
{
	delete[] p;
}

void CircleManager::searchByName()
{
	string name{};
	cout << "�˻��ϰ��� �ϴ� ���� �̸� >> ";
	cin >> name;
	for (int i = 0; i < size; ++i)
		if (p[i].getName() == name)
			cout << name << "�� ������ " << p[i].getArea();
	cout << endl;
}

void CircleManager::searchByArea()
{
	int area{};
	cout << "�ּ� ������ ������ �Է��ϼ��� >> ";
	cin >> area;
	cout << area << "���� ū ���� �˻��մϴ�." << endl;

	for (int i = 0; i < size; ++i)
		if (p[i].getArea() > area) {
			cout << p[i].getName() << "�� ������ " << p[i].getArea();
			if (i < size - 1) cout << ", ";	// ������ ���� �����ϰ� ���̿� , �� �߰�
		}
}