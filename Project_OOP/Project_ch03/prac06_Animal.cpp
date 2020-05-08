// 동물 클래스 구현부
#include "prac06_Animal.h"
#include <iostream>

Animal::Animal(string name) : name{ name } {}

void Animal::setTimer(int time)
{
	timer = time;
	if (timer % tHungry == 0) {	// 시간이 배고픈 주기에 나누어 떨어진다면 배고픔을 느끼고 이에 대한 출력을 함
		hungry = true;			
		cout << species << " - " << name << "(이)가 배고픔을 느낀다." << endl;	
	}
}

bool Animal::isHungry()
{
	return hungry ? true : false;	// 배고프면 true 아니면 false
}

void Animal::Eat()
{
	hungry = false;
	cout << species << " - " << name << "(이)가 먹이를 먹었다." << endl;
}

 int Animal::getTHungry()
{
	return tHungry;
}