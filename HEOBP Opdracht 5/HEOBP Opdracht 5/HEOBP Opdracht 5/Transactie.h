#pragma once
#include <iostream>
#include <fstream>
#include <time.h> 
#include "Bankrekening.h"

class Bankrekening;

class Transactie
{
	public:
		Transactie(Bankrekening rekening);
		void Deposit(float amount);
		Bankrekening rekening;
		
};
