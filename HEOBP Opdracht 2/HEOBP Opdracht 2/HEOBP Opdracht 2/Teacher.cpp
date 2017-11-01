#include "stdafx.h"
#include "Teacher.h"
using namespace std;

Teacher::Teacher(){}

Teacher::Teacher(string name)
{
	this->name = name;
}

string Teacher::getName()
{
	return name;
}