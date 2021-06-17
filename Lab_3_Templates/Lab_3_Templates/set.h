#pragma once
#include <iostream>
#include <iomanip>

using namespace std;
/*
Класс − множество set.Дополнительно перегрузить следующие
операции :
+− добавить элемент в множество(типа item + set);
+− объединение множеств;
== − проверка множеств на равенство.
*/
/*
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
/*Методические указания ко второй части задания.
1. Класс содержащий массив или множество реализовать как
динамический массив. Для этого определение класса должно иметь
следующие поля:
− указатель на начало массива;
− максимальный размер массива;
− текущий размер массива.
3. Для ввода и вывода определить в классе функции input и print.
4. Чтобы не возникало проблем, аккуратно работайте с
константными объектами. Например:
•конструктор копирования следует определить так: MyTmp (const
MyTmp& ob);
•операцию присваивания перегрузить так: MyTmp& operator = (const
MyTmp& ob);
5. Для шаблонов множеств, списков, стеков и очередей в качестве
стандартных типов использовать целые и вещественные типы. Для
пользовательского типа взять класс из лабораторной работы No 1. */
template<class type>
class Set {
private:
	int maxSize;
	int currSize;
	type* set;
	bool HasItem(type item) {
		for (int i = 0; i < currSize; i++) {
			if (set[i] == item) return true;
		}
		return false;
	}
public:
	Set(int size): maxSize(size) {
		set = new type[maxSize];
		currSize = 0;
	}
	Set(const Set<type>& other) {
		operator=(other);
	}
	~Set() {
		delete[] set;
	}
	type& operator[](const int i) {
		return set[i];
	}
	Set<type>& operator=(const Set<type>& other) {
		//операция присваивания
		if (set != other.set) {
			delete[] set;
			set = new type[other.maxSize];
			for (int i = 0; i < other.currSize; i++) {
				set[i] = other.set[i];
			}
			maxSize = other.maxSize;
			currSize = other.currSize;
		}
		return *this;
	}
	Set<type>& operator+(const type item) {
		//добавить элемент в множество
		if (!this->HasItem(item) && currSize < maxSize) {
			set[currSize] = item;
			currSize++;
		}
		return *this;
	}
	Set<type>& operator+(const Set<type>& other) {
		//объединение множеств
		type* unionSet = new type[maxSize + other.maxSize];
		int thisIndex;
		for (thisIndex = 0; thisIndex < currSize; thisIndex++)
			unionSet[thisIndex] = set[thisIndex];
		for (int otherIndex = 0; otherIndex < other.currSize; otherIndex++) {
			if (!this->HasItem(other.set[otherIndex])) {
				unionSet[thisIndex] = other.set[otherIndex];
				thisIndex++;
			}
		}
		delete[] set;
		set = unionSet;
		maxSize = maxSize + other.maxSize;
		currSize = thisIndex;
		return *this;
	}
	bool operator==(const Set<type>& other) {
		//проверка множеств на равенство
		if (currSize != other.currSize) return false;
		else {
			for (int i = 0; i < currSize; i++)
				if (!this->HasItem(other.set[i]))
					return false;
		}
		return true;
	}
	int getMaxSize() {
		return maxSize;
	}
	void input(type item) {
		operator+(item);
	}
	void print(){
		for (int i = 0; i < currSize; i++) {
			cout << set[i] << " | ";
		}
		cout << endl;
	}
};