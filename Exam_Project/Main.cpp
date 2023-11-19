#include <iostream>
#include "CreditCard.h"
#include "DebitCard.h"
#include <map>
#include <algorithm>
#include <fstream>
using namespace std;

typedef pair<string, int> money;

void Expenses(multimap<string, int>& expenses)
{
	string str;
	int sum;
	cout << "Enter day/week/month: ";
	cin >> str;
	cout << "Sum of expenses: ";
	cin >> sum;
	expenses.insert(money(str, sum));
	
}
void Show(multimap<string, int>& expenses)
{
	for (auto it = expenses.begin(); it != expenses.end(); it++)
	{
		cout << it->first << " - " << it->second << endl;
	}
}


int main()
{
	multimap<string, int> EducationExpensesDebit;
	multimap<string, int> TravelExpensesDebit;
	multimap<string, int> EducationExpensesCredit;
	multimap<string, int> TravelExpensesCredit;
	fstream file("Expenses1.txt", ios::in | ios::out);
	fstream file2("Expenses2.txt", ios::in | ios::out);

	DebitCard debitCard;
	CreditCard creditCard;
	
	int menu;
	double topUp1;
	double topUp2;
	double c;

	cout << "You have debit card and credit card\n";
	do
	{
		cout << "\n1.Top up your debit card\n2.Top up your credit card\n3.Enter debit card expenses\n4.Enter credit card expenses\n5.Show debit card expenses report\n6.Show credit card expenses report\n7.Exit\nEnter: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << "\nCurrent balance: " << debitCard.GetBalanceDebit();
			cout << "\nEnter sum: ";
			cin >> topUp1;
			debitCard.SetBalanceDebit(topUp1);
			cout << "\nCurrent balance: " << debitCard.GetBalanceDebit();
			break;
		case 2:
			cout << "\nCurrent balance on credit card: "  << creditCard.GetBalanceCredit();
			cout << "\nEnter sum: ";
			cin >> topUp2;
			creditCard.SetBalanceCredit(topUp2);
			cout << "\nCurrent balance: " << creditCard.GetBalanceCredit();
			break;
		case 3:
			Expenses(EducationExpensesDebit);
			for (auto it = EducationExpensesDebit.begin(); it != EducationExpensesDebit.end(); it++)
			{
				file << it->first << " - " << it->second << endl;
				c = it->second;
			}
			debitCard.ExpensesDebit(c);	
			Expenses(TravelExpensesDebit);
			for (auto it = TravelExpensesDebit.begin(); it != TravelExpensesDebit.end(); it++)
			{
				file << it->first << " - " << it->second << endl;
				c = it->second;
			}
			debitCard.ExpensesDebit(c);
			break;
		case 4:
			Expenses(EducationExpensesCredit);
			for (auto it = EducationExpensesCredit.begin(); it != EducationExpensesCredit.end(); it++)
			{
				file2 << it->first << " - " << it->second << endl;
				c = it->second;
			}
			creditCard.ExpensesCredit(c);
			Expenses(TravelExpensesDebit);
			for (auto it = TravelExpensesDebit.begin(); it != TravelExpensesDebit.end(); it++)
			{
				file << it->first << " - " << it->second << endl;
				c = it->second;
			}
			creditCard.ExpensesCredit(c);
			break;
		case 5:
			cout << "\tCategory\t";
			cout << "\nEducation: ";
			Show(EducationExpensesDebit);
			cout << "\nTravel: ";
			Show(TravelExpensesDebit);
			break;
		case 6:
			cout << "\tCategory\t";
			cout << "\nEducation: ";
			Show(EducationExpensesCredit);
			cout << "\nTravel: ";
			Show(TravelExpensesCredit);
			break;
		default:
			break;
		}
	} while (menu != 7);


	return 0;
}