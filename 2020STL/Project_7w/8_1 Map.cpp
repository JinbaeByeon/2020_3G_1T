#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

/* ���� 1: ���̵� �׷� map (include: iomanip)*/
//enum class Gender { Boy, Girl, Hybrid };
//string Genders[]{ "���̱׷�","�ɱ׷�","ȥ���׷�" };
//
//class IdolGroup {
//	string groupName;		// �׷� �̸�
//	Gender gender;			// ����
//	int year;				// ���� �⵵
//	int num;				// �ο� ��
//	string member;			// �����
//
//public:
//	explicit IdolGroup(string gn, Gender g, int y, int n, string m)
//		:groupName(gn), gender(g), year(y), num(n), member(m) {}
//	
//	void show() const {
//		cout << " �̸� :" << left << setw(14) << groupName << setw(8)
//			 << Genders[static_cast<int>(gender)] << ", " << year << " ��, "
//			 << num << " ��, ��� - " << member << endl;
//	}
//	int getYear() const { return year; }
//};
//
//int main()
//{
//	map<string, IdolGroup> IdolGroups;
//
//	IdolGroups.insert(pair<string, IdolGroup>("�� �ý�����",
//		IdolGroup("�� �ý�����", Gender::Girl, 1968, 2, "���μ�")));
//	
//	IdolGroups.insert(make_pair("�۰��",
//		IdolGroup("�۰��",Gender::Boy,1979,6,"��ö��")));
//	
//	auto koyote = make_pair("�ڿ���",
//		IdolGroup("�ڿ���", Gender::Hybrid, 1998, 3, "������ ���� ����"));
//	IdolGroups.insert(IdolGroups.begin(), koyote);
//	
//	IdolGroups.emplace("������",
//		IdolGroup("������", Gender::Girl, 2014, 4, "�ֶ� ���� ���� ȭ��"));
//
//	IdolGroups.insert_or_assign("����",
//		IdolGroup("����", Gender::Girl, 2019, 5, "���� ���� ���� ä�� ����"));
//
//	map<int, IdolGroup> IdolGroups2;
//	for (const auto& ig : IdolGroups)
//		IdolGroups2.emplace(ig.second.getYear(), ig.second);
//	for (const auto& ig : IdolGroups2)
//		ig.second.show();
//
//	cout << "*** ���̵� ôô�ڻ� *** " << endl;
//
//	while (true) {
//		cout << "�ñ��Ͻ� �׷��� �̸��� �Է��� �ּ���: ";
//		string name;
//		cin >> name;
//
//		map<string,IdolGroup>::iterator p = IdolGroups.find(name);
//		if (p != IdolGroups.end())
//			p->second.show();
//		else
//			cout << name << " - ���� �׷��Դϴ�." << endl;
//
//		cout << endl;
//	}
//
//
//}

/* ���� 2: ��ȭ��ȣ��*/
//int main()
//{
//	map<string, string> phoneBook;
//	phoneBook["��ȣ�ȳ�"] = "114";
//	phoneBook.emplace("�ϱ⿹��", "131");
//	phoneBook.insert(make_pair<string, string>("��������", "1333"));
//	phoneBook["�������Ű�"] = "123";
//	phoneBook["���̹��׷�"] = "118";
//
//	for (const auto& [name, number] : phoneBook)
//		cout << name << ": " << number << endl;
//}

/* �ܾ� ���Ƚ�� ��� (include: fstream,string)*/
int main()
{
	cout << " ���� ������ ? ";
	string name;
	cin >> name;
	
	ifstream in(name);
	if (!in) {
		cout << name << " - ���� ���� ���� " << endl;
		return 0;
	}
	
	map<string, int> words;

	string str;
	while (in >> str) {
		words.insert_or_assign(str, words[str] + 1);
		//words[str]++;
	}
		
	/*�ǽ� 1*/
	/*while (true) {
		cout << "ã�� �ܾ��? ";
		cin >> name;

		if (words.find(name) != words.end())
			cout << name << " - " << words[name] << endl;
		else
			cout << "���� �ܾ��Դϴ�." << endl;
	}*/

	/*�ǽ� 2*/
	map<int, pair<string, int>> words_sortbynum;

	// key ���� ������ �����Ͽ� ������������ ����
	for (const auto& [name, num] : words)
		words_sortbynum[-num] = make_pair(name, num);

	for (const auto& [num, word] : words_sortbynum)
		cout << word.first << " - " << word.second << endl;
	
}