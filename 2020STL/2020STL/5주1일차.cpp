#include <iostream> 
#include <vector> 
#include <algorithm>
#include "String.h" 

using namespace std;
int main()
{
	vector<String> v;
	v.reserve(4);
	v.emplace_back("일본");
	v.emplace_back("코로나");
	v.emplace_back("신규확진");
	v.emplace_back("700명");

	cout << "vector v의 주소: " << &v << endl;
	cout << "원소의 갯수: " << v.size() << endl;
	cout << "원소가 저장된 메모리: " << v.data() << endl;
	cout << "재할당하지 않고 담을 수 있는 갯수: " << v.capacity() << endl;

	cout << "------------------" << endl;
	cout << "원소를 추가하기 전" << endl;
	// v를 사용하여 원하는 일을 할 만큼했다. 그런데 원소가 한 개 더 필요하다. 
	// 아래와 같이 원소를 추가하면 어떤 일이 일어날까?
	v.emplace_back("PANDEMIC");
	cout << "원소를 추가한 후" << endl;
	cout << "------------------" << endl;

	cout << "vector v의 주소: " << &v << endl;
	cout << "원소의 갯수: " << v.size() << endl;
	cout << "원소가 저장된 메모리: " << v.data() << endl;
	cout << "재할당하지 않고 담을 수 있는 갯수: " << v.capacity() << endl;
}