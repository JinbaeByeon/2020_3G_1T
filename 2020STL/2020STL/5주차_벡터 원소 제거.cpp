#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	// [문제]를 해결하는 코드를 작성하라

	v.erase(remove_if(v.begin(), v.end(), [](int i) {
		return i & 1;
		}),v.end());
	for (int n : v) // int의 경우 복사나 const &나 차이없음
		cout << n << ' ';
	cout << endl;
}