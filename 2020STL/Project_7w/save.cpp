#include "save.h"
#include <iostream>
#include <filesystem>
#include <chrono>
#include <fstream>
using namespace std;

void save(string file_read, string file_write)
{
	ifstream in(file_read, ios::binary);
	size_t size = filesystem::file_size(file_read);
	char* p = new char[size];

	in.read(p, size);
	ofstream out(file_write, ios::binary);
	out.write(p, size);

	auto tp = chrono::system_clock::now();
	auto ct = chrono::system_clock::to_time_t(tp);
	auto lt = localtime(&ct);

	out.imbue(locale("kor"));


	out << std::put_time(lt, "%c - (%A)") << endl;

}