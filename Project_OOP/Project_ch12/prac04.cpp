#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	const char* file = "prac02.cpp";

	ofstream fout{ file ,ios::app | ios::ate };
	if (!fout) {
		cout << "������ ���� ����" << endl;
		return-1;
	}

	long n = fout.tellp();
	cout << n << endl;

	fout.close();
	return 0;
}