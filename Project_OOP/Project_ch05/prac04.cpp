// append�� ���� ���ۿ� text�� ���̰� �� ���� ������ ��ȯ�Ͽ� ���� �������� �Է� �� �� ���۸� ����ϴ� ���α׷�
#include "Buffer.h"

Buffer& append(Buffer& buf, string text) {
	buf.add(text);
	return buf;
}

int main() {
	Buffer buf("Hello");
	Buffer& temp = append(buf, "Guys"); // buf�� ���ڿ��� "Guys" ������
	temp.print(); // "HelloGuys" ���
	buf.print(); // "HelloGuys" ���
}