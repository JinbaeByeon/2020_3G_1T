#include <iostream> 
#include <vector> 
#include "String.h"

using namespace std;
int main()
{
	vector<String> v;
	v.reserve(2);

	v.emplace_back(String("코로나"));
	cout << "---원소추가----" << endl;
	v.emplace_back(String("바이러스"));
	cout << " zz" << endl;
	for (String& s : v)
		cout << s << endl;

}