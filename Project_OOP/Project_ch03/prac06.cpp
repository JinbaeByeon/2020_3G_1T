// �� �ִ� ��迡 ��Ḧ �� �������� �����ؼ� �������� ����� �ֱ⸶�� ���� �ִ� ���α׷�

#include <iostream>
#include "prac06_Machine.h"
#include "prac06_Cat.h"




int main()
{
	Machine machine; // �� �ִ� ���

	machine.setAnimals(Dog("�����"));	// ���� ��迡 ����
	machine.setAnimals(Cat("�ɳ���"));	// ����̸� ��迡 ����
	
	while (1) {
		machine.Count();	// ��踦 �۵���Ų��.
	}

}