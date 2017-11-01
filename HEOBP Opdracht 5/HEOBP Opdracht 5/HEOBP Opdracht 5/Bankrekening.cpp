#include "Bankrekening.h"
#include <string> 
#include <iostream>
#include <time.h>
#include <ctime>
 

using namespace std;

Bankrekening::Bankrekening()
{
	this->saldo = 0;
}

Bankrekening::Bankrekening(float saldo)
{
	this->saldo = saldo;
}

float Bankrekening::GetSaldo()
{
	return saldo;
}


Bankrekening Bankrekening::operator+(const float& value)
{
	time_t  timev;
	time(&timev);
	log += "\n";
	log += "Transactie....... Hoeveelheid:  " + to_string(value) + " ...... nieuw totaal: " + to_string(saldo + value) + " ..... Datum: " + ctime(&timev);
	Bankrekening rekening = Bankrekening(saldo + value);
	rekening.log = log;
	return rekening;
}

Bankrekening& Bankrekening::operator+=(float value)  
{
	saldo += value;
	time_t  timev;
	time(&timev);
	log += "\n";
	log += "Transactie....... Hoeveelheid:  " + to_string(value) + " ...... nieuw totaal: " + to_string(saldo + value) + " ..... Datum: " + ctime(&timev);
	return *this;
}

string Bankrekening::GetLog()
{
	return log;
}

ostream& operator<<(ostream &lhs, Bankrekening& bankrekening)
{
	lhs << "deze rekening heeft een saldo van: " << bankrekening.GetSaldo() << " Log: " << bankrekening.GetLog();
	return lhs;
}




