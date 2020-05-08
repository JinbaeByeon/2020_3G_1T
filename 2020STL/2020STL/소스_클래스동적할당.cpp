#include <iostream>
using namespace std;
class Model {
	char* data{ nullptr };
	size_t size{ 0 };
	int id{ 0 };

public:
	Model() {
		data = nullptr;
		size = 0;
		id = (int)this;
		cout << id << endl;
		cout << "Model 클래스 생성" << endl;
	}
	Model(int n) {
		size = n;
		data = (char*)this;
		id = (int)this;
		cout << id << endl;
		cout << "Model 클래스 생성" << endl;
	}
	~Model() { cout << "Model 클래스 소멸" << endl; }
	Model(Model& A) {
		data = A.data;
		size = A.size;
		id = A.id;
		cout << id << endl;
		cout << "Model 클래스 복사" << endl;
	}
	Model(Model&& other) : data(nullptr), size(other.size), id((int)this) {
		data = other.data; // data 주소만 가져온다. other.data = nullptr;
		other.size = 0;
		// 관찰 메시지와 id를 출력하도록 하자
		cout << id << endl;
		cout << "이동생성자" << endl;
	}
};

int main()
{
	Model a{ 1000 };
	Model b = move(a);

}