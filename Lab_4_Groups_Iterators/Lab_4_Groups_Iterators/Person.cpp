#include "Person.h"

using namespace std;

Person::Person(string _name, bool add)
{
	this->name = _name;
    if (add) {
        this->Add();
    }
}

void Person::Add()
{
    Node* newNode = new Node;
    newNode->object = this;
    newNode->next = NULL;
    if (begin == NULL) begin = newNode;
    else
    {
        Node* current = begin;
        while (current->next != NULL)
            current = current->next;
        current->next = newNode;
    }

}

string Person::GetName()
{
    return name;
}

Person::~Person()
{
    
}

void Person::Print(void)
{
	Node* current = begin;
    if (current->object == NULL) {
        cout << "Список пуст!" << endl;
    }
    else {
        while (current != NULL)
	    {
		    current->object->Show();
		    current = current->next;
        } 	
    }
}
