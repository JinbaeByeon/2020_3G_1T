#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

#define SIZE 10'000'000

int main()
{
	ifstream in("정수1000만개.data", ios::binary);
	ofstream out("정수1000만개정렬.data", ios::binary);

	vector<int> v = {};

	// 문제1. 정수 1000만개 읽어오기
	int n;
	for (int i = 0; i < SIZE; ++i) {
		in.read((char*)&n, sizeof(n));
		v.push_back(n);
	}

	// 문제2. 읽은 정수 1000만개 sort로 정렬하기  
	sort(v.begin(),v.end());

	// 문제3. 정렬한 정수 저장하기
	for (int i = 0; i < SIZE; ++i) {
		out.write((char*)&v[i], sizeof(v[i]));
	}
}