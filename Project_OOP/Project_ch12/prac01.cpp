#include <iostream>
#include <fstream>
using namespace std;
#define �б�
#define ����
int main() {
	char name[10], dept[20];
	int sid;

#ifdef ����
	// Ű����κ��� �б�
	cout << "�̸�>>";
	cin >> name; // Ű���忡�� �̸� �Է� ����
	cout << "�й�>>";
	cin >> sid; // Ű���忡�� �й� �Է� ����
	cout << "�а�>>";
	cin >> dept; // Ű���忡�� �а� �Է� ����
	// ���� ����. student.txt ������ ����, ��� ��Ʈ�� ����
	ofstream fout("student.txt",ios::out | ios::app);
	if (!fout) { // ���� ���� �˻�
		cout << "student.txt ������ �� �� ����";
		return 0;
	}

	// ���� ����
	fout << name << endl; // name ����
	fout << sid << endl; // sid ����
	fout << dept << endl; // dept ����

	fout.close(); // ���� �ݱ�
#endif

#ifdef �б�
	ifstream fin; 	// ��Ʈ�� ��ü ���� �� ���� ����
	fin.open("student.txt");
	if (!fin) {  // ���� ���� ���� Ȯ��
		cout << "������ �� �� ����";
		return 0;
	}
	while (true) {
		// ���� �б�
		fin >> name; // ���Ͽ� �ִ� ���ڿ��� �о name �迭�� ����
		fin >> sid; // ������ �о sid ������ ������ ����
		fin >> dept; // ���ڿ��� �а� dept �迭�� ����
		if (fin.eof())break;
		// ���� �ؽ�Ʈ�� ȭ�鿡 ���
		cout << name << endl;
		cout << sid << endl;
		cout << dept << endl;
	}
	fin.close(); // ���� �б⸦ ��ġ�� ������ �ݴ´�.
#endif
}