#pragma once
#include "Faculty.h"

class StudentGroup : public Faculty
{
public:
	StudentGroup();
	StudentGroup(string name);
	~StudentGroup() override;
	void Show() override;
	void ForEach(void(*action)(Object* obj, float score), float avgScore);
};