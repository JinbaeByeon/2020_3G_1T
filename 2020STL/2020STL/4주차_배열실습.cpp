#include <iostream>
#include <array>
#include <algorithm>
#include "String.h"

using namespace std;


int main()
{
	array<String, 16> words{ "Anger", "as", "Japanese", "Prime", "Minister offers", "two",
"cloth", "masks", "per", "family", "while", "refusing", "to", "declare",
"coronavirus", "emergency" };

	cout << "�����ϱ� ��" << endl;
	for (int i = 0; i < words.size(); ++i)
		cout << words[i] << " ";
	cout << endl << endl;

	// ���⿡ �� ���� �ڵ带 �����.
	
	for (int i = 0; i < words.size(); ++i) {
		sort(&words[i][0], &words[i][words[i].size()], [](const char& a, const char& b) {
			return a < b;
			});
	}

	cout << "������ ���" << endl;
	for (int i = 0; i < words.size(); ++i)
		cout << words[i] << " ";
	cout << endl;
	
}