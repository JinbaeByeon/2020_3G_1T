#include <iostream>
#include <fstream>
using namespace std;

void save(string);		// save ����

int main()
{
	cout << "�� ������ �ϵ��ũ�� �����ϵ��� ����" << endl;
	
	save("�ҽ�_1��2���� ����.cpp");		// �ϵ��ũ�� �����ϴ� �Լ�
}

void save(string s)			// save ����
{
	// ������ ���� ������ ���� -> "�ҽ�.cpp"
	ifstream in(s);

	// ���� ������ ������ ������ ���� -> ������ �����̸��� "��������.txt" ��� ����
	ofstream out("��������.txt", ios::app);

	// �ҽ�.cpp�� ��� ������ �о� ��������.txt ���Ͽ� ����Ѵ�.
	int c;
	while ((c = in.get()) != EOF)
		out << (char)c;

	cout << "�ҽ�.cpp�� ��������.txt�� �����Ͽ����ϴ�" << endl;
}
