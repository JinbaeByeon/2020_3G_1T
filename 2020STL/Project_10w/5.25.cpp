#include <iostream>
#include<unordered_set>
#include <set>
#include <vector>
#include <thread>
#include <iterator>
#include "String.h"
#include <string>
#include <random>
using namespace std;

template<>
struct hash<String>
{
	size_t operator()(const String& s) const {
		return hash<string>()(s.getString());
	}
};

int main()
{
	// �ؽ�
	/*unordered_multiset<int> us{ 1,2,3,4,5,6,7,8 };

	int n = 9;
	while (true) {
		cout << "��Ŷ�� ���� - " << us.bucket_count() << ": ";
		for (int i = 0; i < us.bucket_count(); ++i) {
			if (us.bucket_size(i)) {
				cout << "[" << i << "] ";
				for (auto j = us.begin(i); j != us.end(i); ++j)
					cout << "=> " << *j << " ";
				cout << endl;
			}
		}
		cout << endl;

		us.insert(++n %= 8 + 1);
		this_thread::sleep_for(5000ms);
	}*/

	// String �ؽ�
	/*unordered_multiset<String> us{ "���Ϻ���","����ũ","�Ⱦ���","����-�ý�","ž������" };
	String s[]{ "���Ϻ���","����ũ","�Ⱦ���","����-�ý�","ž������" };
	int n = 0;
	while (true) {
		cout << "��Ŷ�� ���� - " << us.bucket_count() << endl;
		for (int i = 0; i < us.bucket_count(); ++i) {
			if (us.bucket_size(i)) {
				cout << "[" << i << "] ";
				for (auto j = us.begin(i); j != us.end(i); ++j)
					cout << "=> " << *j << " ";
				cout << endl;
			}
		}
		cout << endl;

		cout << "ã�� ���Ҵ�? >>";
		String str;
		cin >> str;

		auto p = us.find(str);
		if (p != us.end())
			cout << str << "(��)�� ã�ҽ��ϴ�." << endl;
		else
			cout << str << "(��)�� ã�� ���߽��ϴ�." << endl;
	
		us.insert(s[++n%5]);
		this_thread::sleep_for(1000ms);
	}*/

}