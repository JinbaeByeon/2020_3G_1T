/* 디폴트 매개 변수를 가진 하나의 minMax() 함수를 작성*/

#include <iostream>
using namespace std;

int minMax(int[], int, bool isMin = false);	// 세 번째 인자가 true이면 배열의 최소값을 반환하는 함수

int main()
{
	int a[] = { 1,2,3,4,5 };;
	int aMax = minMax(a, 5); // 배열 a의 정수 중 최대값 리턴
	int aMin = minMax(a, 5, true); // 배열 a의 정수 중 최소값 리턴
	cout << aMax << endl; // 5 출력 
	cout << aMin << endl; // 1 출력
}

int minMax(int arr[], int size, bool isMin)
{
	int idx = 0;
	// bool 값에 따라서 최대값 혹은 최소값 인덱스를 구한다
	for (int i = 0; i < size; ++i) {
		if ((isMin && arr[i] < arr[idx]) || (!isMin && arr[i] > arr[idx]))	
			idx = i;		
	}
	return arr[idx];
}