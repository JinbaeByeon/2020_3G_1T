// 컨테이너 반복자를 이용한 print 함수 구현
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T>
void print(T beg, T end) {
	for (auto p = beg; p != end; ++p)
		cout << *p << " ";
	cout << endl;
}

int main() {
	vector<int> a = { 2, 3, 5, 7, 9 };
	print(a.begin(), a.end());

	vector<double> d1 = { 1.5, 2.7, 9.6, 1e+10 };
	print(d1.begin(), d1.end());
	return 0;
}