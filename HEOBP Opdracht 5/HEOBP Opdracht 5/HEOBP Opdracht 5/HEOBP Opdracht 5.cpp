// HEOBP Opdracht 5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Bankrekening.h"
#include "Transactie.h"
#include <iostream>
#include <string>


int main()
{
	Bankrekening rekening = Bankrekening(0.0);
	Transactie transactie = Transactie(rekening);

	
	transactie.Deposit(15.0);
	transactie.Deposit(15.0);
	transactie.Deposit(15.0);
	std::cout << transactie.rekening << std::endl;
    return 0;
}

