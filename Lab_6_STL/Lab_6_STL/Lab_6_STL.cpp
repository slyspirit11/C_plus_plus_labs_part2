#include <iostream>
#include <iomanip>
#include "Employee.h"
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <Windows.h>
#include <map>
#include <list>
#include <vector>

//вариант 3 по списку
//1. deque 2. stack 3. multimap
//data type: float
//внутреннее устройство дека
// Дек - это вектор который содержит указатели на массивы фиксированной длины
// Когда мы получаем элемент по индексу сначала определяется массив который содержит элемент
//  index / размер фиксированного массива
//  index % размер фиксированного массива
// 2 операции, поэтому O(1)

using namespace std;

void printMenu() {
	cout << "1.Вставка\n2.Редактирование\n3.Удаление\n4.Просмотр\n5.Продолжить" << endl;
}
void printDequeMenu1() {
	cout << "1.Вставка c левого конца\n2.Вставка с правого конца" << endl;
}
void printDequeMenu2() {
	cout << "1.Удаление c левого конца\n2.Удаление с правого конца" << endl;
}

template<typename T>
void appendDeque(deque<T>& deq) {
	int input = -1;
	while (true) {
		printDequeMenu1();
		cin.ignore(1, '\n');
		cin >> input;
		if (input < 1 || input > 2) break;
		cout << "Введите данные" << endl;
		cin.ignore(1, '\n');
		T object;
		cin >> object;
		switch (input) {
		case 1:
			deq.push_front(object);
			cout << "Элемент успешно добавлен" << endl;
			break;
		case 2:
			deq.push_back(object);
			cout << "Элемент успешно добавлен" << endl;
			break;
		default:
			cout << "Выбран неверный пункт меню" << endl;
			break;
		}
		break;
	}
}
template<typename container>
void updateDeque(container& collection, int index) {
	cin.ignore(1, 'a');
	cout << "Введите данные" << endl << ">";
	cin >> collection.at(index);
}
template<typename T>
void removeDeque(deque<T>& deq) {
	int input = -1;
	while (true) {
		printDequeMenu2();
		cin.ignore(1, '\n');
		cin >> input;
		if (input < 1 || input > 2) break;
		switch (input) {
		case 1:
			deq.pop_front();
			cout << "Элемент успешно удалён" << endl;
			break;
		case 2:
			deq.pop_back();
			cout << "Элемент успешно удалён" << endl;
			break;
		default:
			cout << "Выбран неверный пункт меню" << endl;
			break;
		}
		break;
	}

}
template<typename T>
void printDeque(deque<T>& deq) {
	int index = 0;
	for (auto iter = begin(deq); iter != end(deq); iter++) {
		cout << index << ": " << *iter << endl;
		index++;
	}
}
void runProgram1() {
	//deque<float> deq = { 0.5, 0.3, 18.3, 11.25, 30.48 };
	deque<Employee> deq = {
		Employee("Степан Филиппович", "Слесарь"),
		Employee("Людмила Алексеевна", "Программист"),
		Employee("Павел Генадьевич", "Дизайнер"),
		Employee("Олег Артемович", "Сантехник"),
		Employee("Анастасия Александровна", "Офтальмолог")
	};
	string path = "output.txt";
	int input1 = -1;
	while (true) {
		int index = -1;
		system("cls");
		printMenu();
		cin >> input1;
		if (input1 < 1 || 4 < input1) break;
		switch (input1) {
		case 1://Вставка
			appendDeque(deq);
			break;
		case 2://Редактирование
			cout << "Введите индекс редактируемого элемента" << endl << ">";
			while (index < 0 || (int)deq.size() <= index) {
				cin.ignore(1, '\n');
				cin >> index;
			}
			updateDeque(deq, index);
			break;
		case 3://Удаление
			if (deq.size() > 0)
				removeDeque(deq);
			else cout << "Дек не содержит элементов" << endl;
			break;
		case 4://Просмотр
			printDeque(deq);
			break;
		default:
			break;
		}
		system("pause");
	}
	/*5. Создать второй контейнер этого же класса и заполнить его данными
того же типа, что и первый контейнер.*/
	deque<Employee> deq2 = {
	Employee("Иван Робертович", "Президент"),
	Employee("Василий Арсеньевич", "Навигатор"),
	Employee("Анна Сергеевна", "Каменщик"),
	Employee("Руслан Михайлович", "HR"),
	Employee("Григорий Петрович", "Водитель")
	};

	/*6. Изменить первый контейнер, удалив из него n элементов после
заданного и добавив затем в него все элементы из второго контейнера.*/
	cout << "Введите индекс после которого нужно удалить все элементы" << endl << ">";
	int index = -1;
	while (index < 0 || (int)deq.size() <= index) {
		cin.ignore(1, '\n');
		cin >> index;
	}
	while (deq.size() - (index + 1) > 0) {
		deq.pop_back();
	}
	for (auto it = begin(deq2); it < end(deq2); it++) {
		deq.push_back(*it);
	}
	/*7. Просмотреть первый и второй контейнеры.*/
	cout << "Первый дек: " << endl;
	printDeque(deq);
	cout << "Второй дек: " << endl;
	printDeque(deq2);
}


void appendStack(stack<Employee>& s) {
	int input = -1;
	cout << "Введите данные" << endl;
	cin.ignore(1, '\n');
	Employee object;
	cin >> object;
	s.push(object);
}
void updateStack(stack<Employee>& s, int index) {
	cin.ignore(1, 'a');
	Employee object;
	cout << "Введите данные" << endl << ">";
	cin >> object;
	stack<Employee> s1;
	int currIndex = 0;
	while (!s.empty()) {
		if (currIndex == index)
			s1.push(object);
		else {
			s1.push(s.top());
			s.pop();
		}
		currIndex++;
	}
	while (!s1.empty()) {
		s.push(s1.top());
		s1.pop();
	}
}
void removeStack(stack<Employee>& s) {
	s.pop();
}
void printStack(stack<Employee>& s) {
	stack<Employee> s1;
	int currIndex = 0;
	while (!s.empty()) {
		cout << currIndex << ": " << s.top() << endl;
		s1.push(s.top());
		s.pop();
		currIndex++;
	}
	while (!s1.empty()) {
		s.push(s1.top());
		s1.pop();
	}
}
void runProgram2() {
	stack<Employee> stack1;
	stack1.push(Employee("Степан Филиппович", "Слесарь"));
	stack1.push(Employee("Людмила Алексеевна", "Программист"));
	stack1.push(Employee("Павел Генадьевич", "Дизайнер"));
	stack1.push(Employee("Олег Артемович", "Сантехник"));
	stack1.push(Employee("Анастасия Александровна", "Офтальмолог"));
	string path = "output.txt";
	int input1 = -1;
	while (true) {
		int index = -1;
		system("cls");
		printMenu();
		cin >> input1;
		if (input1 < 1 || 4 < input1) break;
		switch (input1) {
		case 1://Вставка
			appendStack(stack1);
			break;
		case 2://Редактирование
			cout << "Введите индекс редактируемого элемента" << endl << ">";
			while (index < 0 || (int)stack1.size() <= index) {
				cin.ignore(1, '\n');
				cin >> index;
			}
			updateStack(stack1, index);
			break;
		case 3://Удаление
			if (stack1.size() > 0)
				removeStack(stack1);
			else cout << "Стек не содержит элементов" << endl;
			break;
		case 4://Просмотр
			printStack(stack1);
			break;
		default:
			break;
		}
		system("pause");
	}
	/*5. Создать второй контейнер этого же класса и заполнить его данными
	того же типа, что и первый контейнер.*/
	stack<Employee> stack2;
	stack2.push(Employee("Иван Робертович", "Президент"));
	stack2.push(Employee("Василий Арсеньевич", "Навигатор"));
	stack2.push(Employee("Анна Сергеевна", "Каменщик"));
	stack2.push(Employee("Руслан Михайлович", "HR"));
	stack2.push(Employee("Григорий Петрович", "Водитель"));

	/*6. Изменить первый контейнер, удалив из него n элементов после
	заданного и добавив затем в него все элементы из второго контейнера.*/
	cout << "Введите индекс после которого нужно удалить все элементы" << endl << ">";
	int index = -1;
	while (index < 0 || (int)stack2.size() <= index) {
		cin.ignore(1, '\n');
		cin >> index;
	}
	//нужно удалить все элементы после индекса
	//сохраняем первые index + 1 элементов в новый стек, затем pop
	stack<Employee> temp1;
	while (!stack1.empty()) {
		temp1.push(stack1.top());
		stack1.pop();
	}
	while ((int)temp1.size() > index + 1) {
		temp1.pop();
	}
	stack<Employee> temp2;
	stack<Employee> temp3;
	while (!stack2.empty()) {
		temp2.push(stack2.top());
		temp3.push(stack2.top());
		stack2.pop();
	}
	while (!temp2.empty() || !temp3.empty()) {
		stack1.push(temp2.top());
		stack2.push(temp3.top());
		temp2.pop();
		temp3.pop();
	}
	while (!temp1.empty()) {
		stack1.push(temp1.top());
		temp1.pop();
	}
	/*7. Просмотреть первый и второй контейнеры.*/
	cout << "Первый стек: " << endl;
	printStack(stack1);
	cout << "Второй стек: " << endl;
	printStack(stack2);
}


void printMultimap(multimap<float, Employee>& m) {
	auto it = m.begin();
	int index = 0;
	while (it != m.end()) {
		cout << index << ": " << (*it++).second << endl;
		index++;
	}
}
void my_copy_if(deque<Employee>& src, stack<Employee>& dest, const function<bool(Employee& emp)> pred) {
	for (auto it = src.begin(); it != src.end(); it++) {
		if (pred(*it)) {
			dest.push(*it);
		}
	}
}
void sortStack(stack<Employee>& s) {
	vector<Employee> v;
	while (!s.empty()) {
		v.push_back(s.top());
		s.pop();
	}
	sort(begin(v), end(v), [](Employee& thisEmp, Employee& otherEmp) {
		return thisEmp > otherEmp;
		});
	for (auto it = v.begin(); it != v.end(); it++) {
		s.push(*it);
	}
}
multimap<float, Employee>& my_merge(deque<Employee>& deq, stack<Employee>& s) {
	multimap<float, Employee> m;
	int index = 0;
	for (auto it = deq.begin(); it != deq.end(); it++) {
		m.insert(make_pair(index, *it));
		index++;
	}
	while (!s.empty()) {
		m.insert(make_pair(index, s.top()));
		s.pop();
		index++;
	}
	return m;
}
int my_count_if(multimap<float, Employee>& m, const function<bool(pair<float, Employee> p)> pred) {
	int count = 0;
	for (auto it = m.begin(); it != m.end(); it++) {
		if (pred(*it)) {
			count++;
		}
	}
	return count;
}
bool my_find_if(multimap<float, Employee>& m, const function<bool(pair<float, Employee> p)> pred) {
	for (auto it = m.begin(); it != m.end(); it++) {
		if (pred(*it)) {
			return true;
		}
	}
	return false;
}
void runProgram3() {
	/*1. Создать первый контейнер, содержащий объекты пользовательского
типа. Тип контейнера выбирается в соответствии с вариантом задания.*/
	deque<Employee> deq = {
		Employee("Степан Филиппович", "Слесарь"),
		Employee("Людмила Алексеевна", "Программист"),
		Employee("Павел Генадьевич", "Дизайнер"),
		Employee("Олег Артемович", "Сантехник"),
		Employee("Анастасия Александровна", "Офтальмолог")
	};
	/*2. Отсортировать его по убыванию элементов.
	  3. Просмотреть контейнер.*/
	cout << "before sort: " << endl;
	printDeque(deq);
	sort(begin(deq), end(deq), [](Employee& thisEmp, Employee& otherEmp) {
		return thisEmp > otherEmp;
		});
	cout << "\nafter sort: " << endl;
	printDeque(deq);
	cout << endl;
	/*4. Используя подходящий алгоритм, найти в контейнере элемент,
	удовлетворяющий заданному условию.*/
	auto it = find_if(begin(deq), end(deq), [](Employee& thisEmp) {
		return thisEmp.GetFio().length() < 17;
		});
	cout << "Сотрудник с именем меньше 17 символов найден: " << endl << *it << endl;
	/*5.Переместить элементы, удовлетворяющие заданному условию в другой
	(предварительно пустой) контейнер. Тип второго контейнера определяется
	вариантом задания.*/
	//Условие: в имени содержится буква 'н'
	stack<Employee> stack1;
	my_copy_if(deq, stack1, [](Employee& emp) {
		return emp.GetFio().find('н') != string::npos;
		});
	//6. Просмотреть второй контейнер.
	printStack(stack1);
	/*7. Отсортировать первый и второй контейнеры по возрастанию
	элементов.*/
	sort(begin(deq), end(deq), [](Employee& thisEmp, Employee& otherEmp) {
		return thisEmp < otherEmp;
		});
	sortStack(stack1);
	//8. Просмотреть их
	cout << "\nПервый контейнер: " << endl;
	printDeque(deq);
	cout << "\nВторой контейнер: " << endl;
	printStack(stack1);
	//9. Получить третий контейнер путем слияния первых двух.
	multimap<float, Employee> m = my_merge(deq, stack1);
	//10. Просмотреть третий контейнер.
	cout << "\nТретий контейнер: " << endl;
	printMultimap(m);
	cout << endl;
	/*11 Подсчитать, сколько элементов, удовлетворяющих заданному
	условию, содержит третий контейнер.*/
	//Условие: первая буква профессии: 'С'
	int count = my_count_if(m, [](pair<float, Employee> p) {
		return p.second.GetPost()[0] == 'С';
		});
	cout << "Кол-во сотрудников, профессия которых начинается на 'С': " << count << endl;
	cout << endl;
	/*12.Определить, есть ли в третьем контейнере элемент, удовлетворяющий
	заданному условию.*/
	bool found = my_find_if(m, [](pair<float, Employee> p) {
		string fio = p.second.GetFio();
		return fio[fio.length() - 1] == 'ч';
		});
	cout << "Есть ли сотрудники, имя которых заканчивается на букву 'ч': " << boolalpha << found << endl;
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	runProgram3();
}

