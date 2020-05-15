/* int 배열과 double 배열을 서로 변환시켜주는 ArrayUtility 클래스*/

#include <iostream>
using namespace std;

class ArrayUtility {
public:
// int 배열을 double 배열로 변환
static void intToDouble(int source[], double dest[], int size);
// double 배열을 int 배열로 변환
static void doubleToInt(double source[], int dest[], int size);
};

int main() {
	int x[] = { 1,2,3,4,5 };
	double y[5];
	double z[] = { 9.9, 8.8, 7.7, 6.6, 5.6 };

	ArrayUtility::intToDouble(x, y, 5); // x[] -> y[]
	for (int i = 0; i < 5; i++) cout << y[i] << ' ';
	cout << endl;

	ArrayUtility::doubleToInt(z, x, 5); // z[] -> x[]
	for (int i = 0; i < 5; i++) cout << x[i] << ' ';
	cout << endl;
}

void ArrayUtility::intToDouble(int source[], double dest[], int size)
{
	for (int i = 0; i < size; ++i)
		dest[i] = (double)source[i];
}
void ArrayUtility::doubleToInt(double source[], int dest[], int size)
{
	for (int i = 0; i < size; ++i)
		dest[i] = (int)source[i];
}