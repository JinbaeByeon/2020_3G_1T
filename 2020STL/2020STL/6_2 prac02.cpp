#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "String.h"
using namespace std;

int main()
{
	ifstream in("STL Wiki.txt");
	if (!in) {
		cout << "파일 열기 실패" << endl;
		return 0;
	}

	vector<char> v{ istreambuf_iterator<char>(in),istreambuf_iterator<char>() };
	int num_words = 0;
	for (auto i = v.cbegin(); i < v.cend(); ++i) {
		if (*i == ' ') ++num_words;
		else if (isalpha(*(i - 1)) && (*i == '\n' || *i == '.') && *(i + 1) != ' ')++num_words;
	}
	cout << num_words;

}