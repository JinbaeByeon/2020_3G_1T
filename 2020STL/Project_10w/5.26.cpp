#include<iostream>
#include <vector>
#include <random>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <chrono>

using namespace std;

// ���� size_data �� �߿��� ������ ����  size_search ���� ã�ƺ��µ� �ɸ��� �ð��� �纻��.
const size_t size_data = 100'0000;
const size_t size_search = 10'000;
default_random_engine dre;
normal_distribution<> nd{ 0.,1. };	// -5 ~ 5

// �� �����̳ʿ��� ã�����ϴ� ���� size_search ���� ã�� �ð��� �缭 ���

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
	
	// ����
	vector<Test> v;
	v.reserve(size_data);
	for (int i = 0; i < size_data; ++i) {
		double n = clamp(nd(dre), -5., 5.);
		n += 5;			// 0 ~ 10
		n *= 100'0000;	// 0 ~ 1000'0000


		v.push_back(n);
	}

	// ��
	multiset<Test> s{ v.begin(),v.end() };

	// ������� ��
	unordered_multiset<Test> us{ v.begin(),v.end() };

	cout << "�Է¿Ϸ�" << endl;

	{
		for (int i = 0; i < size_search; ++i)
			find(v.begin(), v.end(), Target[i]);
		cout << "���Ϳ��� ==�� ȣ��� Ƚ���� " << cntEqual <<  endl;
		cout << cntCmp << endl;
	}
	/*{
		start = chrono::steady_clock::now();

		for (int i = 0; i < size_search; ++i)
			s.find(Target[i]);

		ElapsedTime = chrono::duration_cast<chrono::milliseconds> (chrono::steady_clock::now() - start).count();
		cout << "�ɸ� �ð� - " << ElapsedTime << endl;
	}*/

}