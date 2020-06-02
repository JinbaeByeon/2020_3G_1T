#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

//#define ����1
//#define ����2
//#define ����3
#define ����4
#ifdef ����1
template<class init>							// template�� ����� ���Ǹ� ���ÿ� �Ѵ�. => template�� ������Ͽ� �ٷ� ����
init print(init first, const init last)
{
	for (; first != last; ++first)
		cout << *first << " ";
	cout << endl;
	return first;
}
int main()
{
	// [����] main�� �������� �ʱ�
	// �����ϸ� �����̳��� ���Ұ��� ȭ�鿡 ��µǵ��� print�� �����ϰ� �����϶�.
	// 1 3 5 4 2
	// 1 2 3 4 5
	vector<int> v{ 1,3,5,4,2 };
	set<int> s{ v.begin(),v.end() };
	print(v.begin(), v.end());
	print(s.begin(), s.end());
}
#endif

#ifdef ����2
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
	// my_find �����
	vector<int> v{ 1,2,3,4,5 };
	auto p = my_find(v.begin(), v.end(), 6);

	if (p != v.end())
		cout << *p << "�� ã�Ҵ�." << endl;
	else
		cout << "���� �����̴�." << endl;
}
#endif

#ifdef ����3
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
	// find_if ����� - ���ϴ� ������ predicate
	vector<int> v{ 1,2,3,4,5 };

	auto p = find_if(v.begin(), v.end(), greater7);

	if (p != v.end())
		cout << *p << "�� Ȧ���̴�." << endl;
	else
		cout << "Ȧ���� ����." << endl;
}
#endif

#ifdef ����4

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
	// v�� ��� ���Ұ� Ȧ����� true�� �����ϴ� my_all_of�� �ۼ�
	vector<int> v{ 1,3,5,7,9 };

	all_of(v.begin(), v.end(), [](int n) {
		return n & 1;
		});
}
#endif

