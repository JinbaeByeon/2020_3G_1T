#pragma once
#include <string>
class Dog {
private:
	std::string name;
	int age;
	int id;

public:
	Dog();
	Dog(std::string name, int age);
	friend bool Compare(const Dog&, const Dog&);
	std::string getName() const { return name; }
	virtual ~Dog() {}
	friend std::ostream& operator<<(std::ostream&, const Dog&);
	friend std::istream& operator>>(std::istream&, Dog&);
	bool operator<(const Dog& rhs) const;
};