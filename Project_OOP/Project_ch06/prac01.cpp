/* minMax() 함수를 중복 작성*/

#include <iostream>
using namespace std;

int minMax(int[], int);			// 배열의 최대값을 반환하는 함수
int minMax(int[], int, bool);	// 세 번째 인자가 true이면 배열의 최소값을 반환하는 함수

int main()
{
	int a[] = { 1,2,3,4,5 };;
	int aMax = minMax(a, 5); // 배열 a의 정수 중 최대값 리턴
	int aMin = minMax(a, 5, true); // 배열 a의 정수 중 최소값 리턴
	cout << aMax << endl; // 5 출력 
	cout << aMin << endl; // 1 출력
}

int minMax(int arr[], int size)
{
	int max = arr[0];
	for (int i = 0; i < size; ++i)
		max = arr[i] > max ? arr[i] : max;		// 배열의 i 번째 인자가 max보다 크면 max = arr[i];
	return max;
}
int minMax(int arr[], int size, bool isMin)
{
	// bool 값이 true 일 경우 최소값
	if (isMin) {	
		int min = arr[0];
		for (int i = 0; i < size; ++i)
			min = arr[i] < min ? arr[i] : min;	// 배열의 i 번째 인자가 min보다 작으면 min = arr[i];
		return min;
	}
	// bool 값이 false면 최대값 리턴
	return minMax(arr, size);
}