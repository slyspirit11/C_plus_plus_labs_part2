#pragma once
#include "Person.h"
class Student : public Person
{
private:
	float avgScore;
public:
	Student(string name, bool add = false);
	void SetAvgScore(float score);
	float GetAvgScore();
	~Student() override;
	void Show() override;
};

