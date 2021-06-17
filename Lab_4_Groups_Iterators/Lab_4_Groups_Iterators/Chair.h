#pragma once
#include "Faculty.h"

class Chair : public Faculty
{
public:
	Chair();
	Chair(string name);
	~Chair() override;
	void Show() override;
};