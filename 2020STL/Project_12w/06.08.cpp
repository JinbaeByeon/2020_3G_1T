#include <iostream>
#include<numeric>
#include <algorithm>
#include<iterator>
#include <random>
#include <fstream>
using namespace std;

//#define 문제1
//#define 문제2
//#define 문제3
//#define 문제4
//#define 문제5
#define 문제6

#ifdef 문제5
default_random_engine dre;
uniform_int_distribution<> uid{ 'a','z' };
class Person {
	string first;
	string last;
public:
	Person() {
		for (int i = 0; i < 2; ++i) {
			first += uid(dre);
			last += uid(dre);
		}
	}
	string getFirst() const {
		return first;
	}
	string getLast() const {
		return last;
	}

	void show() const {
		cout << first << " - " << last << endl;
	}
	bool operator<(const Person& rhs) const {	// 같다는(equivalance) 의미는
		return last < rhs.last;				// < 연산자로 판단한다.
	}
};
#endif

int main()
{
#ifdef 문제1||문제2||문제3||문제4
	int n[100];
	
	iota(begin(n), end(n), 1);

	// 정렬하기 전 n을 무작위로 섞는다.
	shuffle(begin(n), end(n), default_random_engine());
	cout << "처리할 데이터" << endl;
	copy(begin(n), end(n), ostream_iterator<int>(cout, " "));
	cout << endl;
	
	// [문제] 홀수와 짝수로 분리하고 나누어 출력하라. - partition
#endif

#ifdef 문제1
	auto p =partition(begin(n), end(n), [](const int& a) {
		return a & 1;
		});
	cout << "홀수입니다." << endl;
	copy(begin(n), p, ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << "짝수입니다." << endl;
	copy(p, end(n), ostream_iterator<int>(cout, " "));
	cout << endl;
#endif

#ifdef 문제2
	// 오름차순 정렬
	sort(begin(n), end(n) );
	cout << "[sort]" << endl;
	copy(begin(n), end(n), ostream_iterator<int>(cout, " "));
	cout << endl;
#endif

#ifdef 문제3
	// 정렬하기 전 n을 무작위로 섞는다.
	shuffle(begin(n), end(n), default_random_engine());

	// 1등부터 10등까지만 정렬
	partial_sort(begin(n), begin(n)+10, end(n));
	cout << "[partial_sort]" << endl;
	copy(begin(n), end(n), ostream_iterator<int>(cout, " "));
	cout << endl;
#endif

#ifdef 문제4
	shuffle(begin(n), end(n), default_random_engine());

	// 1부터 10까지 순서와 관계없이 골라봐라 - n번째 원소까지
	nth_element(begin(n), begin(n) + 50, end(n));
	cout << "[nth_element]" << endl;
	copy(begin(n), end(n), ostream_iterator<int>(cout, " "));
	cout << endl;
#endif
#ifdef 문제5
	Person p[1000];

	sort(begin(p), end(p), [](const Person& a, const Person& b) {
		return a.getFirst() < b.getFirst();
		});
	stable_sort(begin(p), end(p));

	for (const Person& p : p) {
		p.show();
	}
#endif

#ifdef 문제6
	ifstream in("셜록 홈즈의 모험.txt");
	vector<string> v{ istream_iterator<string>(in),{} };
	cout << "셜록 홈즈의 모험.txt에 있는 단어의 수" << v.size() << endl;

	sort(v.begin(), v.end());
	while (true) {
		cout << "찾을 단어를 입력하세요: ";
		string word;
		cin >> word;

		auto [처음, 마지막] = equal_range(v.begin(), v.end(), word);
		if (처음 != 마지막) {
			cout << "이 단어는 " << 마지막 - 처음 << "개가 있습니다." << endl;
			copy(처음 - 1, 마지막 + 1, ostream_iterator<string>(cout, " "));
			cout << endl;
		}
		else {
			cout << "없는 원소입니다. 들어갈 위치는 다음 두 단어 사이" << endl;
			copy(처음 - 1, 마지막 + 1, ostream_iterator<string>(cout, " "));
			cout << endl;
		}
	}
#endif
} 