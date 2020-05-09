#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include "String.h"
#include <string>
using namespace std;

int main() {
	String str{ "The quick brown fox jumps over the lazy dog" };
	sort(str.begin(), str.end());

	cout << str << endl;
}
