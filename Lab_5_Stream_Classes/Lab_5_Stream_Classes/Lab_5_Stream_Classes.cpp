#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <Windows.h>
#include "Headers.h"
#include "Manipulator.h"
#include <vector>


using namespace std;

Node* Person::begin = new Node;
Person* chooseObject();
void write(Person*, string path);
void read(string path);
void writeAlternative(Person* person, string path);
void readAlternative(string path);
bool remove(int recordNumber, string path);
bool update(int recordNumber, string path);
streampos find(string name, string path);
vector<string>split(const string& s, char delim);
int count(string path);


void testOpenFile(string path) {
	//создание потоков и открытие файла 3мя способами
	//1 спобоб(filebuf), запись
	filebuf fbuf;
	fbuf.open(path, ios::out | ios::app);
	ostream stream1(&fbuf);
	fbuf.close();
	//2 способ(ifstream), чтение
	ifstream stream2;
	stream2.open(path, ios::in | ios::beg);
	stream2.close();
	//3 способ(fstream), чтение и запись
	fstream stream3;
	stream3.open(path, ios::out);
	//string name = "George Orwell";
	//stream3 << name << '\n';
	//stream3 << "Elisabeth Young" << '\n';
	stream3.close();
	stream3.open(path, ios::in);
	//string f = "";
	//while (!stream3.eof()) {
	//    f = "";
	//    getline(stream3, f);
	//    cout << f << endl;
	//}
	stream3.close();

}

void printMenu1() {
	cout << "1. Добавить\n2. Изменить\n3. Удалить\n4. Вывести записанные объекты\n";
}


void start() {
	string path = "output.txt";
	string inputString;
	int input = -1;
	while (true) {
		int recordNumber = -1;
		system("cls");
		cout << "Всего записей: " << count(path) << endl;
		printMenu1();
		try {
			cin >> inputString;
			input = stoi(inputString);
			if (input < 1 || 4 < input) break;
			switch (input) {
			case 1://Добавление объекта в файл
				write(chooseObject(), path);
				cout << "Запись успешно завершена" << endl;
				break;
			case 2://Изменение объекта
				cout << "Введите номер записи" << endl;
				cin.ignore(1, '\n');
				cin >> recordNumber;
				update(recordNumber, path) ?
					cout << "запись под номером " << recordNumber << " успешно изменена" << endl :
					cout << "запись под номером " << recordNumber << " найти не удалось" << endl;
				break;
			case 3://Удаление объекта
				cout << "Введите номер записи" << endl;
				cin.ignore(1, '\n');
				cin >> recordNumber;
				remove(recordNumber, path) ?
					cout << "запись под номером " << recordNumber << " успешно удалена" << endl :
					cout << "запись под номером " << recordNumber << " найти не удалось" << endl;
				break;
			case 4://Вывод всех записей
				readAlternative(path);
				break;
			default:
				break;
			}
		}
		catch (exception e) {
			input = -1;
			cout << e.what();
		}
		ofstream out("", ios::in);
		system("pause");
	}
}

void printMenu2() {
	cout << "1. Professor\n2. HeadOfDepartment\n3. Student\n";
}

Person* chooseObject() {
	cout << "\nВыберите тип объекта\n";
	string inputString;
	int input = -1;
	Person* p = nullptr;
	while (true) {
		//system("cls");
		printMenu2();
		string name;
		try {
			cin >> inputString;
			cout << '\n';
			input = stoi(inputString);
			if (input < 1 || 4 < input) break;
			switch (input) {
			case 1://Профессор
				p = new Professor("");
				cout << "Введите имя профессора" << endl;
				cin.ignore(1, '\n');
				cin >> *p;
				return p;
			case 2://Глава кафедры
				p = new HeadOfDepartment("");
				cout << "Введите имя главы кафедры" << endl;
				cin.ignore(1, '\n');
				cin >> *p;
				return p;
			case 3://Студент
				p = new Student("");
				cout << "Введите имя студента" << endl;
				cin.ignore(1, '\n');
				cin >> *p;
				return p;
			default:
				break;
			}
		}
		catch (exception e) {
			input = -1;
			cout << e.what();
			break;
		}
	}
	return p;
}

void write(Person* person, string path) {
	ofstream outStream;
	outStream.open(path, ios::out | ios::app);
	if (typeid(*person).name() == (string)("class Professor")) {
		outStream << *person << "," << "professor" << "\n";
	}
	else if (typeid(*person).name() == (string)("class HeadOfDepartment")) {
		outStream << *person << "," << "hod" << "\n";
	}
	else if (typeid(*person).name() == (string)("class Student")) {
		outStream << *person << "," << "student" << "\n";
	}
	else {
		throw exception("unknown object type");
	}
	outStream.close();
	delete person;
}

void writeAlternative(Person* person, string path) {
	ofstream outStream;
	outStream.open(path, ios::out | ios::app);
	if (typeid(*person).name() == (string)("class Professor")) {
		string s = (person)->GetName();
		s.append(",professor");
		outStream.write(s.c_str(), s.length());
	}
	else if (typeid(*person).name() == (string)("class HeadOfDepartment")) {
		string s = (person)->GetName();
		s.append(",hod");
		outStream.write(s.c_str(), s.length());
	}
	else if (typeid(*person).name() == (string)("class Student")) {
		string s = (person)->GetName();
		s.append(",student");
		outStream.write(s.c_str(), s.length());
	}
	else {
		throw exception("unknown object type");
	}
	outStream.close();
	delete person;
}

void read(string path) {
	ifstream reader;
	string record;
	manip m = wp(30, '|');
	reader.open(path, ios::in);
	while (getline(reader, record)) {
		cout << m << record << endl;
	}
	reader.close();
}

void readAlternative(string path) {
	ifstream reader;
	string record;
	manip m = wp(30, '|');
	reader.open(path, ios::in);
	while (!reader.eof()) {
		streampos startPos = reader.tellg();
		getline(reader, record);
		streampos endPos = reader.tellg();
		reader.seekg(startPos);
		reader.read(&record[0], endPos - startPos - 1);
		if (record == "") break;
		cout << m << record << endl;
	}
	reader.close();
}

bool remove(int recordNumber, string path) {
	fstream reader;
	int recordIndex = 0;
	string fileText = "";
	string record = "";
	bool isDeleted = false;
	reader.open(path, ios::in);
	while (getline(reader, record)) {
		if (recordNumber != recordIndex + 1) {
			fileText.append(record);
			fileText.append("\n");
		}
		else isDeleted = true;
		recordIndex++;
	}
	reader.close();
	fstream writer;
	writer.open("output.txt", ios::out);
	writer << fileText;
	writer.close();
	return isDeleted;
}

bool update(int recordNumber, string path) {
	fstream reader;
	int recordIndex = 0;
	string fileText = "";
	string record = "";
	bool isUpdated = false;
	reader.open(path, ios::in);
	while (getline(reader, record)) {
		if (recordNumber != recordIndex + 1) {
			fileText.append(record);
			fileText.append("\n");
		}
		else {
			cout << "Изменение записи" << endl;
			cout << record << '\n';
			Person* person = chooseObject();
			if (typeid(*person).name() == (string)("class Professor")) {
				fileText.append(person->GetName());
				fileText.append(",professor\n");
			}
			else if (typeid(*person).name() == (string)("class HeadOfDepartment")) {
				fileText.append(person->GetName());
				fileText.append(",hod\n");
			}
			else if (typeid(*person).name() == (string)("class Student")) {
				fileText.append(person->GetName());
				fileText.append(",student\n");
			}
			else {
				throw exception("unknown object type");
			}
			isUpdated = true;
		}
		recordIndex++;
	}
	reader.close();
	fstream writer;
	writer.open("output.txt", ios::out);
	writer << fileText;
	writer.close();
	return isUpdated;

}

int count(string path) {
	ifstream reader;
	reader.open(path, ios::in);
	string record = "";
	int count = 0;
	while (getline(reader, record)) {
		count++;
	}
	reader.close();
	return count;
}

streampos find(string name, string path) {
	ifstream reader;
	reader.open(path, ios::in);
	string record = "";
	int offset = 0;
	while (!reader.eof()) {
		record = "";
		streampos pos = reader.tellg();
		getline(reader, record);
		if (record.length() > 0)
		{
			auto words = split(record, ',');
			if (words[0] == name) {
				reader.close();
				return pos;
			}
		}
	}
	reader.close();
	return -1;
}

vector<string> split(const string& s, char delim) {
	vector<string> elems;
	stringstream ss;
	ss.str(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Person::begin->next = NULL;
	start();
	//testOpenFile(path);
}