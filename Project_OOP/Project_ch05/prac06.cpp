// ������ȣ�� �ڵ����� �ο��Ǹ� �Է¹޴� ���ڿ��� ���� �������� ������ ����Ʈ�� �����ϴ� ���α׷�
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

int count_item = 0;	// �������� ��

int main()
{
	Item* list_item[100]{ NULL, };	// ������ ����Ʈ
	string str_input;

	// ������ ����Ʈ�� ũ���� 100�� �ʰ��Ͽ� �������� �ʴ´�.
	while (count_item <= 100) {
		cout << "[�����۸�] Ȥ�� [�����۸�] [�����ۼ���]�� �Է��ϼ���>> ";
		
		// �̸��� 20���ڸ� �ʰ��Ͽ� �Է��� ��츦 ���� �ݺ���
		while (true) {	
			getline(cin, str_input, '\n');
			// �����۸� �Է¹޾��� ���
			if (str_input.find(' ') == -1) {
				// �����۸��� 20���ڸ� �ʰ��Ͽ� �Է��� ��� ���Է�
				if (str_input.length() > 20)
					cout << "�̸��� 20���� ���Ϸ� �Է��ϼ���>>";
				else break;
			}
			// �����۸� + �����ۼ����� �Է¹޾��� ���
			else {
				// �����۸��̳� �����ۼ����� 20���ڸ� �ʰ��Ͽ� �Է��� ��� ���Է�
				if (str_input.find(' ') > 20 || str_input.length()-str_input.find(' ') > 21)
					cout << "�� �̸��� 20���� ���Ϸ� �Է��ϼ���>>";
				else break;
			}
		}
		// �����۸� �Է¹޾��� ���
		if (str_input.find(' ') == -1) {
			Item* tmp = new Item(str_input);
			// ���� �������� �ƴ� ��� ���� �������� ������ ����
			if (count_item > 0)
				tmp->setExplain(list_item[count_item - 1]->getExplain());
			
			list_item[count_item] = new Item(*tmp);
			++count_item;
		}
		// �����۸� + �����ۼ����� �Է¹޾��� ���
		else {
			// �Է¹��� ���ڿ��� ���� ���������� ���ڿ��� �̸�, ���� ������ ���ڿ��� ����
			list_item[count_item] = new Item(str_input.substr(0, str_input.find(' ')),
				str_input.substr(str_input.find(' ') + 1));
			++count_item;
		}
		// ������ ����Ʈ ���
		for (int i = 0; i < count_item; ++i)
			list_item[i]->show();
		cout << endl;
	}
	// ���α׷� ���� �� �Ҹ��� ȣ��
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
// ���� ������
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
	cout << "[�����۸�:" << name << "] [�����ۼ���:" << explain << "]" << endl;
}