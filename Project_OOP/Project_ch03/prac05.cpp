// �־��� �簢���� �����ϴ� Ÿ���� �߻�ȭ�� OvalŬ����
// ����ο� �����η� ������ �ۼ���

#include <iostream>

using namespace std;

class Oval {
// ������ �� �Ҹ���
public:
	Oval() :Oval(1, 1) {};
	Oval(int, int);
	~Oval();
// �������
private:
	int width;
	int height;
// ��Ÿ �����Լ�
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
	cout << "Oval �Ҹ� - " << "Width: " << width << ", Height: " << height << endl;
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

