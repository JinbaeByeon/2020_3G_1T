#include <iostream>
#include <random>
#include <fstream>
#include <vector>
#include <thread>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

#define NUM_PLAYER 100'000

random_device rd;
default_random_engine dre{ rd() };
normal_distribution nd{ 0.f,1.f };
int countID = 0;

class Player {
	string id = "";
	unsigned int breakout = 0;
	unsigned int championsLeague = 0;

public:
	Player() {};
	Player(string id) :id(id) {}
		
	string GetID() const { return id; }
	unsigned int GetBreakOut() const { return breakout; }
	unsigned int GetChampionsLeague() const { return championsLeague; }
	void SetBreakOut(unsigned int score) { breakout = score; }
	void SetChampionsLeague(unsigned int score) { championsLeague = score; }

	Player& operator=(const Player& rhs) {
		id = rhs.id;
		breakout = rhs.breakout;
		championsLeague = rhs.championsLeague;
		return *this;
	}
	bool operator==(const Player& rhs) const {
		return id == rhs.id;
	}

};

void ShowRanking(const vector<Player>& vBreakOut, const vector<Player>& vChampions,const string& id);

void StartSeason(vector<Player>& vPlayer);

enum MENU{
	종료,
	시즌시작,
	플레이어검색,
	떼탈출_랭킹100,
	챔피언스리그_랭킹100
};


int main()
{

	vector<Player> vPlayer;

	ifstream in{ "랭킹",ios::binary };
	if (!in) {	// 파일이 없을 시 초기화
		vPlayer.reserve(NUM_PLAYER);
		float n;
		while (countID != NUM_PLAYER) {
			Player tmp(to_string(countID++));
			n = { clamp(nd(dre), -5.f, 5.f) + 5.f };
			tmp.SetBreakOut(n * 290'588'702.6f);

			n = { clamp(nd(dre), -5.f, 5.f) + 5.f };
			tmp.SetChampionsLeague(n * 111'267'038.4f);

			vPlayer.emplace_back(tmp);
		}
	}
	else {
		vPlayer.resize(NUM_PLAYER);
		in.read((char*)vPlayer.data(), sizeof(Player) * NUM_PLAYER);
		in.close();		
	}

	vector<Player> vChampionsLeague = vPlayer;
	
	sort(vPlayer.begin(), vPlayer.end(), [](const Player& a, const Player& b) {
		return a.GetBreakOut() > b.GetBreakOut();
		});
	sort(vChampionsLeague.begin(), vChampionsLeague.end(), [](const Player& a, const Player& b) {
		return a.GetChampionsLeague() > b.GetChampionsLeague();
		});
	int menu = 시즌시작;
	string id;
	int cnt = 0;
	while (menu != 종료) {
		cout << "0: 종료, 1: 시즌시작, 2: 플레이어 검색, 3: 떼탈출 랭킹100, 4: 챔피언스리그 랭킹100" << endl;
		cin >> menu;
		switch (menu) {
		case 시즌시작:
			StartSeason(vPlayer);
			vChampionsLeague = vPlayer;
			sort(vPlayer.begin(), vPlayer.end(), [](const Player& a, const Player& b) {
				});
			break;
		case 플레이어검색:
			cout << "Player ID: ";
			cin >> id;
			ShowRanking(vPlayer,vChampionsLeague, id);
			break;
		case 떼탈출_랭킹100:
			for (const auto& a : vPlayer) {
				cout << a.GetID() << " " << a.GetBreakOut() << endl;
				if (++cnt == 100) break;
			}
			cnt = 0;
			break;
		case 챔피언스리그_랭킹100:
			for (const auto& a : vChampionsLeague) {
				cout << a.GetID() << " " << a.GetChampionsLeague() << endl;
				if (++cnt == 100) break;
			}
			cnt = 0;
			break;
		}
	}

	ofstream out{ "랭킹",ios::binary };
	out.write((char*)vPlayer.data(), sizeof(Player) * NUM_PLAYER);
	out.close();
}


void ShowRanking(const vector<Player>& vBreakOut, const vector<Player>& vChampions,const string& id)
{
	auto p = find(vBreakOut.begin(), vBreakOut.end(), Player(id));
	if (p == vBreakOut.end()) {
		cout << "플레이어 " << id << "가 존재하지 않습니다." << endl;
		return;
	}
	size_t idx = p - vBreakOut.begin();
	cout << fixed << setprecision(1);
	
	
	if (idx != 0) {
		cout << '\t' << setw(4) << vBreakOut.at(idx - 1).GetID() << setw(6) << idx << "등 상위" <<
			setw(5) << (float)(idx) * 100 / NUM_PLAYER << "% 점수 " << vBreakOut.at(idx - 1).GetBreakOut() << endl;
	}
	cout << "떼탈출 " << setw(6) << id << setw(6) << idx + 1 << "등 상위" << 
		setw(5) << (float)(idx+1) * 100 / NUM_PLAYER << "% 점수 " << vBreakOut.at(idx).GetBreakOut() << endl;
	if (idx != NUM_PLAYER - 1) {
		cout << '\t' << setw(4) << vBreakOut.at(idx + 1).GetID() << setw(6) << idx + 2 << "등 상위" <<
			setw(5) << (float)(idx + 2) * 100 / NUM_PLAYER << "% 점수 " << vBreakOut.at(idx + 1).GetBreakOut() << endl;
	}
	cout << endl;

	idx = find(vChampions.begin(), vChampions.end(), Player(id)) - vChampions.begin();
	if (idx != 0) {
		cout << '\t' << setw(10)<< vChampions.at(idx - 1).GetID() << setw(6) << idx << "등 상위" <<
			setw(5) << (float)(idx) * 100 / NUM_PLAYER << "% 점수 " << vChampions.at(idx - 1).GetChampionsLeague() << endl;
	}
	cout << "챔피언스리그 " << setw(5) << id << setw(6) << idx + 1 << "등 상위" <<
		setw(5) << (float)(idx + 1) * 100 / NUM_PLAYER << "% 점수 " << vChampions.at(idx).GetChampionsLeague() << endl;
	if (idx != NUM_PLAYER - 1) {
		cout << '\t' << setw(10) << vChampions.at(idx + 1).GetID() << setw(6) << idx + 2 << "등 상위" <<
			setw(5) << (float)(idx + 2) * 100 / NUM_PLAYER << "% 점수 " << vChampions.at(idx + 1).GetChampionsLeague() << endl;
	}
	cout << endl;
}

void StartSeason(vector<Player>& vPlayer)
{
	float n;
	for (int i = 0; i < NUM_PLAYER; ++i) {
		if (i < NUM_PLAYER / 2) {
			n = (clamp(nd(dre), -5.f, 5.f) + 5.f) * 290'588'702.6f;
			if (n > vPlayer[i].GetBreakOut())
				vPlayer[i].SetBreakOut(n);
		}
		else {
			n = (clamp(nd(dre), -5.f, 5.f) + 5.f) * 111'267'038.4f;
			if (n > vPlayer[i].GetChampionsLeague())
				vPlayer[i].SetChampionsLeague(n);
		}
	}
		
}