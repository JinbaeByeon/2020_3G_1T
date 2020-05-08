#include <iostream> 
#include <fstream> 
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> v;
	v.reserve(10000);

	ifstream in("정수 만개");
	int n = 0;

	for (int i = 0; i < 10000; ++i) {
		in >> n;
		v.push_back(n);
	}
	auto a = count_if(v.begin(), v.end(), [](int i) {
		if (0 <= i && i < 10000)return true;
		return false;
		});
	cout << a << endl;



}

//#include <iostream> 
//#include <fstream> 
//#include <random> 
//using namespace std;
//int main()
//{
//	ofstream out("정수 만개");
//	default_random_engine dre;
//	uniform_int_distribution<> uid(0, 10'0000);
//	for (int i = 0; i < 1'0000; ++i) {
//		out << uid(dre) << "  ";
//		if (i % 10 == 9)
//			out << endl;
//	}
//}