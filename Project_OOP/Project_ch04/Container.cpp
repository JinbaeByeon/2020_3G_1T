#include "Container.h"

void Container::fill(int n)
{
	// ä��� ���� 10�� ���� �ʵ��� �Է�
	size = size + n < 10 ? size + n : 10;
}

bool Container::consume(int n)
{
	// ���ᰡ �����ϸ� false �ƴϸ� �Ҹ��ϰ� true ��ȯ
	if (size < n) return false;
	size -= n;
	return true;
}

int Container::getSize()
{
	return size;
}