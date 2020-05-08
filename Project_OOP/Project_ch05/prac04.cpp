// append를 통해 버퍼에 text를 붙이고 그 값을 참조로 반환하여 버퍼 참조값에 입력 후 두 버퍼를 출력하는 프로그램
#include "Buffer.h"

Buffer& append(Buffer& buf, string text) {
	buf.add(text);
	return buf;
}

int main() {
	Buffer buf("Hello");
	Buffer& temp = append(buf, "Guys"); // buf의 문자열에 "Guys" 덧붙임
	temp.print(); // "HelloGuys" 출력
	buf.print(); // "HelloGuys" 출력
}