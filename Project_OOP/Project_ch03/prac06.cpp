// 밥 주는 기계에 사료를 줄 동물들을 설정해서 동물들의 배고픈 주기마다 밥을 주는 프로그램

#include <iostream>
#include "prac06_Machine.h"
#include "prac06_Cat.h"




int main()
{
	Machine machine; // 밥 주는 기계

	machine.setAnimals(Dog("댕댕이"));	// 개를 기계에 설정
	machine.setAnimals(Cat("냥냥이"));	// 고양이를 기계에 설정
	
	while (1) {
		machine.Count();	// 기계를 작동시킨다.
	}

}