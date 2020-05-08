//-----------------------------------------------------------------------------
// String.h
//
// class String - STL 연습용 클래스 
//	1. 컨테이너의 원소로 사용한다
//  2. char를 저장하는 STL 컨테이너가 되도록 코딩해 나아간다
//  
// 2020. 4.	Programmed by Wulong
//-----------------------------------------------------------------------------
#pragma once

class String {
	size_t len { 0 };
	char* p { nullptr };

public:
	String( );

	String( const char* s );

	virtual ~String( );

	String( const String& other );

	String& operator=( const String& rhs );

	String( String&& other ) noexcept;

	String& operator=( String&& rhs ) noexcept;

	char& operator[]( size_t idx );

	char operator[]( size_t idx ) const;

	size_t size( ) const;

	std::string getString( ) const;

	bool operator==(const String& rhs) const noexcept;

	bool operator<(const String& rhs) const noexcept;

	bool operator>(const String& rhs) const noexcept;

	friend std::ostream& operator<<( std::ostream& os, const String& s );
};

