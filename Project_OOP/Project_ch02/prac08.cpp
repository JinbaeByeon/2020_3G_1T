/* 자판기 프로그램 */

//	이 자판기는 돈을 먼저 입금하고 메뉴를 주문하도록 되어 있다.
//	“문자열(공백)양의정수” 외의 입력에 대한 예외는 처리할 필요 없다

#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 메뉴 문자열
	const string COKE = "코카콜라";
	const string HWAN = "환타";
	const string SOL = "솔의눈";
	const string MONEY = "입금";
	const string QUIT = "종료";
	// 메뉴 문자열

	string menu;
	int num, money{};	// money 변수 0으로 초기화

	while (1) {
		cout << "코카콜라 1500원, 환타 1000원, 솔의눈 500원 입니다. 잔액: " << money << "원" << endl;
		cout << "입력>>";

		cin >> menu;
		if (menu == QUIT) break;	// "종료" 문자열 입력시 바로 종료

		cin >> num;

		// 메뉴가 음료일 경우, 잔액이 지불할 금액보다 많으면 (메뉴의 가격)*(갯수)를 차감하고 아닐경우 "잔액부족" 출력
		if (menu == COKE)
			if (money >= num * 1500) {
				money -= num * 1500;
				cout << COKE << " " << num << "개 판매되었습니다.";
			}
			else
				cout << "잔액이 부족합니다.";

		else if (menu == HWAN)
			if (money >= num * 1000) {
				money -= num * 1000;
				cout << HWAN << " " << num << "개 판매되었습니다.";
			}
			else
				cout << "잔액이 부족합니다.";

		else if (menu == SOL)
			if (money >= num * 500) {
				money -= num * 500;
				cout << SOL << " " << num << "개 판매되었습니다.";
			}
			else
				cout << "잔액이 부족합니다.";
		// 메뉴가 입금일 경우, 잔액에 입금 금액을 더함
		else if (menu == MONEY) {
			money += num;
			cout << num << "원 입금되었습니다.";
		}

		else cout << "없는 메뉴입니다.";	// menu에 없는 문자 입력 시 처리
		
		cout << endl;	// 개행처리
	}
}