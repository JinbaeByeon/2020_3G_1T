#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <set>

using namespace std;

//#define 문제1
//#define 문제2
#define 문제3
struct PS :pair<string, string> {
	PS(string s) : pair(s, s) {
		sort(first.begin(), first.end());
	}
	operator string() {
		return second;
	}
};

// operator string()을 만들면 필요 없음
ostream& operator<<(ostream& os, const PS& rhs)
{
	os << rhs.second;
	return os;
}

int main()
{
	ifstream in("단어들.txt");
	vector<PS> v;
	copy(istream_iterator<string>(in), {}, back_inserter(v));
	cout << v.size() << endl;

	sort(v.begin(), v.end(), [](const PS& a, const PS& b) {
		return a.first < b.first;
		});


#ifdef 문제1// [애너그램 찾아서 출력]
	while (true) {
		string word;
		cout << "찾을 단어는?" << endl;
		cin >>word;
		auto [하한, 상한] = equal_range(v.begin(), v.end(), PS(word), [](const PS& a, const PS& b) {
			return a.first < b.first;
			});
		if (상한 == 하한) {
			cout << "없는 단어." << endl;
			continue;
		}
		for (auto i = 하한; i < 상한; ++i) 
			cout << i->second << " ";
		cout << endl;
		
	}
#endif

#ifdef 문제2 // 단어들.txt에 있는 모든 애너그램 쌍을 화면에 출력하라.
			 // 화면 출력 -> 파일 "애너그램쌍.txt"에 출력하라.

	int cnt{};
	auto b = v.begin();
	ofstream out{ "애너그램쌍.txt" };
	while (true) {
		b = adjacent_find(b, v.end(), [](const PS& a, const PS& b) {
			return a.first == b.first;
			});

		if (b == v.end())
			break;

		auto e = find_if_not(b + 1, v.end(), [b](const PS& a) {
			return a.first == b->first;
			});
		
		// cout을 out으로
		out << "[" << ++cnt << "] ";
		
		copy(b, e, ostream_iterator<PS>{out, " "});
		out << endl;
		b = e;
		
	}
#endif

#ifdef 문제3 // 단어들.txt에 있는 애너그램 쌍을 개수 기준 내림차순으로 파일 출력
	ofstream out{ "애너그램쌍 개수 내림차순.txt" };
	auto b = v.begin();
	int cnt{};
	vector<vector<string>> vvs;

	while (true) {
		b = adjacent_find(b, v.end(), [](const PS& a, const PS& b) {
			return a.first == b.first;
			});
		if (b == v.end())
			break;
		auto e = find_if_not(b + 1, v.end(), [b](const PS& a) {
			return a.first == b->first;
			});
		// [b,e) 구간은 애너그램 구간이다.
		vector<string> vs{ b,e };
		vvs.push_back(vs);

		b = e;
	}
	
	// vvs를 개수 기준으로 정렬
	sort(vvs.begin(), vvs.end(), [](const vector<string>& a, const vector<string>& b) {
		return a.size() > b.size();
		});
	
	for (int i = 0; i < vvs.size(); ++i) {
		out << "[" << i + 1 << "] (" << vvs[i].size() << ") - ";
		copy(vvs[i].begin(), vvs[i].end(), ostream_iterator<string>{out, "  "});
		out << endl;
	}
#endif
}