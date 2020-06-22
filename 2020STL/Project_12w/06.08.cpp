#include <iostream>
#include<numeric>
#include <algorithm>
#include<iterator>
#include <random>
#include <fstream>
using namespace std;

//#define ����1
//#define ����2
//#define ����3
//#define ����4
//#define ����5
#define ����6

#ifdef ����5
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
	bool operator<(const Person& rhs) const {	// ���ٴ�(equivalance) �ǹ̴�
		return last < rhs.last;				// < �����ڷ� �Ǵ��Ѵ�.
	}
};
#endif

int main()
{
#ifdef ����1||����2||����3||����4
	int n[100];
	
	iota(begin(n), end(n), 1);

	// �����ϱ� �� n�� �������� ���´�.
	shuffle(begin(n), end(n), default_random_engine());
	cout << "ó���� ������" << endl;
	copy(begin(n), end(n), ostream_iterator<int>(cout, " "));
	cout << endl;
	
	// [����] Ȧ���� ¦���� �и��ϰ� ������ ����϶�. - partition
#endif

#ifdef ����1
	auto p =partition(begin(n), end(n), [](const int& a) {
		return a & 1;
		});
	cout << "Ȧ���Դϴ�." << endl;
	copy(begin(n), p, ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << "¦���Դϴ�." << endl;
	copy(p, end(n), ostream_iterator<int>(cout, " "));
	cout << endl;
#endif

#ifdef ����2
	// �������� ����
	sort(begin(n), end(n) );
	cout << "[sort]" << endl;
	copy(begin(n), end(n), ostream_iterator<int>(cout, " "));
	cout << endl;
#endif

#ifdef ����3
	// �����ϱ� �� n�� �������� ���´�.
	shuffle(begin(n), end(n), default_random_engine());

	// 1����� 10������� ����
	partial_sort(begin(n), begin(n)+10, end(n));
	cout << "[partial_sort]" << endl;
	copy(begin(n), end(n), ostream_iterator<int>(cout, " "));
	cout << endl;
#endif

#ifdef ����4
	shuffle(begin(n), end(n), default_random_engine());

	// 1���� 10���� ������ ������� ������ - n��° ���ұ���
	nth_element(begin(n), begin(n) + 50, end(n));
	cout << "[nth_element]" << endl;
	copy(begin(n), end(n), ostream_iterator<int>(cout, " "));
	cout << endl;
#endif
#ifdef ����5
	Person p[1000];

	sort(begin(p), end(p), [](const Person& a, const Person& b) {
		return a.getFirst() < b.getFirst();
		});
	stable_sort(begin(p), end(p));

	for (const Person& p : p) {
		p.show();
	}
#endif

#ifdef ����6
	ifstream in("�ȷ� Ȩ���� ����.txt");
	vector<string> v{ istream_iterator<string>(in),{} };
	cout << "�ȷ� Ȩ���� ����.txt�� �ִ� �ܾ��� ��" << v.size() << endl;

	sort(v.begin(), v.end());
	while (true) {
		cout << "ã�� �ܾ �Է��ϼ���: ";
		string word;
		cin >> word;

		auto [ó��, ������] = equal_range(v.begin(), v.end(), word);
		if (ó�� != ������) {
			cout << "�� �ܾ�� " << ������ - ó�� << "���� �ֽ��ϴ�." << endl;
			copy(ó�� - 1, ������ + 1, ostream_iterator<string>(cout, " "));
			cout << endl;
		}
		else {
			cout << "���� �����Դϴ�. �� ��ġ�� ���� �� �ܾ� ����" << endl;
			copy(ó�� - 1, ������ + 1, ostream_iterator<string>(cout, " "));
			cout << endl;
		}
	}
#endif
} 