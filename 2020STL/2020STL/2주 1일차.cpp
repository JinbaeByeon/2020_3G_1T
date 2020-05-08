#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

#define SIZE 10'000'000

int main()
{
	ifstream in("����1000����.data", ios::binary);
	ofstream out("����1000��������.data", ios::binary);

	vector<int> v = {};

	// ����1. ���� 1000���� �о����
	int n;
	for (int i = 0; i < SIZE; ++i) {
		in.read((char*)&n, sizeof(n));
		v.push_back(n);
	}

	// ����2. ���� ���� 1000���� sort�� �����ϱ�  
	sort(v.begin(),v.end());

	// ����3. ������ ���� �����ϱ�
	for (int i = 0; i < SIZE; ++i) {
		out.write((char*)&v[i], sizeof(v[i]));
	}
}