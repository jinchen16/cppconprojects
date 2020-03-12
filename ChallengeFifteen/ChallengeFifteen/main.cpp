// Section 15 Challenge
// Inheritance

/*
1. Add a Checking Account class to the Account hierarchy
A checking account has a name and a balance and has a fee of $1.50 per withdrawal transaction.
Every withdrawal transaction will be asses this flat fee.

2. Add a Trust Account class to the Account hierarchy
A Trust Account has a name, balance, and an interest rate
The Trust Account deposit works jus like a savings account deposit.
However, any deposit of $5000.00 or more will receive a $50.00 bonus deposit to the account.

The Trust account withdrawal should only allow 3 withdrawals per year and each of these must be less thatn 20% of the account balance.
You don't have to keep track of calendar time for this application, just make sure the 4th deposit fails.
*/

#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Checkings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main()
{
	cout.precision(2);
	cout << fixed;

	// Accounts
	vector<Account> accounts;
	accounts.push_back(Account{});
	accounts.push_back(Account{ "Larry" });
	accounts.push_back(Account{ "Moe", 2000 });
	accounts.push_back(Account{ "Curly", 5000 });

	display(accounts);
	deposit(accounts, 1000);
	withdraw(accounts, 2000);

	// Savings
	vector<Savings_Account> sav_accounts;
	sav_accounts.push_back(Savings_Account{});
	sav_accounts.push_back(Savings_Account{ "Superman" });
	sav_accounts.push_back(Savings_Account{ "Batman", 2000 });
	sav_accounts.push_back(Savings_Account{ "Wonderwoman", 5000, 5.0 });

	display(sav_accounts);
	deposit(sav_accounts, 1000);
	withdraw(sav_accounts, 2000);

	// Checking
	vector<Checkings_Account> check_accounts;
	check_accounts.push_back(Checkings_Account{});
	check_accounts.push_back(Checkings_Account{"Kirk"});
	check_accounts.push_back(Checkings_Account{"Spock", 2000});
	check_accounts.push_back(Checkings_Account{"Spock2", 500});

	display(check_accounts);
	deposit(check_accounts, 1000);
	withdraw(check_accounts, 2000);

	// Trust
	vector<Trust_Account> trust_accounts;
	trust_accounts.push_back(Trust_Account{});
	trust_accounts.push_back(Trust_Account{"Athos", 10000, 5.0});
	trust_accounts.push_back(Trust_Account{"Porthos", 20000, 4.0});
	trust_accounts.push_back(Trust_Account{"Aramis", 30000});

	display(trust_accounts);
	deposit(trust_accounts, 1000);
	withdraw(trust_accounts, 3000);

	for (size_t i = 0; i < 5; i++)
	{
		withdraw(trust_accounts, 1000);

	}
	return 0;
}