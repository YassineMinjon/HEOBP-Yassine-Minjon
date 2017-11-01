#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Bankrekening
{
	public:
		string log = "";
		Bankrekening();
		Bankrekening(float saldo);
		float GetSaldo();
		Bankrekening operator+(const float& value);
		Bankrekening& operator+=(float value);
		friend ostream& operator<<(ostream& lhs, Bankrekening& rekening);
		string GetLog();

	private:
		float saldo = 0;
		
};