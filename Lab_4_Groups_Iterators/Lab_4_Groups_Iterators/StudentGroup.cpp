#include "StudentGroup.h"

StudentGroup::StudentGroup() : Faculty()
{
	
}

StudentGroup::StudentGroup(string name) : Faculty(name)
{
}

StudentGroup::~StudentGroup()
{
}

void StudentGroup::Show()
{
	cout << "Ãðóïïà: " << name << endl;
	Item* current = first;
	while (current != NULL) {
		current->object->Show();
		current = current->next;
	}
}

void StudentGroup::ForEach(void(*action)(Object* obj, float score), float avgScore)
{
	Item* current = first;
	while (current != NULL) {
		action(current->object, avgScore);
		current = current->next;
	}
}
