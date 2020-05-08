// 동물 클래스 선언부

#pragma once
#include <string>
using namespace std;

class Animal
{
public:
	Animal() {};
	Animal(string);
protected:
	string name{};	// 이름
	bool hungry{};	// 배고픈지 아닌지 구분하는 변수
	int timer{};	// 밥 먹고 시간이 얼마나 지났는지 나타내는 변수
	int tHungry{};	// 각 동물들의 배고픔 주기 시간
	string species;	// 동물의 종을 나타냄
public:
	virtual bool isHungry();			// 배고픈지 아닌지 판별하는 함수
	virtual void setTimer(int time);	// 받은 시간을 타이머에 입력하는 함수
	virtual void Eat();				
	virtual int getTHungry();			// 배고픔 주기를 알려주는 함수
};

