// 5개의 실수를 입력받아 두번째로 작은 수를 화면에 출력하는 프로그램

#include <iostream>
using namespace std;

int main()
{
	float num[5] = {};	// 입력받을 5개의 실수 배열
	// 제일 작은 수와 두 번째로 작은 수를 입력받을 배열을 실수 최대값으로 선언
	float min[2] = { FLT_MAX,FLT_MAX };	

	cout << "5개의 실수를 입력하세요>>";
	for (int i = 0; i < 5; ++i)
		cin >> num[i];

	// min 배열의 0번 인덱스에 5개의 실수 중 최소값을 넣는다.
	for (int i = 0; i < 5; ++i) 
		if (min[0] > num[i]) min[0] = num[i];	

	//min 배열의 1번 인덱스에 '5개의 실수 중 최소값을 제외한 제일 작은 수'(두 번째로 작은 수)를 넣는다.
	for (int i = 0; i < 5; ++i)
		if (min[1] > num[i] && num[i] != min[0]) min[1] = num[i];

	cout << "두 번째로 작은 수 = " << min[1];
}