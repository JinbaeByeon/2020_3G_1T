/* ���Ǳ� ���α׷� */

//	�� ���Ǳ�� ���� ���� �Ա��ϰ� �޴��� �ֹ��ϵ��� �Ǿ� �ִ�.
//	�����ڿ�(����)���������� ���� �Է¿� ���� ���ܴ� ó���� �ʿ� ����

#include <iostream>
#include <string>
using namespace std;

int main()
{
	// �޴� ���ڿ�
	const string COKE = "��ī�ݶ�";
	const string HWAN = "ȯŸ";
	const string SOL = "���Ǵ�";
	const string MONEY = "�Ա�";
	const string QUIT = "����";
	// �޴� ���ڿ�

	string menu;
	int num, money{};	// money ���� 0���� �ʱ�ȭ

	while (1) {
		cout << "��ī�ݶ� 1500��, ȯŸ 1000��, ���Ǵ� 500�� �Դϴ�. �ܾ�: " << money << "��" << endl;
		cout << "�Է�>>";

		cin >> menu;
		if (menu == QUIT) break;	// "����" ���ڿ� �Է½� �ٷ� ����

		cin >> num;

		// �޴��� ������ ���, �ܾ��� ������ �ݾ׺��� ������ (�޴��� ����)*(����)�� �����ϰ� �ƴҰ�� "�ܾ׺���" ���
		if (menu == COKE)
			if (money >= num * 1500) {
				money -= num * 1500;
				cout << COKE << " " << num << "�� �ǸŵǾ����ϴ�.";
			}
			else
				cout << "�ܾ��� �����մϴ�.";

		else if (menu == HWAN)
			if (money >= num * 1000) {
				money -= num * 1000;
				cout << HWAN << " " << num << "�� �ǸŵǾ����ϴ�.";
			}
			else
				cout << "�ܾ��� �����մϴ�.";

		else if (menu == SOL)
			if (money >= num * 500) {
				money -= num * 500;
				cout << SOL << " " << num << "�� �ǸŵǾ����ϴ�.";
			}
			else
				cout << "�ܾ��� �����մϴ�.";
		// �޴��� �Ա��� ���, �ܾ׿� �Ա� �ݾ��� ����
		else if (menu == MONEY) {
			money += num;
			cout << num << "�� �ԱݵǾ����ϴ�.";
		}

		else cout << "���� �޴��Դϴ�.";	// menu�� ���� ���� �Է� �� ó��
		
		cout << endl;	// ����ó��
	}
}