// ���� Ŭ���� �����

#pragma once
#include <string>
using namespace std;

class Animal
{
public:
	Animal() {};
	Animal(string);
protected:
	string name{};	// �̸�
	bool hungry{};	// ������� �ƴ��� �����ϴ� ����
	int timer{};	// �� �԰� �ð��� �󸶳� �������� ��Ÿ���� ����
	int tHungry{};	// �� �������� ����� �ֱ� �ð�
	string species;	// ������ ���� ��Ÿ��
public:
	virtual bool isHungry();			// ������� �ƴ��� �Ǻ��ϴ� �Լ�
	virtual void setTimer(int time);	// ���� �ð��� Ÿ�̸ӿ� �Է��ϴ� �Լ�
	virtual void Eat();				
	virtual int getTHungry();			// ����� �ֱ⸦ �˷��ִ� �Լ�
};

