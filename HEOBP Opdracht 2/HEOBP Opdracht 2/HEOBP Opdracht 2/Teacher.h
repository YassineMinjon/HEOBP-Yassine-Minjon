#pragma once
using namespace std;
#include<string>



class Teacher 
{
	public:
		Teacher();
		Teacher(string name);
		string getName();

	private:
		string name;
};