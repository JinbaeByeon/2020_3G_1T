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
			cout << "에스프레소 나왔습니다." << endl;
			return;
		}
		// 물이 부족하면 소모한 커피 반환
		tong[0].fill(1);
	}
	cout << "원료가 부족합니다." << endl;
}

void CoffeeVendingMachine::selectAmericano()
{
	if (tong[0].consume(1)) {
		if (tong[1].consume(2)) {
			cout << "아메리카노 나왔습니다." << endl;
			return;
		}
		// 물이 부족하면 소모한 커피 반환
		tong[0].fill(1);
	}
	cout << "원료가 부족합니다." << endl;
}

void CoffeeVendingMachine::selectSugarCoffee()
{

	if (tong[0].consume(1)) {
		if (tong[1].consume(2)) {
			if (tong[2].consume(1)) {
				cout << "설탕커피 나왔습니다." << endl;
				return;
			}
			// 설탕이 부족하면 소모한 물 반환
			tong[1].fill(2);
		}
		// 설탕 또는 물이 부족하면 소모한 커피 반환
		tong[0].fill(1);
	}
	cout << "원료가 부족합니다." << endl;
}

void CoffeeVendingMachine::show()
{
	cout << "커피: " << tong[0].getSize();
	cout << ", 물: " << tong[1].getSize();
	cout << ", 설탕: " << tong[2].getSize() << endl;
}

bool CoffeeVendingMachine::checkInputError()
{
	// 어디에 오류 처리를 하는건지 모르겠습니다.
}

void CoffeeVendingMachine::run()
{
	cout << "***** 커피자판기가 동작합니다. *****" << endl;
	int menu = -1;
	while (menu != 0) {
		cout << "메뉴를 눌러주세요(1: 에스프레소, 2: 아메리카노, 3: 설탕커피, 4: 잔량보기, 5 : 채우기, 0: 끝내기) >>";
		cin >> menu;
		switch (menu) {
		case 1:	// 에스프레소
			selectEspresso();
			break;
		case 2:	// 아메리카노
			selectAmericano();
			break;
		case 3:	// 설탕커피
			selectSugarCoffee();
			break;
		case 4:	// 잔량보기
			show();
			break;
		case 5:	// 채우기
			fill();
			break;
		}
	}
}
