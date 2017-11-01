#include "stdafx.h"
#include "Modules.h"

using namespace std;

Modules::Modules(string name, Teacher teacher, int ec)
{
	this->name = name;
	this->teacher = teacher;
	this->ec = ec;
}

string Modules::getName()
{
	return name;
}

string Modules::getTeacher()
{
	return teacher.getName();
}

int Modules::getAmountOfStudents()
{
	return students.size();
}

Student Modules::getStudentInfo(int index)
{
	vector<Student>::iterator it = students.begin();
	return it[index];
}

int Modules::getEc()
{
	return ec;
}

void Modules::addStudent(Student student)
{
	students.push_back(student);
	student.addEc(this->getEc());
}

void Modules::printStudents()
{
	vector<Student>::iterator it = students.begin();
	cout << "This Module has the following students: " << endl;
	while (it != students.end())
	{
		cout << it->getName() << endl;
		it++;
	}
}