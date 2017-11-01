// HEOBP Opdracht 1.cpp : Defines the entry point for the console application.
//Yassine minjon

#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Lesson //De Lesson class is de basis van alle lessen op het rooster en bevat alle variabele die iedere les sowieso nodig heeft.
{
	private:
		int month; 
		int week;
		int day;
		int classRoom;
		int length;
		string time;
		string name;
		string teacher;
		string discription;

	static int numberOfLessons;
	
	public:
		int getMonth(){ return month; }
		int getWeek() { return week; }
		int getDay() { return day; }
		int getClassroom() { return classRoom; }
		int getLength() { return length; }
		string getTime() { return time; }
		string getName() { return name; }
		string getTeacher() { return teacher; }
		string getDiscription() { return discription; }

		void setDate(int monthVal, int weekVal, int dayVal) { month = monthVal; week = weekVal; day = dayVal; }
		void setClassRoom(int classRoomVal) { classRoom = classRoomVal;}
		void setLenght(int lengthVal) { length = lengthVal; }
		void setTime(float timeVal) { time = timeVal; }
		void setName(string lessonName) { name = lessonName; }
		void setTeacher(string teacherName) { teacher = teacher; }
		void setDiscription(string newDiscription) { discription = newDiscription; }

		Lesson();
		Lesson(int monthVal, int weekVal, int dayVal, int classRoomVal, int lengthVal, string timeVal, string nameVal, string teacherVal, string newDiscription);
		~Lesson();
};

int Lesson::numberOfLessons = 0;

Lesson::Lesson(void) { numberOfLessons++; }

Lesson::Lesson(int monthVal, int weekVal, int dayVal, int classRoomVal, int lengthVal, string timeVal, string nameVal, string teacherVal, string newDiscription)
{
	this->month = monthVal;
	this->week = weekVal;
	this->day = dayVal;
	this->classRoom = classRoomVal;
	this->length = lengthVal;
	this->time = timeVal;
	this->name = nameVal;
	this->teacher = teacherVal;
	this->discription = newDiscription;
	numberOfLessons++;
}

Lesson::~Lesson() { numberOfLessons--; }


class KernModule : public Lesson // De KernModule class inherit alle functies en variabele van de Lesson class, de Kernmodule heeft alleen zelf nog een study variabele, deze word gebruikt om aan te geven voor welke studierichting dit kernvak is.
{
	private:
		string study; 

	public:
		string getStudy() { return study; }

		void setStudy(string studyVal) { study = studyVal; }

		KernModule(int monthVal, int weekVal, int dayVal, int classRoomVal, int lengthVal, string timeVal, string nameVal, string teacherVal, string newDiscription, string studyVal);
		KernModule() : Lesson() {};
};

KernModule::KernModule(int monthVal, int weekVal, int dayVal, int classRoomVal, int lengthVal, string timeVal, string nameVal, string teacherVal, string newDiscription, string studyVal)
: Lesson(monthVal ,weekVal ,dayVal ,classRoomVal ,lengthVal ,timeVal ,nameVal ,teacherVal ,newDiscription)
{
	this->study = studyVal;
}


class KeuzeVak : public Lesson // Net als de KernModule class is de KeuzeVak class een Lesson, deze heeft alleen ook een eigen list met de namen van de studenten voor wie dit keuzevak geld.
{
	private:
		list<string> students;
		list<string>::iterator it;

	public:
		list<string> getStudents(){ return students; }

		void addStudents(string studentName) { students.insert(it, studentName); }

		KeuzeVak(int monthVal, int weekVal, int dayVal, int classRoomVal, int lengthVal, string timeVal, string nameVal, string teacherVal, string newDiscription, list<string> studentList);
		KeuzeVak() : Lesson() {};

};

KeuzeVak::KeuzeVak(int monthVal, int weekVal, int dayVal, int classRoomVal, int lengthVal, string timeVal, string nameVal, string teacherVal, string newDiscription, list<string> studentList)
: Lesson(monthVal, weekVal, dayVal, classRoomVal, lengthVal, timeVal, nameVal, teacherVal, newDiscription)
{
	this->students = studentList;
}


class Student // De Student class bevat alle gegevens die de app nodig heeft om de luiste lessen voor iedere student weer te geven.
{
	private:
		int studentNumber;
		string study;
		string name;

	public:
		int getStudentNumber() { return studentNumber; }
		string getStudy() { return study; }
		string getName() { return name; }

		void setStudentNumber(int newStudentNumber) { studentNumber = newStudentNumber; }
		void setStudy(string newStudy) { study = newStudy; }
		void setName(string newName) { name = newName; }

		Student();
};

Student::Student(void){}

int main()
{
	
    return 0;
}

