#include "CreditCard.h"
#include <iostream>
using namespace std;
CreditCard::CreditCard(double balance, double expenses)
{
	this->balance = balance;
	this->expenses = expenses;
}
void CreditCard::SetBalanceCredit(double Balance)
{
	balance = balance + Balance;
}
void CreditCard::SetExpensesCredit(double expenses)
{
	this->expenses = expenses;
}
double CreditCard::GetBalanceCredit()
{
	return balance;
}
double CreditCard::GetExpensesCredit()
{
	return expenses;
}
double CreditCard::ExpensesCredit(double Expenses)
{
	if (balance >= Expenses)
	{
		balance = balance - Expenses;
	}
	return balance;
}