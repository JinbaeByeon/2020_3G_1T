#include<iostream>
using namespace std;

class X {
private:
	int x;
public:
	X(int a): x(a) {}
	friend ostream& operator<<(ostream& os, X& x);
};

ostream& operator<<(ostream& os, X& x) {
	os << x.x;
	return os;
}
void change(X&, X&);

int main()
{
	X a{ 1 };
	X b{ 2 };

	change(a, b);
	cout << a << ", " << b << endl;
}


void change(X& a, X& b)
{
	X t{ a };
	a = b;
	b = t;
}	