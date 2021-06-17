#include "Faculty.h"

Faculty::Faculty() : Department(){

}

Faculty::Faculty(string name, Person* head) : Department(name, head) {

}

Faculty::~Faculty()
{

}

void Faculty::Show()
{
	cout << "Факультет: " << name << endl;
	Item* current = first;
	while (current != NULL) {
		current->object->Show();
		current = current->next;
	}
}
