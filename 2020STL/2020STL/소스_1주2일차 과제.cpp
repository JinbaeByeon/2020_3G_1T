//#include <iostream> 
//#include <random> 
//#include <fstream> 
//
//using namespace std;
//
//int main() {
//	default_random_engine dre;
//	uniform_int_distribution<int> uid;
//
//	ofstream out("정수1000개.txt");
//	int n;
//	for (int i = 0; i < 1'000; ++i) {
//		n = uid(dre);
//		out.write((char*)&n, sizeof(n));
//
//	}
//	out.close();

//	ifstream in("정수1000개.txt");
//	int data[1000];
//	in.read((char*)data, sizeof(int) * 1000);
//
//	for (int i : data)
//		cout << i << endl;
//}
#include <iostream> 
#include <string> 
#include <fstream>

using namespace std;
int main()
{
	int n = 18;
	cout << n << ", " << &n << endl;
	ofstream out("연습용.txt");
	out.write((char*)&n, sizeof(n));
	out.close();

	ifstream in("연습용.txt");
	int a;
	in.read((char*)&a, sizeof(a));
	cout << a << ", " << &a << endl;

	/*cout << n << ", " << &n << endl;*/
}