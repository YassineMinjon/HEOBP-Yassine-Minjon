#pragma once

#include<string>
#include <vector>
#include "Modules.h"

using namespace std;

class Modules;

class Student
{
	public:
		Student(string name);
		string getName();
		void addModule(Modules module);
		int getTotalEc();
		void addEc(int _ec);
		void printAllInformation();

	private:
		string name;
		vector<Modules> modules;
		int ec;
};

