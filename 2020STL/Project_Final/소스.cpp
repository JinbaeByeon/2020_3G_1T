#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <set>

using namespace std;

//#define ����1
//#define ����2
#define ����3
struct PS :pair<string, string> {
	PS(string s) : pair(s, s) {
		sort(first.begin(), first.end());
	}
	operator string() {
		return second;
	}
};

// operator string()�� ����� �ʿ� ����
ostream& operator<<(ostream& os, const PS& rhs)
{
	os << rhs.second;
	return os;
}

int main()
{
	ifstream in("�ܾ��.txt");
	vector<PS> v;
	copy(istream_iterator<string>(in), {}, back_inserter(v));
	cout << v.size() << endl;

	sort(v.begin(), v.end(), [](const PS& a, const PS& b) {
		return a.first < b.first;
		});


#ifdef ����1// [�ֳʱ׷� ã�Ƽ� ���]
	while (true) {
		string word;
		cout << "ã�� �ܾ��?" << endl;
		cin >>word;
		auto [����, ����] = equal_range(v.begin(), v.end(), PS(word), [](const PS& a, const PS& b) {
			return a.first < b.first;
			});
		if (���� == ����) {
			cout << "���� �ܾ�." << endl;
			continue;
		}
		for (auto i = ����; i < ����; ++i) 
			cout << i->second << " ";
		cout << endl;
		
	}
#endif

#ifdef ����2 // �ܾ��.txt�� �ִ� ��� �ֳʱ׷� ���� ȭ�鿡 ����϶�.
			 // ȭ�� ��� -> ���� "�ֳʱ׷���.txt"�� ����϶�.

	int cnt{};
	auto b = v.begin();
	ofstream out{ "�ֳʱ׷���.txt" };
	while (true) {
		b = adjacent_find(b, v.end(), [](const PS& a, const PS& b) {
			return a.first == b.first;
			});

		if (b == v.end())
			break;

		auto e = find_if_not(b + 1, v.end(), [b](const PS& a) {
			return a.first == b->first;
			});
		
		// cout�� out����
		out << "[" << ++cnt << "] ";
		
		copy(b, e, ostream_iterator<PS>{out, " "});
		out << endl;
		b = e;
		
	}
#endif

#ifdef ����3 // �ܾ��.txt�� �ִ� �ֳʱ׷� ���� ���� ���� ������������ ���� ���
	ofstream out{ "�ֳʱ׷��� ���� ��������.txt" };
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
		// [b,e) ������ �ֳʱ׷� �����̴�.
		vector<string> vs{ b,e };
		vvs.push_back(vs);

		b = e;
	}
	
	// vvs�� ���� �������� ����
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