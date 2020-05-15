/* ����Ʈ �Ű� ������ ���� �ϳ��� minMax() �Լ��� �ۼ�*/

#include <iostream>
using namespace std;

int minMax(int[], int, bool isMin = false);	// �� ��° ���ڰ� true�̸� �迭�� �ּҰ��� ��ȯ�ϴ� �Լ�

int main()
{
	int a[] = { 1,2,3,4,5 };;
	int aMax = minMax(a, 5); // �迭 a�� ���� �� �ִ밪 ����
	int aMin = minMax(a, 5, true); // �迭 a�� ���� �� �ּҰ� ����
	cout << aMax << endl; // 5 ��� 
	cout << aMin << endl; // 1 ���
}

int minMax(int arr[], int size, bool isMin)
{
	int idx = 0;
	// bool ���� ���� �ִ밪 Ȥ�� �ּҰ� �ε����� ���Ѵ�
	for (int i = 0; i < size; ++i) {
		if ((isMin && arr[i] < arr[idx]) || (!isMin && arr[i] > arr[idx]))	
			idx = i;		
	}
	return arr[idx];
}