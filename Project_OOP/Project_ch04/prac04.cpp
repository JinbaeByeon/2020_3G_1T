// 키보드에서 이름과 전화번호를 입력 받아 출력하고 검색하는 프로그램
#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	string tel;
public:
	Person() {};
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel) {
		this->name = name; this->tel = tel;
	}
};

int main()
{
	Person person[3];	// Person 객체 3개 생성
	string name, tel;	// 입력받을 이름과 전화번호

	cout << "이름과 전화번호를 입력해주세요" << endl;
	for (int i = 0; i < 3; ++i) {
		cout << "사람 " << i + 1 << ">> ";
		cin >> name >> tel;
		person[i].set(name, tel);
	}

	cout << "모든 사람의 이름은 ";
	for (int i = 0; i < 3; ++i)
		cout << person[i].getName() << " ";
	cout << "입니다." << endl;

	cout << "전화번호를 검색합니다. 이름을 입력하세요>>";
	cin >> name;
	for (int i = 0; i < 3; ++i) {
		if (person[i].getName() == name)
			cout << "전화번호는 " << person[i].getTel() << "입니다." << endl;
	}
}