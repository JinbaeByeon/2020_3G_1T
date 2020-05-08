#include "prac06_Machine.h"
#include <iostream>
#include <thread>

Machine::Machine()
{
	time = 0;
	nAnimal = 0;
	pAnimals = new Animal[10];	// 임의로 최대 설정 가능 동물의 수를 10마리로 정한다.
}

Machine::~Machine()
{
	delete pAnimals;
}

void Machine::Count()
{
	
	int time_division{ 1 };	// 기계의 time 시간이 int 범위를 초과하지 않도록 나눠줄 변수
	for (int i = 0; i < nAnimal; ++i) time_division *= pAnimals[i].getTHungry();	// 각 동물들의 배고픈 주기의 시간을 곱해준다.
	if (time_division % 24 != 0)
		time_division *= 24;		// 나누는 값이 24의 배수여야 나누어 떨어졌을 때 시간의 변화가 없다.(24시간 기준)
	time = (++time) % time_division;

	cout << time % 24 << "시 입니다." << endl;
	for (int i = 0; i < nAnimal; ++i) {
		pAnimals[i].setTimer(time);		// 현재 시간을 각 동물들이 갖고있는 타이머에 설정한다.
	}
	Feeding();							// 배고픈 동물들에게 먹이를 준다.
	this_thread::sleep_for(1000ms);		// 1초를 지연시킴 (임의로 1시간으로 생각)
}
void Machine::Feeding()
{
	for (int i = 0; i < nAnimal; ++i) {	// 설정된 동물들에게
		if (pAnimals[i].isHungry()) {	// 만약 배고프다면
			pAnimals[i].Eat();			// 동물들을 먹게 한다
		}
	}
}

void Machine::setAnimals(Animal animal)
{
	pAnimals[nAnimal++] = animal;	// 입력받은 동물을 기계에 설정한다.
}