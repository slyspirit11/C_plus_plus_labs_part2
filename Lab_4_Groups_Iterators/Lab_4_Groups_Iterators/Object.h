#pragma once

#include <iostream>
#include <iomanip>
using namespace std;

class Object
{
public:
	virtual void Show() = 0;
	virtual ~Object() {};
};