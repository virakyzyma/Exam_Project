#include "DebitCard.h"
#include <iostream>
using namespace std;
DebitCard::DebitCard(double balance, double expenses)
{
	this->balance = balance;
	this->expenses = expenses;
}
double DebitCard::SetBalanceDebit(double Balance)
{
	
	balance = balance + Balance;
	return balance;
}
void DebitCard::SetExpensesDebit(double expenses)
{ 
	this->expenses = expenses;
}
double DebitCard::GetBalanceDebit()
{
	return balance;
}
double DebitCard::ExpensesDebit(double Expenses)
{
	if (balance >= Expenses)
	{
		balance = balance - Expenses;
	}
	return balance;
}