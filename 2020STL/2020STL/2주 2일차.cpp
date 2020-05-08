#include <iostream>
#include <string>
#include<array>
using namespace std;

template<typename T,size_t n>
class Array {
private:
	size_t num{ 0 };
	T* data;

public:
	explicit Array() :num{ n }, data{ new T[num] } {}
	~Array() { delete[] data; }
	Array(const Array&) = delete;
	Array& operator=(const Array&) = delete;
	T operator[](int idx) const {
		return data[idx];
	}
	T& operator[](int idx) {
		return data[idx];
	}
};

int main()
{
	Array<string,10> a;

	for (int i = 0; i < 10; ++i)
		a[i] = "string"s + to_string(i); // a에 쓰기
	for (int i = 0; i < 10; ++i)
		cout << a[i] << endl; // a에서 읽기
}