// 통 하나를 나타내는 클래스
#pragma once
class Container {
	int size; // 현재 저장 량, 최대 저장 가능량은 10
public:
	Container() { size = 10; }
	void fill(int n); // n 만큼 채우기
	bool consume(int n); // n 만큼 소모하기
	int getSize(); // 현재 크기 리턴
};
