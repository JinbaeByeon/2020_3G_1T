/*
���ڿ��� �ϳ� �Է¹ް� ���ڿ��� �κ� ���ڿ��� ���̸� 1�� �ø��� ����ϴ� ���α׷� 
��)	hello�� �Է¹����� ������ ���� ��µȴ�.
	h
	he
	hel
	hell
	hello
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s_input, s_output;					// �Է¹޴� �������� ����ϴ� ���ڿ��� ����

	cout << "���ڿ� �Է�>>";
	cin >> s_input;

	int cnt = 0;								// �Է¹��� ���ڿ��� ù��° ���ں��� ������� �ޱ� ���� ī��Ʈ
	while (cnt < s_input.length()) {			// �Է¹��� ���ڿ��� ũ�⸸ŭ �޾ƿ��� �ݺ����� ������.
		s_output.push_back(s_input.at(cnt++));	// �Է¹��� ���ڿ��� ���� cnt ��ġ�� �ش��ϴ� ���� ��� ���ڿ��� �� �ڿ� �߰��Ѵ�.
		cout << s_output << endl;
	}
}