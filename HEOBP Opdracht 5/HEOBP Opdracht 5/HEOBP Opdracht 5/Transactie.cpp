#include "Transactie.h"

using namespace std;

Transactie::Transactie(Bankrekening rekening)
{
	this->rekening = rekening;
}

void Transactie::Deposit(float amount)
{
	rekening = rekening + amount;
}
