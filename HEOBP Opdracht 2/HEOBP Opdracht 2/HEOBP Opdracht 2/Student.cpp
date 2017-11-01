#include "stdafx.h"
#include "Student.h"
using namespace std;

Student::Student(string name)
{
	this->name = name;
}

string Student::getName()
{
	return name;
}

void Student::addModule(Modules module)
{
	modules.push_back(module);
}

int Student::getTotalEc()
{
	return ec;
}

void Student::addEc(int _ec)
{
	ec += _ec;
}

void Student::printAllInformation()
{
	cout << "Student" << endl;
	cout << "student name: " << name << endl;
	cout << "total ec`s: " << getTotalEc() << endl;
	cout << "______________________________________" << endl;
}