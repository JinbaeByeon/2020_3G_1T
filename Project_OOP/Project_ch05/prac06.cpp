// 고유번호가 자동으로 부여되며 입력받는 문자열에 따라 아이템을 생성해 리스트에 저장하는 프로그램
#include <iostream>
#include <string>
using namespace std;

class Item {
private:
	string name{ NULL };
	int id{ 0 };
	string explain{ NULL };
public:
	Item(const string& name);
	Item(const string& name,const string& explain);
	Item(const Item& other);
	void show();
	string getExplain();
	void setExplain(const string& explain);
};

int count_item = 0;	// 아이템의 수

int main()
{
	Item* list_item[100]{ NULL, };	// 아이템 리스트
	string str_input;

	// 아이템 리스트의 크기인 100을 초과하여 생성하지 않는다.
	while (count_item <= 100) {
		cout << "[아이템명] 혹은 [아이템명] [아이템설명]을 입력하세요>> ";
		
		// 이름을 20글자를 초과하여 입력한 경우를 위한 반복문
		while (true) {	
			getline(cin, str_input, '\n');
			// 아이템명만 입력받았을 경우
			if (str_input.find(' ') == -1) {
				// 아이템명을 20글자를 초과하여 입력한 경우 재입력
				if (str_input.length() > 20)
					cout << "이름을 20글자 이하로 입력하세요>>";
				else break;
			}
			// 아이템명 + 아이템설명을 입력받았을 경우
			else {
				// 아이템명이나 아이템설명을 20글자를 초과하여 입력한 경우 재입력
				if (str_input.find(' ') > 20 || str_input.length()-str_input.find(' ') > 21)
					cout << "각 이름을 20글자 이하로 입력하세요>>";
				else break;
			}
		}
		// 아이템명만 입력받았을 경우
		if (str_input.find(' ') == -1) {
			Item* tmp = new Item(str_input);
			// 최초 아이템이 아닌 경우 이전 아이템의 설명을 복사
			if (count_item > 0)
				tmp->setExplain(list_item[count_item - 1]->getExplain());
			
			list_item[count_item] = new Item(*tmp);
			++count_item;
		}
		// 아이템명 + 아이템설명을 입력받았을 경우
		else {
			// 입력받은 문자열의 공백 이전까지의 문자열은 이름, 공백 이후의 문자열은 설명
			list_item[count_item] = new Item(str_input.substr(0, str_input.find(' ')),
				str_input.substr(str_input.find(' ') + 1));
			++count_item;
		}
		// 아이템 리스트 출력
		for (int i = 0; i < count_item; ++i)
			list_item[i]->show();
		cout << endl;
	}
	// 프로그램 종료 시 소멸자 호출
	delete[] list_item;
}

Item::Item(const string& name)
{
	this->name = name;
	id = count_item + 1;
}
Item::Item(const string& name, const string& explain)
{
	this->name = name;
	this->explain = explain;
	id = count_item + 1;
}
// 복사 생성자
Item::Item(const Item& other)
{
	this->name = other.name;
	this->explain = other.explain;
	id = count_item + 1;
}

string Item::getExplain()
{
	return explain;
}

void Item::setExplain(const string& explain)
{
	this->explain = explain;
}

void Item::show()
{
	cout << "[아이템명:" << name << "] [아이템설명:" << explain << "]" << endl;
}