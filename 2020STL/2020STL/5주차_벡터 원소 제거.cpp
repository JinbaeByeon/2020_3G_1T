#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	// [����]�� �ذ��ϴ� �ڵ带 �ۼ��϶�

	v.erase(remove_if(v.begin(), v.end(), [](int i) {
		return i & 1;
		}),v.end());
	for (int n : v) // int�� ��� ���糪 const &�� ���̾���
		cout << n << ' ';
	cout << endl;
}