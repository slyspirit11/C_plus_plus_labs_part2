#pragma once
#include <iomanip>
#include <iostream>
#include "Object.h"
using namespace std;
class Person;

struct Node
{
	Person* object;
	Node* next;
};

class Person : public Object
{
protected:
	string name;
public:
	static Node* begin;
	Person(string _name, bool add = false);
	virtual ~Person();
	//текущий объект сам добавляет себя в список
	void Add();
	string GetName();
	//метод просмотра списка: свой для каждого объекта
	virtual void Show(void) = 0;
	//статический метод просмотра списка
	static void Print(void);
};