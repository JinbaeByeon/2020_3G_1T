// String Ŭ������ �̿��Ͽ� ����ڰ� �Է��� ���� �� ���� ���ڿ��� �Է¹ް� �Ųٷ� ����ϴ� ���α׷�
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string text;	// �Է¹��� ���ڿ�
	
	cout << "�Ʒ��� �� ���� �Է��ϼ���.(exit�� �Է��ϸ� �����մϴ�)" << endl;
	while (true) {
		cout << ">>";
		getline(cin, text, '\n');	// ���� ���ڰ� ���� ������ �Է°���

		if (text == "exit") break;	//exit�� �Է��ϸ� �ݺ��� ����
		
		// �Ųٷ� ���
		for (int i = 0; i < text.length(); ++i)
			cout << text.at(text.length() - i - 1);
		cout << endl;
	}

}