/* minMax() �Լ��� �ߺ� �ۼ�*/

#include <iostream>
using namespace std;

int minMax(int[], int);			// �迭�� �ִ밪�� ��ȯ�ϴ� �Լ�
int minMax(int[], int, bool);	// �� ��° ���ڰ� true�̸� �迭�� �ּҰ��� ��ȯ�ϴ� �Լ�

int main()
{
	int a[] = { 1,2,3,4,5 };;
	int aMax = minMax(a, 5); // �迭 a�� ���� �� �ִ밪 ����
	int aMin = minMax(a, 5, true); // �迭 a�� ���� �� �ּҰ� ����
	cout << aMax << endl; // 5 ��� 
	cout << aMin << endl; // 1 ���
}

int minMax(int arr[], int size)
{
	int max = arr[0];
	for (int i = 0; i < size; ++i)
		max = arr[i] > max ? arr[i] : max;		// �迭�� i ��° ���ڰ� max���� ũ�� max = arr[i];
	return max;
}
int minMax(int arr[], int size, bool isMin)
{
	// bool ���� true �� ��� �ּҰ�
	if (isMin) {	
		int min = arr[0];
		for (int i = 0; i < size; ++i)
			min = arr[i] < min ? arr[i] : min;	// �迭�� i ��° ���ڰ� min���� ������ min = arr[i];
		return min;
	}
	// bool ���� false�� �ִ밪 ����
	return minMax(arr, size);
}