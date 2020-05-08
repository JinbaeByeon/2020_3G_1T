// 이름과 반지름을 속성으로 가진 Circle 클래스와 이들을 배열로 관리하는 CircleManager 클래스
#include <iostream>
using namespace std;

#define PI 3.14

class Circle {
	int radius; // 원의 반지름 값
	string name; // 원의 이름
public:
	void setCircle(string name, int radius); // 이름과 반지름 설정
	double getArea();
	string getName();
};

class CircleManager {
	Circle* p; // Circle 배열에 대한 포인터
	int size = 0; // 배열의 크기
public:
	CircleManager(int size); // size 크기의 배열을 동적 생성. 사용자로부터 입력 완료
	virtual ~CircleManager();
	void searchByName(); // 사용자로부터 원의 이름을 입력받아 면적 출력
	void searchByArea(); // 사용자로부터 면적을 입력받아 면적보다 큰 원의 이름 출력
};

int main()
{
	int size{};	// 원의 개수
	cout << "원의 개수 >> ";
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
		cout << "원 " << i + 1 << "의 이름과 반지름 >> ";
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
	cout << "검색하고자 하는 원의 이름 >> ";
	cin >> name;
	for (int i = 0; i < size; ++i)
		if (p[i].getName() == name)
			cout << name << "의 면적은 " << p[i].getArea();
	cout << endl;
}

void CircleManager::searchByArea()
{
	int area{};
	cout << "최소 면적을 정수로 입력하세요 >> ";
	cin >> area;
	cout << area << "보다 큰 원을 검색합니다." << endl;

	for (int i = 0; i < size; ++i)
		if (p[i].getArea() > area) {
			cout << p[i].getName() << "의 면적은 " << p[i].getArea();
			if (i < size - 1) cout << ", ";	// 마지막 원을 제외하고 사이에 , 를 추가
		}
}