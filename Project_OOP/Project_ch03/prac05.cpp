// 주어진 사각형에 내접하는 타원을 추상화한 Oval클래스
// 선언부와 구현부로 나누어 작성함

#include <iostream>

using namespace std;

class Oval {
// 생성자 및 소멸자
public:
	Oval() :Oval(1, 1) {};
	Oval(int, int);
	~Oval();
// 멤버변수
private:
	int width;
	int height;
// 기타 구현함수
public:
	int getWidth();
	int getHeight();
	void set(int, int);
	void show();
};

int main()
{
	Oval a, b(3, 4);
	a.set(10, 20);
	a.show();
	cout << b.getWidth() << ", " << b.getHeight() << endl;
}

Oval::Oval(int w, int h) : width{ w }, height{ h }{};

Oval::~Oval()
{
	cout << "Oval 소멸 - " << "Width: " << width << ", Height: " << height << endl;
}


inline int Oval::getWidth()
{
	return width;
}
inline int Oval::getHeight()
{
	return height;
}

void Oval::set(int w, int h)
{
	width = w; height = h;
}

void Oval::show()
{
	cout << "Width: " << width << ", Height: " << height << endl;
}

