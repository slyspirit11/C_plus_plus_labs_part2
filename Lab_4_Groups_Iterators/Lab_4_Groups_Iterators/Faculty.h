#pragma once
#include "Department.h"

class Faculty : public Department
{
public:
	Faculty();
	Faculty(string name, Person* head = NULL);
	virtual ~Faculty() override;
	virtual void Show() override;	
};