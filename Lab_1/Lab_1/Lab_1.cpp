#include <iostream>
#include <iomanip>
#include <stack>
#include <map>
#include <list>

using namespace std;

//Вариант 5
/*
* Написать программу согласно варианта. Для организации стека или
очереди можно использовать стандартные функции.
Каждый разрабатываемый класс должен, как правило, содержать
следующие элементы: скрытые поля, конструктор по умолчанию, конструктор с
параметрами, конструктор со списком инициализации переменных, конструктор
копирования, деструктор, методы: изменения, отображения полей класса и
методы согласно задания, дружественные функции, методы для установки и
возвращения значений полей, методы согласно задания. Функциональные
элементы класса должны обеспечивать непротиворечивый, полный,
минимальный и удобный интерфейс класса.
* 1. Описать класс для хранения следующей информации:
– Ф.И.О.,
– должность,
– оклад,
– дата поступления на работу,
– стаж к моменту поступления.
2. Предусмотреть возможность добавления и вывод на экран объектов класса.
Для хранения данных использовать стек.
3. Определить средний оклад лиц, принятых на работу по каждой из
встречающихся должностей.
*/
class Employee {
private:
    string _fio;
    string _post;
    int _salary;
    string _emp_date;
    int _work_exp;

public:
    Employee() {
        _fio = "";
        _post = "";
        _salary = 0;
        _emp_date = "";
        _work_exp = 0;
    }
    Employee(string fio, string post, int salary, string emp_date, int work_exp) : 
        _fio(fio), _post(post), _salary(salary), _emp_date(emp_date), _work_exp(work_exp) { }
    Employee(string fio, string post) {
        _fio = fio;
        _post = post;
    }
    Employee(const Employee& other) {
        _fio = other._fio;
        _post = other._post;
        _salary = other._salary;
        _emp_date = other._emp_date;
        _work_exp = other._work_exp;
    }
    ~Employee() {};

    string GetFio() {
        return _fio;
    }
    void SetFio(string new_fio) {
        _fio = new_fio;
    }
    string GetPost() {
        return _post;
    }
    void SetPost(string new_post) {
        _post = new_post;
    }
    int GetSalary() {
        return _salary;
    }
    void SetSalary(int new_salary) {
        _salary = new_salary;
    }
    string GetEmpDate() {
        return _emp_date;
    }
    void SetEmpDate(string new_emp_date) {
        _emp_date = new_emp_date;
    }
    int GetWorkExp() {
        return _work_exp;
    }
    void SetWorkExp(int new_work_exp) {
        _work_exp = new_work_exp;
    }
    friend void Print(Employee);
};

void Print(Employee e) {
    cout << "FIO: " << e._fio << " Post: " << e._post << " Salary: " << e._salary <<
        " Emp_date: " << e._emp_date << " Work_exp: " << e._work_exp << endl;
}
int main()
{
    stack<Employee> employees;
    Employee e = Employee("John Green", "programmer", 5000, "20.02.2005", 15);
    Print(e);
    cout << e.GetFio() << endl;
    employees.push(e);
    employees.push(Employee("Laura Palmer", "programmer", 9000, "10.07.1998", 18));
    employees.push(Employee("Anders Hejlsberg", "programmer", 4000, "10.07.2002", 13));
    employees.push(Employee("James Dean", "actor", 12000, "01.01.1954", 5));
    employees.push(Employee("Fay Valentine", "actor", 6000, "10.07.1998", 18));
    employees.push(Employee("Jane Taylor", "manager", 25000, "19.06.1995", 20));
    employees.push(Employee("George Smith", "manager", 3000, "20.02.2012", 6));
    
    map<string, list<Employee>> post_employees;
    while(!employees.empty()) {
        post_employees[employees.top().GetPost()].push_back(employees.top());
        employees.pop();
    }
    
    for (auto it = post_employees.begin(); it != post_employees.end(); it++) {
        float avg_salary = 0.0;
        int emp_count = 0;
        for (auto emp : it->second) {
            avg_salary += emp.GetSalary();
            emp_count++;
        }
        cout.setf(ios::left);
        cout << "post: " << setw(12) << it->first << " avg_salary: " << avg_salary/emp_count << endl;
    }

}