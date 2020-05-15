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


class String_Iterator {
	char* p{ nullptr };

public:
	String_Iterator(char* p) :p{ p } {};
	String_Iterator() {};

	bool operator!=(const String_Iterator& rhs) const {
		return p != rhs.p;
	}
	bool operator==(const String_Iterator& rhs) const {
		return p == rhs.p;
	}
	bool operator<(const String_Iterator& rhs) const {
		return p < rhs.p;
	}

	bool operator>(const String_Iterator& rhs) const {
		return p > rhs.p;
	}
	ptrdiff_t operator-(const String_Iterator rhs) const {
		return p - rhs.p;
	}
	String_Iterator& operator=(const char rhs) {
		
	}
	String_Iterator& operator-(const int rhs) {
		String_Iterator iter(p - rhs);
		return iter;
	}

	String_Iterator& operator+(const ptrdiff_t rhs) const{
		String_Iterator iter(p + rhs);
		return iter;
	}

	String_Iterator& operator++() {
		++p;
		return *this;
	}
	String_Iterator& operator--() {
		--p;
		return *this;
	}

	char& operator*() {
		return *p;
	}
	char operator*() const{
		return *p;
	}
	char& operator[](size_t idx) {
		return p[idx];
	}
	char operator[](size_t idx) const {
		return p[idx];
	}

};

template<>
struct std::iterator_traits<String_Iterator> {
	using iterator_category = random_access_iterator_tag;
	using value_type = char;
	using difference_type = ptrdiff_t; 
	using pointer = char*; 
	using reference = char&;
};

class String {
	size_t len{ 0 };
	char* p{ nullptr };
	size_t capacity{ 0 };

public:

	String();

	String(const char* s);

	virtual ~String();

	String(const String& other);

	String& operator=(const String& rhs);

	String(String&& other) noexcept;

	String& operator=(String&& rhs) noexcept;

	String& operator=(String& rhs);

	char& operator[](size_t idx);

	char operator[](size_t idx) const;

	size_t size() const;

	std::string getString() const;

	bool operator==(const String& rhs) const noexcept;


	bool operator<(const String& rhs) const noexcept;

	bool operator>(const String& rhs) const noexcept;

	friend std::ostream& operator<<(std::ostream& os, const String& s);

	using iterator = String_Iterator;
	iterator begin();
	iterator end();

	/* 7_2 back_inserter 구현 관련 String 함수*/
	void push_back(char rhs);
	void reserve(int n);
};

/* 7_2 String_back_insert_iterator 구현*/
class String_back_insert_iterator {
public:
	String_back_insert_iterator(String& str);
	String_back_insert_iterator& operator=(char&& rhs);
	String_back_insert_iterator& operator=(const char& rhs);
	String_back_insert_iterator& operator++();
	String_back_insert_iterator& operator*();
protected:
	String* p{ nullptr };
};