//-----------------------------------------------------------------------------
// String.cpp
//
// class String - STL 연습용 클래스 
//	1. 컨테이너의 원소로 사용한다
//  2. char를 저장하는 STL 컨테이너가 되도록 코딩해 나아간다
//  
// 2020. 4.	Programmed by Wulong
//-----------------------------------------------------------------------------
#include <iostream>
#include <string>			// getString()
#include "String.h"

// 관찰메시지를 출력하려면 주석을 제거할 것
#define 관찰

String::String( ) {
#ifdef 관찰
	std::cout << "디폴트 생성자: 객체-" << this << ", 길이-" << len << ", 메모리-" << static_cast<void*>(p) << std::endl;
#endif
};

String::String( const char* s )
try : len { strlen( s ) }, p { new char[len] } {
#ifdef 관찰
	std::cout << "생성자(char*): 객체-" << this << ", 길이-" << len << ", 메모리-" << static_cast<void*>(p) << std::endl;
#endif
	memcpy( p, s, len );
}
catch ( std::exception& e ) {
	std::cout << "String 생성, 메모리 예외-" << e.what( ) << std::endl;
	throw e;
}


String::~String( ) {
#ifdef 관찰
	std::cout << "소멸자: 객체-" << this << ", 길이-" << len << ", 메모리-" << static_cast<void*>(p) << std::endl;
#endif
	if ( p )
		delete[ ] p;

	len = 0;
}

String::String( const String& other )
try : len { other.len }, p { new char[len] } {
#ifdef 관찰
	std::cout << "복사생성자: 객체-" << this << ", 길이-" << len << ", 메모리-" << static_cast<void*>(p) << std::endl;
#endif
	memcpy( p, other.p, len );
}
catch ( std::exception& e ) {
	std::cout << "String 복사생성, 메모리 예외-" << e.what( ) << std::endl;
	throw e;
}

String& String::operator=( const String& rhs )
try {
	if ( this != &rhs ) {
		if ( p )
			delete p;
		len = rhs.len;
		p = new char[len];
		memcpy( p, rhs.p, len );
#ifdef 관찰
		std::cout << "할당연산자: 객체-" << this << ", 길이-" << len << ", 메모리-" << static_cast<void*>(p) << std::endl;
#endif
	}
	return *this;
}
catch ( std::exception& e ) {
	std::cout << "String 할당연산자, 메모리 예외-" << e.what( ) << std::endl;
	throw e;
}

String::String( String&& other ) noexcept : len { other.len }, p { other.p }  {
// 이동 시 예외발생 코드 없음
#ifdef 관찰
	std::cout << "이동생성자: 객체-" << this << ", 길이-" << len << ", 메모리-" << static_cast<void*>(p) << std::endl;
#endif
	other.len = 0;
	other.p = nullptr;
}

String& String::operator=( String&& rhs ) noexcept {
	if ( this != &rhs ) {
		if ( p )
			delete p;
		len = rhs.len;
		p = rhs.p;
#ifdef 관찰
		std::cout << "이동할당연산자: 객체-" << this << ", 길이-" << len << ", 메모리-" << static_cast<void*>(p) << std::endl;
#endif
		rhs.len = 0;
		rhs.p = nullptr;
	}
	return*this;
}

char& String::operator[]( size_t idx ) {
	return p[idx];
}

char String::operator[]( size_t idx ) const {
	return p[idx];
}

size_t String::size( ) const {
	return len;
}


std::string String::getString( ) const {
	return std::string( p, p+len );
}


std::ostream& operator<<( std::ostream& os, const String& s )
{
	//	for ( int i = 0; i < s.len; ++i )
	//		os << s[i];
	os.write( s.p, s.len );
	return os;
}

bool String::operator==(const String& rhs) const noexcept {
	if (len == rhs.len) {
		for (int i = 0; i < len; ++i) {
			if (p[i] != rhs.p[i])
				return false;
		}
		return true;
	}
	return false;
}

bool String::operator<(const String& rhs) const noexcept {
	return this->getString() < rhs.getString();
}

bool String::operator>(const String& rhs) const noexcept {
	return this->getString() > rhs.getString();
}