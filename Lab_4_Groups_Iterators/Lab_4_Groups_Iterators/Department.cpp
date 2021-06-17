#include "Department.h"

Department::Department(){
	this->name = "IMICN";
	this->head = NULL;
	this->first = NULL;
}

Department::Department(string name, Person* person) {
	this->name = name;
	this->head = person;
	this->first = NULL;
}

Department::~Department() {
	if (first != NULL) {
		Item *current = first, *prev = current;
		while (current != NULL) {
			prev = current;
			current = current->next;
			delete prev;
		}
	}
}

string Department::GetName()
{
	return name;
}

Person* Department::GetHead()
{
	return head;
}

void Department::SetName(string name)
{
	this->name = name;
}

void Department::SetHead(Person* person)
{
	head = person;
}

void Department::Insert(Object* obj)
{
	Item* newItem = new Item;
	newItem->object = obj;
	newItem->next = NULL;
	if (first == NULL) first = newItem;
	else
	{
		Item* current = first;
		while (current->next != NULL)
			current = current->next;
		current->next = newItem;
	}
}

void Department::Delete(Object* obj)
{
	Item* current = first;
	Item* previous = first;
	while (current != NULL) {
		if (current->object == obj) {
			cout << "deleted: ";
			obj->Show();
			Item* nextNode = current;
			if (current->next != NULL) {
				previous->next = current->next;
				nextNode = current->next;
			}
			else {
				nextNode = NULL;
				previous->next = NULL;
			}
			delete current;
			current = nextNode;
		}
		else {
			previous = current;
			current = current->next;
		}
	}

}

bool Department::Empty()
{
	return first == NULL;
}
