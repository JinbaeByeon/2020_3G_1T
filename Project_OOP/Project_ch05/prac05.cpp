// larger() 함수와 largest() 함수를 이용해 가장 반지름이 큰 원을 구하는 프로그램
#include <iostream>
using namespace std;

class Circle {
private:
	int radius;
public:
	Circle() :radius{ 1 } {}					// 생성시 입력값이 없으면 반지름 1
	Circle(int r) :radius{ r } {}
	double getRadius() { return radius; }
	void setRadius(int rad) { radius = rad; }
};


bool larger(Circle& c1, Circle& c2);
Circle& largest(Circle arr[], int size);

int main()
{
	Circle arr[5] = { Circle(5), Circle(100), Circle(), Circle(15), Circle(10) };
	Circle& c = largest(arr, 5);
	cout << c.getRadius() << endl;
	return 0;
}

// c1.r >= c2.r
bool larger(Circle& c1, Circle& c2)
{
	return c1.getRadius() >= c2.getRadius();
}

Circle& largest(Circle arr[], int size)
{
	Circle c_largest = arr[0];
	for (int i = 1; i < size; ++i)
		if (larger(arr[i],c_largest))
			c_largest.setRadius(arr[i].getRadius());
	return c_largest;
}
