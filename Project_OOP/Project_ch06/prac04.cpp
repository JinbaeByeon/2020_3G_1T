/* int �迭�� double �迭�� ���� ��ȯ�����ִ� ArrayUtility Ŭ����*/

#include <iostream>
using namespace std;

class ArrayUtility {
public:
// int �迭�� double �迭�� ��ȯ
static void intToDouble(int source[], double dest[], int size);
// double �迭�� int �迭�� ��ȯ
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