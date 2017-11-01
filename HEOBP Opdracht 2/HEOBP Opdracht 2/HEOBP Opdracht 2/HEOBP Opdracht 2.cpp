// HEOBP Opdracht 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <random>
#include "Modules.h"
#include "Student.h"
#include "Teacher.h"

using namespace std;

int main()
{
	Teacher docent1 = Teacher("john");
	Teacher docent2 = Teacher("frans");
	Teacher docent3 = Teacher("willem");


	Modules les1 = Modules("les1", docent1, 1);
	Modules les2 = Modules("les2", docent2, 3);
	Modules les3 = Modules("les3", docent3, 5);

	vector<Modules> modules = vector<Modules>();

	modules.push_back(les1);
	modules.push_back(les2);
	modules.push_back(les3);

	vector<Modules>::iterator modulesIt = modules.begin();


	Student student1 = Student("jan");
	Student student2 = Student("peter");
	Student student3 = Student("herman");
	Student student4 = Student("robin");
	Student student5 = Student("richard");
	Student student6 = Student("wendy");
	Student student7 = Student("susan");
	Student student8 = Student("fred");
	Student student9 = Student("geert");
	Student student10 = Student("thomas");


	vector<Student> studenten = vector<Student>();

	studenten.push_back(student1);
	studenten.push_back(student2);
	studenten.push_back(student3);
	studenten.push_back(student4);
	studenten.push_back(student5);
	studenten.push_back(student6);
	studenten.push_back(student7);
	studenten.push_back(student8);
	studenten.push_back(student9);
	studenten.push_back(student10);

	vector<Student>::iterator studentenIt = studenten.begin();




	for (int x = 0; x < 4; x++)
	{
		modules[0].addStudent(studentenIt[x]);
		studentenIt[x].addModule(modules[0]);
	}

	for (int x = 0; x < 7; x++)
	{
		modules[1].addStudent(studentenIt[x]);
		studentenIt[x].addModule(modules[1]);
	}

	for (int x = 0; x < 10; x++)
	{
		modules[2].addStudent(studentenIt[x]);
		studentenIt[x].addModule(modules[2]);
	}


	for (int i = 0; i < 3; i++)
	{
		cout << " " << endl;
		cout << "This is : " << modulesIt[i].getName() << endl;
		cout << "This module is given by: " << modulesIt[i].getTeacher() << endl;
		cout << "It is worth: " << modulesIt[i].getEc() << " ec`s " << endl;
		cout << "It has the following students: " << endl;
		cout<<" "<<endl;

		for (int o = 0; o < modulesIt[i].getAmountOfStudents(); o++)
		{
			modulesIt[i].getStudentInfo(o).printAllInformation();
		}
	}

    return 0;
}

