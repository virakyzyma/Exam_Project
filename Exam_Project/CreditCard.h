#pragma once
class CreditCard
{
protected:
	double balance = 10000;
	double expenses; //затраты
public:
	CreditCard() = default;
	CreditCard(double balance, double expenses);

	void SetBalanceCredit(double balance);
	void SetExpensesCredit(double Balance);

	double GetBalanceCredit();
	double GetExpensesCredit();

	double ExpensesCredit(double expenses);
};