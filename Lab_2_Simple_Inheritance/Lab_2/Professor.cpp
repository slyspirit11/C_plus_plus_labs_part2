#include "Professor.h"

Professor::Professor(string name, bool add) : Person(name, add)
{
}

Professor::~Professor()
{
	Node* current = begin;
	Node* previous = begin;
	while (current != NULL) {
		if (current->object == this) {
			cout << "deleted: ";
			this->Show();
			cout << "------------" << endl;
			Node* nextNode = current;
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

void Professor::Show()
{
	cout << "Professor: " << name << endl;
}