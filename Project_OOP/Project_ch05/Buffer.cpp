// 버퍼 클래스 구현부
#include "Buffer.h"

void Buffer::print()
{
	cout << data << endl;
}
void Buffer::add(const string& str)
{
	data.append(str);
}