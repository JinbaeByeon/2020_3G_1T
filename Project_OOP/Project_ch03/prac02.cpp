// ��, ��, ���� ������ �޷� Ŭ����
#include <iostream>
using namespace std;

class Calendar {
public:
	int year = 0;
	int month = 0;
	int day = 0;

	Calendar() {}
	Calendar(int y) :year{ y } {}
	Calendar(int y, int m, int d) :year{ y }, month{ m }, day{ d } {}
	~Calendar() { cout << "�Ҹ��ڰ� ȣ��Ǿ����ϴ�." << endl; }
};