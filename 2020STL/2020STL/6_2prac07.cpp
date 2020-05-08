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
	ofstream out("STL Wiki에서 5글자로 된 단어.txt");

	vector<char> v{ istreambuf_iterator<char>(in),istreambuf_iterator<char>() };
	vector<string> v_string;
	string s;
	auto begin = v.begin();

	for (auto i = v.begin(); i < v.end(); ++i) {
		if (*i != '\n') s.push_back(*i);
		if (*i == ' ') {
			if (s.length() == 6)
				v_string.emplace_back(s);
			s.clear();
		}
		else if (*i - 1 != ' ' && *i - 1 != '\n' && (*i == '\n' || *i == '.') && *(i + 1) != ' ') {
			if (s.length() == 6)
				v_string.emplace_back(s);
			s.clear();
		}
	}

	for (auto i : v_string)
		out << i << ' ';
}