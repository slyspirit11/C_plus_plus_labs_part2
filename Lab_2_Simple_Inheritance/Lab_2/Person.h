#pragma once
#include <iomanip>
#include <iostream>
using namespace std;
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
	//������� ������ ��� ��������� ���� � ������
	void Add();
	//����� ��������� ������: ���� ��� ������� �������
	virtual void Show(void) = 0;
	//����������� ����� ��������� ������
	static void Print(void);
};

