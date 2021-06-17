#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

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
    Employee(string fio) : Employee() {
        _fio = fio;
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
    bool operator==(const Employee& other){
        return 
            this->_fio == other._fio &&
            this->_post == other._post &&
            this->_salary == other._salary &&
            this->_emp_date == other._emp_date &&
            this->_work_exp == other._work_exp;
    }
    friend ostream& operator<<(ostream& out, Employee& emp);
    friend void Print(Employee);
};

void Print(Employee e) {
    cout << "FIO: " << e._fio << " Post: " << e._post << " Salary: " << e._salary <<
        " Emp_date: " << e._emp_date << " Work_exp: " << e._work_exp << endl;
}

ostream& operator<<(ostream& out, Employee& emp) {
    out << emp._fio;
    return out;
}