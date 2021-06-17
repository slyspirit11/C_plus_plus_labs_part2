#pragma once

#include "Object.h"
#include "Person.h"
#include <iostream>
#include <iomanip>
using namespace std;

struct Item {
	Object* object;
	Item* next;
};//�������� owner(���� �����������)
/*����� ����� ������ ����� ��������� ��������� ������:
1) int Empty();
����������, ���� �� ���� �� ���� ������� � ������.
2) TObject* Delete(TObject* p);
������� ������� �� ������, �� ��������� ��� � ������.
3) void DelDisp(TObject* p);
������� ������� �� ������ � �� ������.*/
class Department : public Object
{
protected:
	string name; // �������� �������������
	Person* head; // ������������
	Item* first; // ��������� �� ������ ���������� ������ �������� Item
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