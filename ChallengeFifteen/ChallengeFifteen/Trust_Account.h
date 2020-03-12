#pragma once
#include "Savings_Account.h"

/*
2. Add a Trust Account class to the Account hierarchy
A Trust Account has a name, balance, and an interest rate
The Trust Account deposit works just like a savings account deposit.
However, any deposit of $5000.00 or more will receive a $50.00 bonus deposit to the account.

The Trust account withdrawal should only allow 3 withdrawals per year and each of these must be less thatn 20% of the account balance.
You don't have to keep track of calendar time for this application, just make sure the 4th deposit fails.
*/

class Trust_Account : public Savings_Account
{
	friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
private:
	static constexpr const char *def_name = "Unnamed account";
	static constexpr const double def_balance = 0, def_int_rate = 0;
	static constexpr const double max_withdraw_percent = 0.2;
	static constexpr const double bonus_deposit = 50, max_for_bonus = 5000;
	int withdraw_times = 3;
public:
	Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
	bool deposit(double amount);
	bool withdraw(double amount);
	int get_withdraw_times() const;
};

