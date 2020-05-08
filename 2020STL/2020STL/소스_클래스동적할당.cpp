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
		cout << "Model Ŭ���� ����" << endl;
	}
	Model(int n) {
		size = n;
		data = (char*)this;
		id = (int)this;
		cout << id << endl;
		cout << "Model Ŭ���� ����" << endl;
	}
	~Model() { cout << "Model Ŭ���� �Ҹ�" << endl; }
	Model(Model& A) {
		data = A.data;
		size = A.size;
		id = A.id;
		cout << id << endl;
		cout << "Model Ŭ���� ����" << endl;
	}
	Model(Model&& other) : data(nullptr), size(other.size), id((int)this) {
		data = other.data; // data �ּҸ� �����´�. other.data = nullptr;
		other.size = 0;
		// ���� �޽����� id�� ����ϵ��� ����
		cout << id << endl;
		cout << "�̵�������" << endl;
	}
};

int main()
{
	Model a{ 1000 };
	Model b = move(a);

}