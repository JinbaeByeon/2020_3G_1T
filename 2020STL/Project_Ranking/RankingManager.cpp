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

	unsigned int seasonBO = 0;	// BreakOut�� �ְ����� ���� ����
	unsigned int seasonCL = 0;	// ChampioonsLeague�� �ְ����� ���� ����
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
	����,
	�������,
	�÷��̾�˻�,
	��Ż��_��ŷ100,
	è�Ǿ𽺸���_��ŷ100
};


int main()
{
	vector<Player> vPlayer;
	string str, id;
	int menu = �������, season = 0;

	cout << "���ϸ�: ";
	cin >> str;
	ifstream in{ str,ios::binary };
	if (!in) {	// ������ ���� �� �ʱ�ȭ
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
	else {	// ������ ������ �÷��̾� �����͸� �о��
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

	while (menu != ����) {
		cout << "0: ����, 1: �������, 2: �÷��̾� �˻�, 3: ��Ż�� ��ŷ100, 4: è�Ǿ𽺸��� ��ŷ100" << endl;
		cout << "------------------------------ " << season << "���� ------------------------------" << endl;
		cin >> menu;
		switch (menu) {
		case �������:
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

			cout << ++season << "���� ����" << endl;
			break;
		case �÷��̾�˻�:
			cout << "Player ID: ";
			cin >> id;
			ShowRanking(vPlayer, vBreakOut, vChampionsLeague, id);
			break;
		case ��Ż��_��ŷ100: {
			int cnt = 0;
			for (const auto& a : vBreakOut) {
				cout << setw(3) << ++cnt << "�� - ID: " << setw(6) << a.GetID() << " ����: " << a.GetBreakOut() << " ����: " << a.GetSeasonBO() << endl;
				if (cnt == 100) break;
			}
		}
			break;
		case è�Ǿ𽺸���_��ŷ100: {
			int cnt = 0;
			for (const auto& a : vChampionsLeague) {
				cout << setw(3) << ++cnt << "�� - ID: " << setw(6) << a.GetID() << " ����: " << a.GetChampionsLeague() << " ����: " << a.GetSeasonCL() << endl;
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
		// id�� ��ġ�ϴ� Player�� index(0~99'999)�� vPlayer���� ã�´�. (id ��, vPlayer�� ID ��������)
		size_t idxPlayer = lower_bound(vPlayer.begin(), vPlayer.end(), Player(id), [](const Player& a, const Player& b) {
			return stoi(a.GetID()) < stoi(b.GetID());
			}) - vPlayer.begin();

		// vBreakout���� �ش� �÷��̾��� index(0~99'999)�� ã�´�. (BreakOut�� ���� ��, vBreakOut�� BreakOut ���� ��������)
		size_t idx = lower_bound(vBreakOut.begin(), vBreakOut.end(), vPlayer[idxPlayer], [](const Player& a, const Player& b) {
			return a.GetBreakOut() > b.GetBreakOut();
			}) - vBreakOut.begin();

		// ���� ���� ������ ���� �÷��̾ �����ؼ� �ش� index�� �÷��̾�ID�� ���ϴ� �÷��̾��� ID�� �ƴ϶�� index�� ������Ų��. (�ش� index�� ���� ������ ���� ���� index�� ���̱� ������)
		while (vBreakOut[idx].GetID() != id)
			++idx;

		// �Ҽ��� ù ��° �ڸ����� ���
		cout << fixed << setprecision(1);
		
		// BreakOut ���
		if (idx != 0) {
			cout << '\t' << setw(5) <<
				vBreakOut[idx - 1].GetID() << setw(6) <<
				idx  << "�� ����" << setw(5) <<
				(double)(idx) * 100 / NUM_PLAYER << "% ���� " <<
				vBreakOut[idx - 1].GetBreakOut() << endl;
		}
		cout << "��Ż�� " << setw(6) <<
			id << setw(6) <<
			idx + 1 << "�� ����" << setw(5) <<
			(double)(idx + 1) * 100 / NUM_PLAYER << "% ���� " <<
			vBreakOut[idx].GetBreakOut() << endl;
		if (idx != NUM_PLAYER - 1) {
			cout << '\t' << setw(5) <<
				vBreakOut[idx + 1].GetID() << setw(6) <<
				idx + 2 << "�� ����" << setw(5) <<
				(double)(idx + 2) * 100 / NUM_PLAYER << "% ���� " <<
				vBreakOut[idx + 1].GetBreakOut() << endl;
		}
		cout << endl;
		// BreakOut ���

		// vChampions���� �ش� �÷��̾��� index(0~99'999)�� ã�´�. (ChampionsLeague�� ���� ��, vChampions�� BreakOut ���� ��������)
		idx = lower_bound(vChampions.begin(), vChampions.end(), vPlayer[idxPlayer], [](const Player& a, const Player& b) {
			return a.GetChampionsLeague() > b.GetChampionsLeague();
			}) - vChampions.begin();

		// ���� ���� ������ ���� �÷��̾ �����ؼ� �ش� index�� �÷��̾�ID�� ���ϴ� �÷��̾��� ID�� �ƴ϶�� index�� ������Ų��. (�ش� index�� ���� ������ ���� ���� index�� ���̱� ������)
		while (vChampions[idx].GetID() != id)
			++idx;

		// è�Ǿ𽺸��� ���
		if (idx != 0) {
			cout << '\t' << setw(10) <<
				vChampions[idx - 1].GetID() << setw(6) <<
				idx << "�� ����" << setw(5) <<
				(double)(idx) * 100 / NUM_PLAYER << "% ���� " <<
				vChampions[idx - 1].GetChampionsLeague() << endl;
		}
		cout << "è�Ǿ𽺸��� " << setw(5) <<
			id << setw(6) <<
			idx + 1 << "�� ����" << setw(5) <<
			(double)(idx + 1) * 100 / NUM_PLAYER << "% ���� " <<
			vChampions[idx].GetChampionsLeague() << endl;
		if (idx != NUM_PLAYER - 1) {
			cout << '\t' << setw(10) <<
				vChampions[idx + 1].GetID() << setw(6) <<
				idx + 2 << "�� ����" << setw(5) <<
				(double)(idx + 2) * 100 / NUM_PLAYER << "% ���� " <<
				vChampions[idx + 1].GetChampionsLeague() << endl;
		}
		cout << endl;
		// è�Ǿ𽺸��� ���
	}
	else {
		cout << "�÷��̾� " << id << "�� �������� �ʽ��ϴ�." << endl;
		return;
	}
}

void StartSeason(vector<Player>& vPlayer,const int season)
{
	double n;
	unique_ptr<bool[]> isPlay{ new bool[NUM_PLAYER] {false,} };
	int idx, cnt = 0;

	// ������ 5������ BreakOut �÷���
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
	// ������ 5������ ChampionsLeague �÷���
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