#include "Headers.h"

#pragma region Person
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

ostream& operator<< (ostream& output, Person& p) {
    output << p.name;
    return output;
}

istream& operator>> (istream& input, Person& p) {
    getline(input, p.name);
    return input;
}
#pragma endregion Person

#pragma region Professor
Professor::Professor(string name, bool add) : Person(name, add)
{
}

Professor::~Professor()
{
    Node* current = begin;
    Node* previous = begin;
    while (current != NULL) {
        if (!current) break;
        if (current->object == this) {
            //cout << "deleted: ";
            //this->Show();
            //cout << "------------" << endl;
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
#pragma endregion Professor

#pragma region HeadOfDepartment
HeadOfDepartment::HeadOfDepartment(string name, bool add) : Professor(name, add)
{
}

HeadOfDepartment::~HeadOfDepartment()
{
    Node* current = begin;
    Node* previous = begin;
    while (current != NULL) {
        if (current->object == this) {
            //cout << "deleted: ";
            //this->Show();
            //cout << "------------" << endl;
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

void HeadOfDepartment::Show()
{
    cout << "HeadOfDepartment: " << name << endl;
}
#pragma endregion HeadOfDepartment

#pragma region Student
Student::Student(string name, bool add) : Person(name, add)
{
    avgScore = (float)4.3;
}

Student::~Student()
{
    Node* current = begin;
    Node* previous = begin;
    while (current != NULL) {
        if (current->object == this) {
            //cout << "deleted: ";
            //this->Show();
            //cout << "------------" << endl;
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

#pragma endregion Student