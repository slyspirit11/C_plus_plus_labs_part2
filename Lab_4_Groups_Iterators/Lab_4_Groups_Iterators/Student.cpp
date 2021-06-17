#include "Student.h"

Student::Student(string name, bool add) : Person(name, add)
{
	srand(rand());
	float a = rand() % 5 + 0.01*(rand() % 100);
	avgScore = (float)a;
}

void Student::SetAvgScore(float score)
{
	this->avgScore = score;
}

float Student::GetAvgScore()
{
	return avgScore;
}

Student::~Student()
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

void Student::Show()
{
	cout << "Student: " << name << endl;
}
