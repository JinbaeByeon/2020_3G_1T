// �ӽ� ��������Դϴ�.
#pragma once
#include "prac06_Animal.h"

class Machine
{
public:
	Machine();
	~Machine();
private:
	Animal* pAnimals;	// ������ �������� ����ų ������
	int nAnimal;		// �������� ��
	int time;			// �ð�
public:
	void Count();			// �ð��� ���.
	void Feeding();			// ���̸� ���δ�.
	void setAnimals(Animal);// ������ �����Ѵ�.
};

