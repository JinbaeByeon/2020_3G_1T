// ���� Ŭ���� �����
#pragma once
#include <iostream>
using namespace std;

class Buffer
{
private:
	string data;
public:
	Buffer(string str) :data{ str } {}
	void print();
	void add(const string&);
};

