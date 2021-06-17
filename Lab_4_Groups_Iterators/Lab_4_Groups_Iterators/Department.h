#pragma once

#include "Object.h"
#include "Person.h"
#include <iostream>
#include <iomanip>
using namespace std;

struct Item {
	Object* object;
	Item* next;
};//добавить owner(если понадобится)
/*Кроме этого группа может содержать следующие методы:
1) int Empty();
Показывает, есть ли хотя бы один элемент в группе.
2) TObject* Delete(TObject* p);
Удаляет элемент из группы, но сохраняет его в памяти.
3) void DelDisp(TObject* p);
Удаляет элемент из группы и из памяти.*/
class Department : public Object
{
protected:
	string name; // название подразделения
	Person* head; // руководитель
	Item* first; // указатель на начало связанного списка структур Item
public:
	Department();
	Department(string name, Person* person = NULL);
	virtual void Show() override = 0;
	virtual ~Department() override;
	void SetHead(Person* person);
	void SetName(string name);
	void Insert(Object* obj);
	void Delete(Object* obj);
	Person* GetHead();
	string GetName();
	bool Empty();
};