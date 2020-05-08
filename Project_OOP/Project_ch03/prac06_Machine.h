// 머신 헤더파일입니다.
#pragma once
#include "prac06_Animal.h"

class Machine
{
public:
	Machine();
	~Machine();
private:
	Animal* pAnimals;	// 설정된 동물들을 가리킬 포인터
	int nAnimal;		// 동물들의 수
	int time;			// 시간
public:
	void Count();			// 시간을 잰다.
	void Feeding();			// 먹이를 먹인다.
	void setAnimals(Animal);// 동물을 설정한다.
};

