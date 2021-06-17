#pragma once
#include "Person.h"
#include <iomanip>
#include <iostream>

using namespace std;
class Professor : public Person
{
protected:
    string faculty;
public:
    Professor(string name, bool add = false);
    virtual ~Professor() override;
    virtual void Show() override;
};

