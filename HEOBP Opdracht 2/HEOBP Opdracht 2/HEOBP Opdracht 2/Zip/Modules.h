#pragma once

#include <string>
#include "Teacher.h"
#include "Student.h"
#include <vector>
#include <iostream>

using namespace std;

class Student;

class Modules
{
	public:
		Modules(string name, Teacher teacher, int ec);
		string getName();
		string getTeacher();
		int getAmountOfStudents();
		Student getStudentInfo(int index);
		int getEc();
		void addStudent(Student student);
		void printStudents();
		

	private:
		string name;
		Teacher teacher;
		vector<Student> students;
		int ec;
};