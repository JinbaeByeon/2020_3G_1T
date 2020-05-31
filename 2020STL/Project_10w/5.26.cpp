#include<iostream>
#include <vector>
#include <random>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <chrono>

using namespace std;

// 정수 size_data 개 중에서 임의의 정수  size_search 개를 찾아보는데 걸리는 시간을 재본다.
const size_t size_data = 100'0000;
const size_t size_search = 10'000;
default_random_engine dre;
normal_distribution<> nd{ 0.,1. };	// -5 ~ 5

// 각 컨테이너에서 찾고자하는 정수 size_search 개를 찾는 시간을 재서 출력

int cntEqual = 0;
int cntCmp = 0;

class Test {
	int n;
public:
	Test(int n) : n{ n } {};
	Test() = default;
	
	bool operator<(const Test& rhs) const {
		return n < rhs.n;
		++cntCmp;
	}
	int getN() const{ return n; }
	bool operator==(const Test& rhs) const {
		return n == rhs.n;
		++cntEqual;
	}
};

Test Target[size_search];
template<>
struct hash<Test>
{
	size_t operator()(const Test& t) const {
		return hash<int>()(t.getN());
	}
};


int main()
{
	uniform_int_distribution<> uid{ 10,1000'0000 };
	for (int i = 0; i < size_search; ++i)
		Target[i] = uid(dre);
	
	// 벡터
	vector<Test> v;
	v.reserve(size_data);
	for (int i = 0; i < size_data; ++i) {
		double n = clamp(nd(dre), -5., 5.);
		n += 5;			// 0 ~ 10
		n *= 100'0000;	// 0 ~ 1000'0000


		v.push_back(n);
	}

	// 셋
	multiset<Test> s{ v.begin(),v.end() };

	// 언오더드 셋
	unordered_multiset<Test> us{ v.begin(),v.end() };

	cout << "입력완료" << endl;

	{
		for (int i = 0; i < size_search; ++i)
			find(v.begin(), v.end(), Target[i]);
		cout << "벡터에서 ==이 호출된 횟수는 " << cntEqual <<  endl;
		cout << cntCmp << endl;
	}
	/*{
		start = chrono::steady_clock::now();

		for (int i = 0; i < size_search; ++i)
			s.find(Target[i]);

		ElapsedTime = chrono::duration_cast<chrono::milliseconds> (chrono::steady_clock::now() - start).count();
		cout << "걸린 시간 - " << ElapsedTime << endl;
	}*/

}