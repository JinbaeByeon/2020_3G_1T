#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

//#define 문제1
//#define 문제2
//#define 문제3
#define 문제4
#ifdef 문제1
template<class init>							// template은 선언과 정의를 동시에 한다. => template은 헤더파일에 바로 정의
init print(init first, const init last)
{
	for (; first != last; ++first)
		cout << *first << " ";
	cout << endl;
	return first;
}
int main()
{
	// [문제] main을 수정하지 않기
	// 실행하면 컨테이너의 원소값이 화면에 출력되도록 print를 선언하고 정의하라.
	// 1 3 5 4 2
	// 1 2 3 4 5
	vector<int> v{ 1,3,5,4,2 };
	set<int> s{ v.begin(),v.end() };
	print(v.begin(), v.end());
	print(s.begin(), s.end());
}
#endif

#ifdef 문제2
template<class init,class Val>
init my_find(init first,const init last,const Val& value)
{
	while (first != last) {
		if (*first == value)
			return first;
		++first;
	}
	return first;
}
int main()
{
	// my_find 만들기
	vector<int> v{ 1,2,3,4,5 };
	auto p = my_find(v.begin(), v.end(), 6);

	if (p != v.end())
		cout << *p << "를 찾았다." << endl;
	else
		cout << "없는 원소이다." << endl;
}
#endif

#ifdef 문제3
template<class init,class Pr>
init my_find_if(init first, const init last, Pr pred)
{
	while (first != last) {
		if (pred(*first))
			return first;
		++first;
	}
	return first;
}

bool greater7(int n)
{
	if (7 < n)
		return true;
	return false;
}

int main()
{
	// find_if 만들기 - 원하는 조건은 predicate
	vector<int> v{ 1,2,3,4,5 };

	auto p = find_if(v.begin(), v.end(), greater7);

	if (p != v.end())
		cout << *p << "는 홀수이다." << endl;
	else
		cout << "홀수가 없다." << endl;
}
#endif

#ifdef 문제4

template<class init,class Pr>
bool my_all_of(init first, const init& last, Pr pred)
{
	while (first != last) {
		if (pred(*first))
			return false;
		++first;
	}
	return true;
}

int main()
{
	// v의 모든 원소가 홀수라면 true를 리턴하는 my_all_of를 작성
	vector<int> v{ 1,3,5,7,9 };

	all_of(v.begin(), v.end(), [](int n) {
		return n & 1;
		});
}
#endif

