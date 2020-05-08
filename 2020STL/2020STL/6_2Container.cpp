#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ifstream in("STL Wiki.txt");
	if (!in) {
		cout << "파일 열기 실패" << endl;
		return 0;
	}

	vector<char> v{ istreambuf_iterator<char>(in),istreambuf_iterator<char>() };
	auto begin = v.begin();

	for (auto i = v.begin(); i < v.end(); ++i) {
		if (*i == ' ') {
			reverse(begin, i);
			while (!isalpha(*i))++i;
			begin = i;
		}
		else if (isalpha(*(i - 1)) && (*i == '\n' || *i == '.') && *(i + 1) != ' '){
			reverse(begin, i);
			while (!isalpha(*i))++i;
			begin = i;
		}
	}

	for (auto i : v)
		cout << i;

}