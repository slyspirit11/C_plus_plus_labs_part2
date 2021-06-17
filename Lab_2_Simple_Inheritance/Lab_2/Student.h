#pragma once
#include "Person.h"
class Student : public Person
{
private:
	float avgScore;
public:
	Student(string name, bool add = false);
	~Student() override;
	void Show() override;
};

