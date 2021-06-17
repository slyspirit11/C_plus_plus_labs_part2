#include "Chair.h"

Chair::Chair() : Faculty()
{
}

Chair::Chair(string name) : Faculty(name)
{
}

Chair::~Chair()
{
}

void Chair::Show()
{
	cout << "Кафедра: " << name << endl;
	Item* current = first;
	while (current != NULL) {
		current->object->Show();
		current = current->next;
	}
}
