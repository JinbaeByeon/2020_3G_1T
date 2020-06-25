#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	const char* file = "prac02.cpp";

	ofstream fout{ file ,ios::app | ios::ate };
	if (!fout) {
		cout << "파일을 읽지 못함" << endl;
		return-1;
	}

	long n = fout.tellp();
	cout << n << endl;

	fout.close();
	return 0;
}