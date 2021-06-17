#pragma once
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

#pragma region Person
class Person;

struct Node
{
	Person* object;
	Node* next;
};

class Person
{
protected:
	string name;
public:
	static Node* begin;
	Person(string _name, bool add = false);
	virtual ~Person();
	void Add();
	virtual void Show(void) = 0;
	static void Print(void);
	friend istream& operator>> (istream& input, Person& p);
	friend ostream& operator<< (ostream& output, Person& p);
	string GetName() {
		return name;
	}
};
#pragma endregion Person

#pragma region Professor
class Professor : public Person
{
protected:
	string faculty;
public:
	Professor(string name, bool add = false);
	virtual ~Professor() override;
	virtual void Show() override;
};
#pragma endregion Professor

#pragma region HeadOfDepartment
class HeadOfDepartment : public Professor
{
private:
	string department;
public:
	HeadOfDepartment(string name, bool add = false);
	~HeadOfDepartment() override;
	void Show() override;
};
#pragma endregion HeadOfDepartment

#pragma region Student
class Student : public Person
{
private:
	float avgScore;
public:
	Student(string name, bool add = false);
	~Student() override;
	void Show() override;
};
#pragma endregion Student
