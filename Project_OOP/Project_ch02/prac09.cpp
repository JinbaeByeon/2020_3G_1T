/*���ڿ� ����(+)�� ����(*)�� �ϴ� ����*/

//	���ڿ��� �����ڴ� ����(�� ��)���� ���еȴ�.
//	������ �켱������ ������ �������� ����

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s_input,s_cal,s_buffer; // �Է¹޴� ���ĺ� ���ڿ��� ���� ���ڿ��� ����
	string tmp, s_number;

	cout << "�Է�>>";
	getline(cin, s_input, '\n');

	int cnt = 0;					// �Է¹��� ���ڿ��� ���� ��ġ�� ��Ÿ��
	while (cnt < s_input.length()) {// ���ڿ��� ���� ��ġ�� ���ڿ��� ������ �� ��� �ݺ��� ����
		// ���� ���ڿ��� ����(���ĺ�)�� ��� ���ۿ� �ְ� ���� ��ġ�� �̵�
		if (s_input.at(cnt) != ' ' && s_input.at(cnt) != '+' && s_input.at(cnt) != '*')
			s_buffer.push_back(s_input.at(cnt++));

		else if (s_input.at(cnt) == ' ') {					// ���� ���ڿ��� �����̸� ����
			if (s_input.at(cnt + 1) == '+') {				// ���� ���ڿ��� + �������̸� ����
				// ���±��� ���ۿ� �׾Ƶ� ���ڿ��� ����� ���ڿ��� �߰��ϰ� ���۸� ����.
				s_cal += s_buffer;							
				s_buffer.clear();

				// ���� ���ڿ��� ���� �����̰� ���� ���ڿ��� �������̱� ������ 3ĭ ���� ���ڿ�(���� Ȥ�� ����)�� �ٷ� �̵�
				cnt += 3;
			}
			else if (s_input.at(cnt + 1) == '*') {			// ���� ���ڿ��� * �������̸� ����
				cnt += 3;									// �ٷ� ������ ��ġ�� �̵�
				while (s_input.at(cnt) != ' ') {			// ������ ���� �� ���� �ݺ�
					s_number.push_back(s_input.at(cnt++));	// ���� ���ڿ��� �޴´�.

					if (cnt == s_input.length()) break;		// ������ ���ڿ��� ��� �ݺ��� �ߴ�
				}

				// ������ ���� ���� ���ڿ��� ������ ��ȯ�Ͽ� �ݺ��� ����
				for (int i = 0; i < atoi(s_number.c_str()); i++)	
					tmp += s_buffer;	// ���ۿ� �׾Ƶ� ���ڵ��� �����ظ�ŭ ������ ���ڿ��� ��� �״´�.
				
				// �׾Ƶ� ���ڿ�(������ ���ڿ�)�� ���ۿ� �ְ� ������ ����� ���ڿ��� �ʱ�ȭ
				s_buffer = tmp;
				s_number.clear();
				tmp.clear(); 
			}
		}
	}
	// �ݺ����� ������ ���ۿ� �����ִ� ���ڿ��� ����� ���ڿ��� �ְ� ���۸� �ʱ�ȭ
	s_cal += s_buffer;
	s_buffer.clear();

	cout << "���>>" << s_cal;
	
}