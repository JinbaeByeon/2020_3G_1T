#include <iostream> 
#include <vector> 
#include "String.h"

using namespace std;
int main()
{
	vector<String> v;
	v.reserve(2);

	v.emplace_back(String("�ڷγ�"));
	cout << "---�����߰�----" << endl;
	v.emplace_back(String("���̷���"));
	cout << " zz" << endl;
	for (String& s : v)
		cout << s << endl;

}