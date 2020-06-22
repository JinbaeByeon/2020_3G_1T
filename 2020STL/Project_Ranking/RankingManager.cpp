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
normal_distribution nd{ 0.,1. };
uniform_int_distribution uidRandomPlayer{ 0,NUM_PLAYER - 1 };
int countID = 0;

class Player {
	string id = "";
	unsigned int breakout = 0;
	unsigned int championsLeague = 0;

	unsigned int seasonBO = 0;	// BreakOut의 최고점을 얻은 시즌
	unsigned int seasonCL = 0;	// ChampioonsLeague의 최고점을 얻은 시즌
public:
	Player() {};
	Player(string id) :id(id) {}

	string GetID() const { return id; }
	unsigned int GetBreakOut() const { return breakout; }
	unsigned int GetChampionsLeague() const { return championsLeague; }
	void SetBreakOut(unsigned int score) { breakout = score; }
	void SetChampionsLeague(unsigned int score) { championsLeague = score; }

	int GetSeasonBO() const {
		return seasonBO;
	}
	int GetSeasonCL() const {
		return seasonCL;
	}
	void SetSeasonBO(int season) {
		seasonBO = season;
	}
	void SetSeasonCL(int season) {
		seasonCL = season;
	}

	Player& operator=(const Player& rhs) {
		id = rhs.id;
		breakout = rhs.breakout;
		championsLeague = rhs.championsLeague;
		seasonBO = rhs.seasonBO;
		seasonCL = rhs.seasonCL;
		return *this;
	}
	bool operator==(const Player& rhs) const {
		return id == rhs.id;
	}
};

void ShowRanking(const vector<Player>& vPlayer, const vector<Player>& vBreakOut, const vector<Player>& vChampions, const string& id);

void StartSeason(vector<Player>& vPlayer,const int season);

enum MENU {
	종료,
	시즌시작,
	플레이어검색,
	떼탈출_랭킹100,
	챔피언스리그_랭킹100
};


int main()
{
	vector<Player> vPlayer;
	string str, id;
	int menu = 시즌시작, season = 0;

	cout << "파일명: ";
	cin >> str;
	ifstream in{ str,ios::binary };
	if (!in) {	// 파일이 없을 시 초기화
		vPlayer.reserve(NUM_PLAYER);
		double n;
		while (countID != NUM_PLAYER) {
			Player tmp(to_string(countID++));
			n = { clamp(nd(dre), -5., 5.) + 5. };
			tmp.SetBreakOut(n * 290'588'702.6);

			n = { clamp(nd(dre), -5., 5.) + 5. };
			tmp.SetChampionsLeague(n * 111'267'038.4);

			vPlayer.emplace_back(tmp);
		}
	}
	else {	// 파일이 있으면 플레이어 데이터를 읽어옴
		vPlayer.resize(NUM_PLAYER);
		in.read((char*)vPlayer.data(), sizeof(Player) * NUM_PLAYER);
		in.read((char*)&season, sizeof(season));
		in.close();
	}
	
	vector<Player> vChampionsLeague = vPlayer, vBreakOut = vPlayer;

	sort(vBreakOut.begin(), vBreakOut.end(), [](const Player& a, const  Player& b) {
		if (a.GetBreakOut() == b.GetBreakOut())
			return a.GetSeasonBO() < b.GetSeasonBO();
		return a.GetBreakOut() > b.GetBreakOut();
		});

	sort(vChampionsLeague.begin(), vChampionsLeague.end(), [](const Player& a, const Player& b) {
		if (a.GetChampionsLeague() == b.GetChampionsLeague())
			return a.GetSeasonCL() < b.GetSeasonCL();
		return a.GetChampionsLeague() > b.GetChampionsLeague();
		});

	while (menu != 종료) {
		cout << "0: 종료, 1: 시즌시작, 2: 플레이어 검색, 3: 떼탈출 랭킹100, 4: 챔피언스리그 랭킹100" << endl;
		cout << "------------------------------ " << season << "시즌 ------------------------------" << endl;
		cin >> menu;
		switch (menu) {
		case 시즌시작:
			StartSeason(vPlayer, season);
			vBreakOut = vChampionsLeague = vPlayer;

			sort(vBreakOut.begin(), vBreakOut.end(), [](const Player& a, const  Player& b) {
				if (a.GetBreakOut() == b.GetBreakOut())
					return a.GetSeasonBO() < b.GetSeasonBO();
				return a.GetBreakOut() > b.GetBreakOut();
				});

			sort(vChampionsLeague.begin(), vChampionsLeague.end(), [](const Player& a, const Player& b) {
				if (a.GetChampionsLeague() == b.GetChampionsLeague())
					return a.GetSeasonCL() < b.GetSeasonCL();
				return a.GetChampionsLeague() > b.GetChampionsLeague();
				});

			cout << ++season << "시즌 종료" << endl;
			break;
		case 플레이어검색:
			cout << "Player ID: ";
			cin >> id;
			ShowRanking(vPlayer, vBreakOut, vChampionsLeague, id);
			break;
		case 떼탈출_랭킹100: {
			int cnt = 0;
			for (const auto& a : vBreakOut) {
				cout << setw(3) << ++cnt << "등 - ID: " << setw(6) << a.GetID() << " 점수: " << a.GetBreakOut() << " 시즌: " << a.GetSeasonBO() << endl;
				if (cnt == 100) break;
			}
		}
			break;
		case 챔피언스리그_랭킹100: {
			int cnt = 0;
			for (const auto& a : vChampionsLeague) {
				cout << setw(3) << ++cnt << "등 - ID: " << setw(6) << a.GetID() << " 점수: " << a.GetChampionsLeague() << " 시즌: " << a.GetSeasonCL() << endl;
				if (cnt == 100) break;
			}
		}
			break;
		}
	}

	ofstream out{ str,ios::binary };
	out.write((char*)vPlayer.data(), sizeof(Player) * NUM_PLAYER);
	out.write((char*)&season, sizeof(season));
	out.close();
}


void ShowRanking(const vector<Player>& vPlayer, const vector<Player>& vBreakOut, const vector<Player>& vChampions, const string& id)
{
	if (binary_search(vPlayer.begin(), vPlayer.end(), Player(id), [](const Player& a, const Player& b) {
		return stoi(a.GetID()) < stoi(b.GetID()); })) {
		// id가 일치하는 Player의 index(0~99'999)를 vPlayer에서 찾는다. (id 비교, vPlayer는 ID 오름차순)
		size_t idxPlayer = lower_bound(vPlayer.begin(), vPlayer.end(), Player(id), [](const Player& a, const Player& b) {
			return stoi(a.GetID()) < stoi(b.GetID());
			}) - vPlayer.begin();

		// vBreakout에서 해당 플레이어의 index(0~99'999)를 찾는다. (BreakOut의 점수 비교, vBreakOut은 BreakOut 점수 내림차순)
		size_t idx = lower_bound(vBreakOut.begin(), vBreakOut.end(), vPlayer[idxPlayer], [](const Player& a, const Player& b) {
			return a.GetBreakOut() > b.GetBreakOut();
			}) - vBreakOut.begin();

		// 만약 같은 점수를 가진 플레이어가 존재해서 해당 index의 플레이어ID가 원하는 플레이어의 ID가 아니라면 index를 증가시킨다. (해당 index가 동일 점수의 가장 작은 index일 것이기 때문에)
		while (vBreakOut[idx].GetID() != id)
			++idx;

		// 소수점 첫 번째 자리까지 출력
		cout << fixed << setprecision(1);
		
		// BreakOut 출력
		if (idx != 0) {
			cout << '\t' << setw(5) <<
				vBreakOut[idx - 1].GetID() << setw(6) <<
				idx  << "등 상위" << setw(5) <<
				(double)(idx) * 100 / NUM_PLAYER << "% 점수 " <<
				vBreakOut[idx - 1].GetBreakOut() << endl;
		}
		cout << "떼탈출 " << setw(6) <<
			id << setw(6) <<
			idx + 1 << "등 상위" << setw(5) <<
			(double)(idx + 1) * 100 / NUM_PLAYER << "% 점수 " <<
			vBreakOut[idx].GetBreakOut() << endl;
		if (idx != NUM_PLAYER - 1) {
			cout << '\t' << setw(5) <<
				vBreakOut[idx + 1].GetID() << setw(6) <<
				idx + 2 << "등 상위" << setw(5) <<
				(double)(idx + 2) * 100 / NUM_PLAYER << "% 점수 " <<
				vBreakOut[idx + 1].GetBreakOut() << endl;
		}
		cout << endl;
		// BreakOut 출력

		// vChampions에서 해당 플레이어의 index(0~99'999)를 찾는다. (ChampionsLeague의 점수 비교, vChampions는 BreakOut 점수 내림차순)
		idx = lower_bound(vChampions.begin(), vChampions.end(), vPlayer[idxPlayer], [](const Player& a, const Player& b) {
			return a.GetChampionsLeague() > b.GetChampionsLeague();
			}) - vChampions.begin();

		// 만약 같은 점수를 가진 플레이어가 존재해서 해당 index의 플레이어ID가 원하는 플레이어의 ID가 아니라면 index를 증가시킨다. (해당 index가 동일 점수의 가장 작은 index일 것이기 때문에)
		while (vChampions[idx].GetID() != id)
			++idx;

		// 챔피언스리그 출력
		if (idx != 0) {
			cout << '\t' << setw(10) <<
				vChampions[idx - 1].GetID() << setw(6) <<
				idx << "등 상위" << setw(5) <<
				(double)(idx) * 100 / NUM_PLAYER << "% 점수 " <<
				vChampions[idx - 1].GetChampionsLeague() << endl;
		}
		cout << "챔피언스리그 " << setw(5) <<
			id << setw(6) <<
			idx + 1 << "등 상위" << setw(5) <<
			(double)(idx + 1) * 100 / NUM_PLAYER << "% 점수 " <<
			vChampions[idx].GetChampionsLeague() << endl;
		if (idx != NUM_PLAYER - 1) {
			cout << '\t' << setw(10) <<
				vChampions[idx + 1].GetID() << setw(6) <<
				idx + 2 << "등 상위" << setw(5) <<
				(double)(idx + 2) * 100 / NUM_PLAYER << "% 점수 " <<
				vChampions[idx + 1].GetChampionsLeague() << endl;
		}
		cout << endl;
		// 챔피언스리그 출력
	}
	else {
		cout << "플레이어 " << id << "가 존재하지 않습니다." << endl;
		return;
	}
}

void StartSeason(vector<Player>& vPlayer,const int season)
{
	double n;
	unique_ptr<bool[]> isPlay{ new bool[NUM_PLAYER] {false,} };
	int idx, cnt = 0;

	// 임의의 5만명이 BreakOut 플레이
	while (cnt < NUM_PLAYER / 2) {
		idx = uidRandomPlayer(dre);
		if (!isPlay[idx]) {
			n = (clamp(nd(dre), -5., 5.) + 5.) * 290'588'702.6;
			if (n > vPlayer[idx].GetBreakOut()) {
				vPlayer[idx].SetBreakOut(n);
				vPlayer[idx].SetSeasonBO(season);
			}
			isPlay[idx] = true;
			++cnt;
		}
	}

	cnt = 0;
	isPlay.reset(new bool[NUM_PLAYER] {false, });
	// 임의의 5만명이 ChampionsLeague 플레이
	while (cnt < NUM_PLAYER / 2) {
		idx = uidRandomPlayer(dre);
		if (!isPlay[idx]) {
			n = (clamp(nd(dre), -5., 5.) + 5.) * 111'267'038.4;
			if (n > vPlayer[idx].GetChampionsLeague()) {
				vPlayer[idx].SetChampionsLeague(n);
				vPlayer[idx].SetSeasonCL(season);
			}
			isPlay[idx] = true;
			++cnt;
		}
	}
}