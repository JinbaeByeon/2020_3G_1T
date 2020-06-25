// 두 벡터를 하나의 정렬된 벡터로 병합시키는 프로그램
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// 크기가 같고 각각 정렬된 두 배열을 입력 받고, 
// 두 배열을 병합하여 정렬된 새 배열을 리턴한다.
template <class T>
vector<T> merge(vector<T> v1, vector<T> v2) {
	vector<T> v;
	v.reserve(v1.size() + v2.size());
	for (int i = 0; i < v1.size(); ++i)
		v.emplace_back(v1[i]);
	for (int i = 0; i < v2.size(); ++i)
		v.emplace_back(v2[i]);
	sort(v.begin(), v.end());
	return v;
}

template <class T>
void print(T beg, T end) {
	for (auto p = beg; p != end; ++p)
		cout << *p << " ";
	cout << endl;
}

int main() {
	vector<int> a = { 2, 3, 5, 7, 9 };
	vector<int> b = { 1, 4, 6, 8, 12 };
	vector<int> c = merge(a, b);
	print(c.begin(), c.end());

	vector<double> d1 = { 1.5, 2.7, 9.6, 1e+10 };
	vector<double> d2 = { -3.8, 0, 1e-10, 100.0 };
	vector<double> d3 = merge(d1, d2);
	print(d3.begin(), d3.end());
	return 0;
}