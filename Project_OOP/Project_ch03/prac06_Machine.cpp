#include "prac06_Machine.h"
#include <iostream>
#include <thread>

Machine::Machine()
{
	time = 0;
	nAnimal = 0;
	pAnimals = new Animal[10];	// ���Ƿ� �ִ� ���� ���� ������ ���� 10������ ���Ѵ�.
}

Machine::~Machine()
{
	delete pAnimals;
}

void Machine::Count()
{
	
	int time_division{ 1 };	// ����� time �ð��� int ������ �ʰ����� �ʵ��� ������ ����
	for (int i = 0; i < nAnimal; ++i) time_division *= pAnimals[i].getTHungry();	// �� �������� ����� �ֱ��� �ð��� �����ش�.
	if (time_division % 24 != 0)
		time_division *= 24;		// ������ ���� 24�� ������� ������ �������� �� �ð��� ��ȭ�� ����.(24�ð� ����)
	time = (++time) % time_division;

	cout << time % 24 << "�� �Դϴ�." << endl;
	for (int i = 0; i < nAnimal; ++i) {
		pAnimals[i].setTimer(time);		// ���� �ð��� �� �������� �����ִ� Ÿ�̸ӿ� �����Ѵ�.
	}
	Feeding();							// ����� �����鿡�� ���̸� �ش�.
	this_thread::sleep_for(1000ms);		// 1�ʸ� ������Ŵ (���Ƿ� 1�ð����� ����)
}
void Machine::Feeding()
{
	for (int i = 0; i < nAnimal; ++i) {	// ������ �����鿡��
		if (pAnimals[i].isHungry()) {	// ���� ������ٸ�
			pAnimals[i].Eat();			// �������� �԰� �Ѵ�
		}
	}
}

void Machine::setAnimals(Animal animal)
{
	pAnimals[nAnimal++] = animal;	// �Է¹��� ������ ��迡 �����Ѵ�.
}