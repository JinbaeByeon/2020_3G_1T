#include "Container.h"

void Container::fill(int n)
{
	// 채우는 값이 10이 넘지 않도록 입력
	size = size + n < 10 ? size + n : 10;
}

bool Container::consume(int n)
{
	// 원료가 부족하면 false 아니면 소모하고 true 반환
	if (size < n) return false;
	size -= n;
	return true;
}

int Container::getSize()
{
	return size;
}