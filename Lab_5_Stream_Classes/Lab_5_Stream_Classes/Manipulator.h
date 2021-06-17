#pragma once
#include<fstream>
#include<iomanip>
#include<string>
#include<iostream>

using namespace std;

typedef ostream& (*funcPointer)(ostream&, int, char);
class manip
{
public:
	int width; char fill; funcPointer fp;
	manip(funcPointer FP, int W, char FILL) :fp(FP), width(W), fill(FILL) {

	}
	friend ostream& operator<<(ostream& out, manip man);
};

ostream& fmanip(ostream& ostream, int w, char fill)
{
	ostream.width(w);
	ostream.fill(fill);
	ostream.setf(ios::showbase, ios::left);	
	return ostream;
}
manip wp(int W, char FILL)
{
	return manip(fmanip, W, FILL);
}


ostream& operator<<(ostream& out, manip m)
{
	return m.fp(out, m.width, m.fill);
}
