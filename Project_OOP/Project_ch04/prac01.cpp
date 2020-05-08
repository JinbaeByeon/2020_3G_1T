// 정수 공간 5개를 배열로 동적 할당받고 정수를 5개 입력받아 평균을 구하고 출력하는 프로그램

#include <iostream>
using namespace std;

int main()
{
	int* n = new int[5];	// 정수 5개 동적할당
	if (!n) return;
	double average{0};		// 평균을 입력받을 실수 값

	cout << "정수 5개 입력>>";
	for (int i = 0; i < 5; ++i) {
		cin >> n[i];
		average += n[i];
	}
	average /= 5;
	cout << "평균 " << average << endl;

	delete[] n;
}