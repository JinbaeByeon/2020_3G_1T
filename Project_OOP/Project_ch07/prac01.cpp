/*
�� ���� ���̸� �� ������� �Է� ���� ��, �� ���� ���̸� ������ �÷��� 
�ﰢ���� �ƴϸ� �ﰢ���� �����,
�ٽ� �̵�ﰢ���� �ƴϸ� �̵�ﰢ���� ����� ���α׷�
*/
#include <iostream>
using namespace std;

class Line {
private:
	int length;
public:
	Line(int length = 0) { this->length = length; }
	void show() { cout << length << endl; }
	bool operator==(Line other) const;
	bool operator<(Line other) const;
	Line operator+(Line other) const;
	Line operator++(int x);
	int operator-(Line other) const;
	friend Line operator+(int length, Line line);
};

class Triangle {
public:
	static bool isTriangle(Line line1, Line line2, Line line3) {
		return line1 < line2 + line3;
	}
	static bool isIsosceles(Line line1, Line line2, Line line3) {
		return line2 == line3;
	}
};

int main() {
	int length1, length2, length3;
	cout << "�� ���� ���� �Է�(�� �������): ";
	cin >> length1 >> length2 >> length3;
	Line line1(length1), line2(length2), line3(length3);

	if (!Triangle::isTriangle(line1, line2, line3)) {
		cout << "�ﰢ���� �ƴմϴ�=>" << endl;
		while (!Triangle::isTriangle(line1, line2, line3)) {
			line2++;
			line3++;
		}
	}
	line1.show(); line2.show(); line3.show(); cout << endl;

	if (!Triangle::isIsosceles(line1, line2, line3)) {
		cout << "�̵�ﰢ���� �ƴմϴ�=>" << endl;
		line3 = (line2 - line3) + line3;	// line3 = line2
	}
	line1.show(); line2.show(); line3.show(); cout << endl;
	return 0;
}


bool Line::operator==(Line other) const{
	return length == other.length;
}
bool Line::operator<(Line other) const{
	return length < other.length;
}
Line Line::operator+(Line other) const{
	return Line(length + other.length);
}
// Line++
Line Line::operator++(int x) {
	Line tmp = *this;
	++length;
	return tmp;
}
int Line::operator-(Line other) const{
	return length - other.length;
}

Line operator+(int length, Line line)
{
	return Line(length + line.length);
}