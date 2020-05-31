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
	// 해쉬
	/*unordered_multiset<int> us{ 1,2,3,4,5,6,7,8 };

	int n = 9;
	while (true) {
		cout << "버킷의 개수 - " << us.bucket_count() << ": ";
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

	// String 해쉬
	/*unordered_multiset<String> us{ "내일부터","마스크","안쓰면","버스-택시","탑승제한" };
	String s[]{ "내일부터","마스크","안쓰면","버스-택시","탑승제한" };
	int n = 0;
	while (true) {
		cout << "버킷의 개수 - " << us.bucket_count() << endl;
		for (int i = 0; i < us.bucket_count(); ++i) {
			if (us.bucket_size(i)) {
				cout << "[" << i << "] ";
				for (auto j = us.begin(i); j != us.end(i); ++j)
					cout << "=> " << *j << " ";
				cout << endl;
			}
		}
		cout << endl;

		cout << "찾을 원소는? >>";
		String str;
		cin >> str;

		auto p = us.find(str);
		if (p != us.end())
			cout << str << "(을)를 찾았습니다." << endl;
		else
			cout << str << "(을)를 찾지 못했습니다." << endl;
	
		us.insert(s[++n%5]);
		this_thread::sleep_for(1000ms);
	}*/

}