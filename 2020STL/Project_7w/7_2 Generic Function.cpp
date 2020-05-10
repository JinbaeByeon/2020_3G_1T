#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include "String.h"
using namespace std;

template<class T>
void print(T b, T e);

template<class T>
T my_max_element(T b, T e);

template<class InIt ,class OutIt>
OutIt my_copy(InIt first,InIt last, OutIt result);

int main()
{
 	string str{ "The quick brown fox jumps over the lazy dog" };
	String s{};
//	s.reserve(str.size());
	copy(str.begin(), str.end(), String_back_insert_iterator(s));
	
	cout << "s: " << s << endl
		<< "str: " << str << endl;
	cout << "완료" << endl;





	/*my_copy 벡터*/
	//vector<char> v;
	//v.reserve(str.size());
	//
	//my_copy(str.begin(), str.end(), back_inserter(v));
	//for (char c : v)
	//	cout << c << " ";
	//cout << endl;

	/*my_max_element*/
	//auto p = my_max_element(str.begin(), str.end());
	//cout << "최대 : " << *p << endl;
}

template<class T>
void print(T b, T e)
{
	while (b != e) {
		cout << *b;
		++b;
	}
	cout << endl;
}

template<class T>
T my_max_element(T b, T e)
{
	T max = b;
	for (; ++b != e;) {
		if (*max < *b) max = b;
	}
	return max;

}

template<class InIt, class OutIt>
OutIt my_copy(InIt first, InIt last, OutIt result)
{
	for (; first != last; ++first,++result) {
		*result = *first;
	}
	return result;
}