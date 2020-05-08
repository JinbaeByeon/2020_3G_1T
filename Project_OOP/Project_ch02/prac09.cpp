/*문자열 덧셈(+)과 곱셈(*)을 하는 계산기*/

//	문자열과 연산자는 공백(‘ ‘)으로 구분된다.
//	연산자 우선순위는 곱셈이 덧셈보다 높다

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s_input,s_cal,s_buffer; // 입력받는 알파벳 문자열과 계산된 문자열로 나눔
	string tmp, s_number;

	cout << "입력>>";
	getline(cin, s_input, '\n');

	int cnt = 0;					// 입력받은 문자열의 현재 위치를 나타냄
	while (cnt < s_input.length()) {// 문자열의 현재 위치가 문자열의 끝까지 갈 경우 반복문 종료
		// 현재 문자열이 문자(알파벳)일 경우 버퍼에 넣고 다음 위치로 이동
		if (s_input.at(cnt) != ' ' && s_input.at(cnt) != '+' && s_input.at(cnt) != '*')
			s_buffer.push_back(s_input.at(cnt++));

		else if (s_input.at(cnt) == ' ') {					// 현재 문자열이 공백이면 실행
			if (s_input.at(cnt + 1) == '+') {				// 앞의 문자열이 + 연산자이면 실행
				// 여태까지 버퍼에 쌓아둔 문자열을 결과값 문자열에 추가하고 버퍼를 비운다.
				s_cal += s_buffer;							
				s_buffer.clear();

				// 현재 문자열이 공백 문자이고 다음 문자열은 연산자이기 때문에 3칸 앞의 문자열(문자 혹은 숫자)로 바로 이동
				cnt += 3;
			}
			else if (s_input.at(cnt + 1) == '*') {			// 앞의 문자열이 * 연산자이면 실행
				cnt += 3;									// 바로 숫자의 위치로 이동
				while (s_input.at(cnt) != ' ') {			// 공백이 나올 때 까지 반복
					s_number.push_back(s_input.at(cnt++));	// 숫자 문자열을 받는다.

					if (cnt == s_input.length()) break;		// 마지막 문자열일 경우 반복문 중단
				}

				// 위에서 받은 숫자 문자열을 정수로 전환하여 반복문 실행
				for (int i = 0; i < atoi(s_number.c_str()); i++)	
					tmp += s_buffer;	// 버퍼에 쌓아둔 문자들을 곱해준만큼 임의의 문자열에 계속 쌓는다.
				
				// 쌓아둔 문자열(곱해진 문자열)을 버퍼에 넣고 곱셈에 사용한 문자열들 초기화
				s_buffer = tmp;
				s_number.clear();
				tmp.clear(); 
			}
		}
	}
	// 반복문이 끝나면 버퍼에 남아있는 문자열을 결과값 문자열에 넣고 버퍼를 초기화
	s_cal += s_buffer;
	s_buffer.clear();

	cout << "출력>>" << s_cal;
	
}