#include "save.h"
#include <iostream>
#include <fstream>
using namespace std;

void save(string file_read,string file_write)
{
	ifstream in(file_read);
	ofstream out(file_write);
	
	char c;
	while ((c = in.get()) != EOF)
		cout << c;

	cout << file_read << "�� " << file_write << "�� �����Ͽ����ϴ�." << endl;
}