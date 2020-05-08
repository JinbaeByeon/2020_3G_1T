// ���� Ŭ���� ������
#include "prac06_Animal.h"
#include <iostream>

Animal::Animal(string name) : name{ name } {}

void Animal::setTimer(int time)
{
	timer = time;
	if (timer % tHungry == 0) {	// �ð��� ����� �ֱ⿡ ������ �������ٸ� ������� ������ �̿� ���� ����� ��
		hungry = true;			
		cout << species << " - " << name << "(��)�� ������� ������." << endl;	
	}
}

bool Animal::isHungry()
{
	return hungry ? true : false;	// ������� true �ƴϸ� false
}

void Animal::Eat()
{
	hungry = false;
	cout << species << " - " << name << "(��)�� ���̸� �Ծ���." << endl;
}

 int Animal::getTHungry()
{
	return tHungry;
}