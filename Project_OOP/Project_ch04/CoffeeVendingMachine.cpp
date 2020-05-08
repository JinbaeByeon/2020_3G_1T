#include "CoffeeVendingMachine.h"
#include <iostream>
using namespace std;

void CoffeeVendingMachine::fill()
{
	for (int i = 0; i < 3; ++i) {
		tong[i].fill(10);
	}
	show();
}

void CoffeeVendingMachine::selectEspresso()
{
	if (tong[0].consume(1)) {
		if (tong[1].consume(1)) {
			cout << "���������� ���Խ��ϴ�." << endl;
			return;
		}
		// ���� �����ϸ� �Ҹ��� Ŀ�� ��ȯ
		tong[0].fill(1);
	}
	cout << "���ᰡ �����մϴ�." << endl;
}

void CoffeeVendingMachine::selectAmericano()
{
	if (tong[0].consume(1)) {
		if (tong[1].consume(2)) {
			cout << "�Ƹ޸�ī�� ���Խ��ϴ�." << endl;
			return;
		}
		// ���� �����ϸ� �Ҹ��� Ŀ�� ��ȯ
		tong[0].fill(1);
	}
	cout << "���ᰡ �����մϴ�." << endl;
}

void CoffeeVendingMachine::selectSugarCoffee()
{

	if (tong[0].consume(1)) {
		if (tong[1].consume(2)) {
			if (tong[2].consume(1)) {
				cout << "����Ŀ�� ���Խ��ϴ�." << endl;
				return;
			}
			// ������ �����ϸ� �Ҹ��� �� ��ȯ
			tong[1].fill(2);
		}
		// ���� �Ǵ� ���� �����ϸ� �Ҹ��� Ŀ�� ��ȯ
		tong[0].fill(1);
	}
	cout << "���ᰡ �����մϴ�." << endl;
}

void CoffeeVendingMachine::show()
{
	cout << "Ŀ��: " << tong[0].getSize();
	cout << ", ��: " << tong[1].getSize();
	cout << ", ����: " << tong[2].getSize() << endl;
}

bool CoffeeVendingMachine::checkInputError()
{
	// ��� ���� ó���� �ϴ°��� �𸣰ڽ��ϴ�.
}

void CoffeeVendingMachine::run()
{
	cout << "***** Ŀ�����ǱⰡ �����մϴ�. *****" << endl;
	int menu = -1;
	while (menu != 0) {
		cout << "�޴��� �����ּ���(1: ����������, 2: �Ƹ޸�ī��, 3: ����Ŀ��, 4: �ܷ�����, 5 : ä���, 0: ������) >>";
		cin >> menu;
		switch (menu) {
		case 1:	// ����������
			selectEspresso();
			break;
		case 2:	// �Ƹ޸�ī��
			selectAmericano();
			break;
		case 3:	// ����Ŀ��
			selectSugarCoffee();
			break;
		case 4:	// �ܷ�����
			show();
			break;
		case 5:	// ä���
			fill();
			break;
		}
	}
}
