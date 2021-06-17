#include <iostream>
#include <iomanip>
#include <typeinfo>
#include "Student.h"
#include "HeadOfDepartment.h"
#include "Chair.h"
#include "StudentGroup.h"

using namespace std;
/*Порядок выполнения работы.
1.  Дополнить иерархию классов лабораторной работы No 2 классами “группа”.
	Например, для предметной области ФАКУЛЬТЕТ можно предложить
	классы “факультет”, “студенческая группа”, “кафедра”. Рекомендуется создать
	абстрактный класс − “подразделение”, который будет предком всех групп и
	абстрактный класс TObject, находящийся во главе всей иерархии.
2.  Написать для класса-группы метод-итератор.
3.  Написать процедуру или функцию, которая выполняется для всех
	объектов, входящих в группу (смотри примеры в приложении).
4.  Написать демонстрационную программу, в которой создаются,
	показываются и разрушаются объекты-группы, а также демонстрируется
	использование итератора.*/
	//5 вариант
	//Вариант запроса: Имена и средний балл студентов, ср.балл которых выше передаваемого параметра
Node* Person::begin = NULL;
void ShowStudentInfo(Object* obj, float score) {
	float avgScore = ((Student*)obj)->GetAvgScore();
	if (avgScore > score) {
		cout << "Имя: " << ((Student*)obj)->GetName() << "  Средний балл: " << avgScore << endl;
	}
}
int main()
{
	setlocale(LC_ALL, "RU");
	Person* prof1 = new HeadOfDepartment("Страуструп");
	Department* fac = new Faculty("ИМиКН", prof1);
	Chair chair1 = Chair("Кафедра логики");
	Professor prof2 = Professor("Мейерс");
	Professor prof3 = Professor("Лапласс");
	chair1.Insert(prof1);
	chair1.Insert(&prof2);
	chair1.Insert(&prof3);
	fac->Insert(&chair1);
	Chair chair2 = Chair("Кафедра программирования");
	Person* prof4 = new HeadOfDepartment("Декарт");
	Professor prof5 = Professor("Ньютон");
	Professor prof6 = Professor("Эйлер");
	chair2.Insert(prof4);
	chair2.Insert(&prof5);
	chair2.Insert(&prof6);
	fac->Insert(&chair2);
	StudentGroup group1 = StudentGroup("Группа 1");
	Student s1 = Student("Борис");
	Student s2 = Student("Фёдор");
	Student s3 = Student("Иван");
	group1.Insert(&s1);
	group1.Insert(&s2);
	group1.Insert(&s3);
	fac->Insert(&group1);
	StudentGroup group2 = StudentGroup("Группа 2");
	Student s4 = Student("Остап");
	Student s5 = Student("Алехандро");
	Student s6 = Student("Василий");
	group2.Insert(&s4);
	group2.Insert(&s5);
	group2.Insert(&s6);
	group2.Delete(&s6);
	fac->Insert(&group2);
	fac->Show();
	cout << "======================================" << endl;
	cout << "Группа 1" << endl;
	group1.ForEach(ShowStudentInfo, 1.0);
	cout << "Группа 2" << endl;
	group2.ForEach(ShowStudentInfo, 3.5);
	delete prof1, prof4, fac;
	//каким образом можно перенести ту иерархию, которая есть в виде группы на какой-либо паттерн проектирования
	//агрегация - часть и целое существуют отдельно
	//композиция - часть и целое неотделимы
	//есть объект-группа других объектов
	//для этого объекта-группы создаётся особый метод: итератор. 
	//В него передаётся указатель на функцию извне и доп.параметры.
	//Итератор выполняет передаваемую функцию для каждого внутреннего объекта исходного объекта-группы
	//у нас есть группа - создаем класс итератор - создаём функцию с возвращением объекта класса итератор - 
	// - 
}