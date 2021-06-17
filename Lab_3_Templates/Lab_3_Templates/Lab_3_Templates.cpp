#include <iostream>
#include <iomanip>
#include "templates.cpp"
#include "employee.h"
#include "set.h"

using namespace std;

/*
* Часть 1
1.1. Создать новый проект.
1.2. Добавить к проекту файл исходным кодом (.h и .cpp).
1.3. Вынести в отдельный модуль функции и типы данных.
1.4. Написать программу в соответствии с вариантом задания из пункта 
Часть 2
2.1 Создать шаблон заданного класса. Определить конструкторы,
деструктор, перегруженную операцию присваивания (“=”) и операции,
заданные в варианте задания.
2.2. Написать программу, в которой проверяется использование
шаблона для стандартных типов данных.
2.3. Определить пользовательский класс, который будет использоваться
в качестве параметра шаблона. Определить в классе необходимые функции и
перегруженные операции.
2.4. Написать программу, в которой проверяется использование
шаблона для пользовательского типа.
*/


/*ВАРИАНТ 5
Часть 1.
Определить функцию, возвращающую НОД нескольких чисел.
Реализовать шаблон для следующих типов параметров:
5.1. Два параметра типа int.
5.2. Два параметра типа long.
5.3. Два параметра типа float.
5.4. Два параметра типа double.

Часть 2.
Класс − множество set. Дополнительно перегрузить следующие
операции:
+ − добавить элемент в множество (типа item + set);
+ − объединение множеств;
== − проверка множеств на равенство.
*/


template<typename type, type a = 5> void k() {
	cout << type << endl;
}
template<auto d = 5.0> void y() {
	cout << d << endl;
}

template<typename type> class animal;
template<typename type> void drink(animal<type>&);
template<typename type> void eat(animal<type>&);

template<typename type>
class animal {
	type width;
	string name;
public: 
	friend void eat(animal<type>&);
	friend void drink<type>(animal<type>&);
};
 

template<typename type>
void drink(animal<type>& cat)
{
	cat.width = "hey";
	animal<string> b;
	b.width = "hello";
	animal<int> a;
	a.width = 5;
}

template<typename type>
void eat(animal<type>& cat)
{
	cat.width = "hey";
	animal<int> a;
	a.width = 5;
}

int main()
{
	animal<string> cat;
	drink(cat);
	eat(cat);

	setlocale(LC_ALL, "ru");
	//ШАБЛОНЫ ФУНКЦИЙ
	cout << "NOD = " << getNOD(10, 25) << endl;
	cout << "NOD = " << getNOD(10.6, 21.8) << endl;
	//ШАБЛОНЫ КЛАССОВ
	//1.Написать программу в которой проверяется использоваание стандартных типов(целые и вещественные)
	//оператор добавления нового элемента множества
	cout << "Set<int>" << endl;
	Set<int> set1 = Set<int>(5);
	cout << "set1" << endl;
	for (int i = 0; i < set1.getMaxSize(); i++) {
		set1 + i;
	}
	set1.print();
	Set<int> set2 = Set<int>(10);
	for (int i = 0; i < set2.getMaxSize(); i++) {
		set2 + i;
	}
	cout << "set2" << endl;
	set2.print();
	set1 = set2;
	cout << "set1 = set2" << endl;
	set1.print();
	Set<int> set3 = Set<int>(10); for (int i = 30; i < 40; i++) set3 + i;
	set1 + set3;
	cout << "set3" << endl;
	set3.print();
	cout << "set1 + set3" << endl;
	set1.print();
	//оператор сравнения
	set1 = set2;
	cout << "set1 == set2 : " << boolalpha << (set1 == set2) << endl;
	cout << "set1 == set3 : " << boolalpha << (set1 == set3) << endl;

	//2.Написать программу в которой проверяется использоваание пользовательских типов(класс Employee)
	//cout << "Set<Employee>" << endl;

	Set<Employee> set4 = Set<Employee>(2);
	//оператор добавления нового элемента множества
	set4 + Employee("Vader"); set4 + Employee("Fender");
	set4.print();
	Set<Employee> set5 = Set<Employee>(3);
	set5 + Employee("Hopkins"); set5 + Employee("Lefty"); set5 + Employee("Mr Alberto");
	set5.print();
	//оператор присваивания
	cout << "set4 = set5" << endl;
	set4 = set5;
	set4.print();
	//оператор сравнения
	cout << "set4 == set5 после присваивания" << endl;
	cout << boolalpha << (set4 == set5) << endl;
	Set<Employee> set6 = Set<Employee>(2);
	set6 + Employee("Mr Shulpin"); set6 + Employee("Mr Kitten");
	cout << "set4 == set6" << endl;
	cout << boolalpha << (set4 == set6) << endl;
	//оператор объединения множеств
	cout << "set4 + set6" << endl;
	set4 + set6;
	set4.print();
}


