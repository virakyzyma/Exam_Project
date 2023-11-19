#pragma once
class DebitCard
{
protected:
	double balance = 0;
	double expenses; //затраты
public:
	DebitCard() = default;
	DebitCard(double balance, double expenses);

	double SetBalanceDebit(double Balance);
	void SetExpensesDebit(double expenses);

	double ExpensesDebit(double expenses);

	double GetBalanceDebit();
	double GetExpensesDebit();
};
