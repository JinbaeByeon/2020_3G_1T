// ���� Ŭ���� ������
#include "Buffer.h"

void Buffer::print()
{
	cout << data << endl;
}
void Buffer::add(const string& str)
{
	data.append(str);
}