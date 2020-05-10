#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

/* 예제 1: 아이돌 그룹 map (include: iomanip)*/
//enum class Gender { Boy, Girl, Hybrid };
//string Genders[]{ "보이그룹","걸그룹","혼성그룹" };
//
//class IdolGroup {
//	string groupName;		// 그룹 이름
//	Gender gender;			// 성별
//	int year;				// 데뷔 년도
//	int num;				// 인원 수
//	string member;			// 멤버들
//
//public:
//	explicit IdolGroup(string gn, Gender g, int y, int n, string m)
//		:groupName(gn), gender(g), year(y), num(n), member(m) {}
//	
//	void show() const {
//		cout << " 이름 :" << left << setw(14) << groupName << setw(8)
//			 << Genders[static_cast<int>(gender)] << ", " << year << " 년, "
//			 << num << " 명, 멤버 - " << member << endl;
//	}
//	int getYear() const { return year; }
//};
//
//int main()
//{
//	map<string, IdolGroup> IdolGroups;
//
//	IdolGroups.insert(pair<string, IdolGroup>("펄 시스터즈",
//		IdolGroup("펄 시스터즈", Gender::Girl, 1968, 2, "배인순")));
//	
//	IdolGroups.insert(make_pair("송골매",
//		IdolGroup("송골매",Gender::Boy,1979,6,"배철수")));
//	
//	auto koyote = make_pair("코요태",
//		IdolGroup("코요태", Gender::Hybrid, 1998, 3, "김종민 신지 빽가"));
//	IdolGroups.insert(IdolGroups.begin(), koyote);
//	
//	IdolGroups.emplace("마마무",
//		IdolGroup("마마무", Gender::Girl, 2014, 4, "솔라 문별 휘인 화사"));
//
//	IdolGroups.insert_or_assign("있지",
//		IdolGroup("있지", Gender::Girl, 2019, 5, "예지 리아 류진 채령 유리"));
//
//	map<int, IdolGroup> IdolGroups2;
//	for (const auto& ig : IdolGroups)
//		IdolGroups2.emplace(ig.second.getYear(), ig.second);
//	for (const auto& ig : IdolGroups2)
//		ig.second.show();
//
//	cout << "*** 아이돌 척척박사 *** " << endl;
//
//	while (true) {
//		cout << "궁금하신 그룹의 이름을 입력해 주세요: ";
//		string name;
//		cin >> name;
//
//		map<string,IdolGroup>::iterator p = IdolGroups.find(name);
//		if (p != IdolGroups.end())
//			p->second.show();
//		else
//			cout << name << " - 없는 그룹입니다." << endl;
//
//		cout << endl;
//	}
//
//
//}

/* 예제 2: 전화번호부*/
//int main()
//{
//	map<string, string> phoneBook;
//	phoneBook["번호안내"] = "114";
//	phoneBook.emplace("일기예보", "131");
//	phoneBook.insert(make_pair<string, string>("교통정보", "1333"));
//	phoneBook["전기고장신고"] = "123";
//	phoneBook["사이버테러"] = "118";
//
//	for (const auto& [name, number] : phoneBook)
//		cout << name << ": " << number << endl;
//}

/* 단어 사용횟수 출력 (include: fstream,string)*/
int main()
{
	cout << " 읽을 파일은 ? ";
	string name;
	cin >> name;
	
	ifstream in(name);
	if (!in) {
		cout << name << " - 파일 열기 실패 " << endl;
		return 0;
	}
	
	map<string, int> words;

	string str;
	while (in >> str) {
		words.insert_or_assign(str, words[str] + 1);
		//words[str]++;
	}
		
	/*실습 1*/
	/*while (true) {
		cout << "찾는 단어는? ";
		cin >> name;

		if (words.find(name) != words.end())
			cout << name << " - " << words[name] << endl;
		else
			cout << "없는 단어입니다." << endl;
	}*/

	/*실습 2*/
	map<int, pair<string, int>> words_sortbynum;

	// key 값을 음수로 저장하여 오름차순으로 저장
	for (const auto& [name, num] : words)
		words_sortbynum[-num] = make_pair(name, num);

	for (const auto& [num, word] : words_sortbynum)
		cout << word.first << " - " << word.second << endl;
	
}