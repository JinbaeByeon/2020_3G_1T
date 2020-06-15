//-----------------------------------------------------------------------------
// String.cpp
//
// class String - STL ������ Ŭ���� 
//	1. �����̳��� ���ҷ� ����Ѵ�
//  2. char�� �����ϴ� STL �����̳ʰ� �ǵ��� �ڵ��� ���ư���
//  
// 2020. 4.	Programmed by Wulong
//-----------------------------------------------------------------------------
#include <iostream>
#include <string>			// getString()
#include "String.h"

// �����޽����� ����Ϸ��� �ּ��� ������ ��
//#define ����

String::String() {
#ifdef ����
	std::cout << "����Ʈ ������: ��ü-" << this << ", ����-" << len << ", �޸�-" << static_cast<void*>(p) << std::endl;
#endif
};

String::String(const char* s)
try : len{ strlen(s) }, capacity{ len }, p{ new char[len] } {
#ifdef ����
	std::cout << "������(char*): ��ü-" << this << ", ����-" << len << ", �޸�-" << static_cast<void*>(p) << std::endl;
#endif
	memcpy(p, s, len);
}
catch (std::exception & e) {
	std::cout << "String ����, �޸� ����-" << e.what() << std::endl;
	throw e;
}


String::~String() {
#ifdef ����
	std::cout << "�Ҹ���: ��ü-" << this << ", ����-" << len << ", �޸�-" << static_cast<void*>(p) << std::endl;
#endif
	if (p)
		delete[] p;

	len = 0;
	capacity = 0;
}

String::String(const String& other)
try : len{ other.len }, capacity{ other.capacity }, p{ new char[len] } {
#ifdef ����
	std::cout << "���������: ��ü-" << this << ", ����-" << len << ", �޸�-" << static_cast<void*>(p) << std::endl;
#endif
	memcpy(p, other.p, len);
}
catch (std::exception & e) {
	std::cout << "String �������, �޸� ����-" << e.what() << std::endl;
	throw e;
}

String& String::operator=(const String& rhs)
try {
	if (this != &rhs) {
		if (p)
			delete[] p;
		len = rhs.len;
		capacity = rhs.capacity;
		p = new char[capacity];
		memcpy(p, rhs.p, len);
#ifdef ����
		std::cout << "�Ҵ翬����: ��ü-" << this << ", ����-" << len << ", �޸�-" << static_cast<void*>(p) << std::endl;
#endif
	}
	return *this;
}
catch (std::exception & e) {
	std::cout << "String �Ҵ翬����, �޸� ����-" << e.what() << std::endl;
	throw e;
}

String::String(String&& other) noexcept : len{ other.len }, p{ other.p }, capacity{ other.capacity }  {
	// �̵� �� ���ܹ߻� �ڵ� ����
#ifdef ����
	std::cout << "�̵�������: ��ü-" << this << ", ����-" << len << ", �޸�-" << static_cast<void*>(p) << std::endl;
#endif
	other.len = 0;
	other.p = nullptr;
	other.capacity = 0;
}

String& String::operator=(String&& rhs) noexcept {
	if (this != &rhs) {
		*this = rhs;
		if (p)
			delete[] p;
		len = rhs.len;
		p = rhs.p;
		capacity = rhs.capacity;
#ifdef ����
		std::cout << "�̵��Ҵ翬����: ��ü-" << this << ", ����-" << len << ", �޸�-" << static_cast<void*>(p) << std::endl;
#endif
		rhs.len = 0;
		rhs.p = nullptr;
		rhs.capacity = 0;
	}
	return *this;
}

String& String::operator=(String& rhs)
{
	*this = rhs;
	return *this;
}
char& String::operator[](size_t idx) {
	return p[idx];
}

char String::operator[](size_t idx) const {
	return p[idx];
}

size_t String::size() const {
	return capacity;
}


std::string String::getString() const {
	return std::string(p, p + len);
}


std::ostream& operator<<(std::ostream& os, const String& s)
{
	//	for ( int i = 0; i < s.len; ++i )
	//		os << s[i];
	os.write(s.p, s.len);
	return os;
}

std::istream& operator >> (std::istream& is, String& s)
{
	char c[20];
	is >> c;
	s = String(c);

	return is;
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

String::iterator String::begin()
{
	return iterator(p);
}
String::iterator String::end()
{
	return iterator(p + len);
}

/* 7_2 back_inserter ���� ���� String �Լ�*/
void String::push_back(char c)
{
	if (len >= capacity) {
		++capacity *= 2;
		if (p) {
			char* tmp = new char[len];
			memcpy(tmp, p, len);
			delete[] p;
			p = new char[capacity];
			memcpy(p, tmp, len);
			delete[]tmp;
		}
		else
			p = new char[capacity];
	}
	p[len++] = c;
}

void String::reserve(int n)
{
	capacity = n;
	char* tmp = new char[len];
	memcpy(tmp, p, len);
	delete[] p;
	p = new char[capacity];
	memcpy(p, tmp, len);
	delete[] tmp;
}

/* 7_2 String_back_insert_iterator ����*/
String_back_insert_iterator::String_back_insert_iterator(String& str) : p{ &str } {}
String_back_insert_iterator& String_back_insert_iterator::operator=(char&& rhs) {
	p->push_back(rhs);
	return *this;
}
String_back_insert_iterator& String_back_insert_iterator::operator=(const char& rhs) {
	p->push_back(rhs);
	return *this;
}
String_back_insert_iterator& String_back_insert_iterator::operator++() {
	return *this;
}
String_back_insert_iterator& String_back_insert_iterator::operator*() {
	return *this;
}