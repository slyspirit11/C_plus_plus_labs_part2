#pragma once
#include "Professor.h"
class HeadOfDepartment : public Professor
{
private:
	string department;
public:
	HeadOfDepartment(string name, bool add = false);
	~HeadOfDepartment() override;
	void Show() override;
};

