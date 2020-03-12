#pragma once
#include "Account.h"
/*
1. Add a Checking Account class to the Account hierarchy
A checking account has a name and a balance and has a fee of $1.50 per withdrawal transaction.
Every withdrawal transaction will be asses this flat fee.
*/

class Checkings_Account : public Account
{
	friend std::ostream &operator<<(std::ostream &os, const Checkings_Account &account);
private:
	static constexpr const char *def_name = "Unnamed account";
	static constexpr double fee = 1.5;	
	static constexpr double balance = 0;
public:	
	Checkings_Account(std::string name = def_name, double balance = balance);
	bool withdraw(double amount);
};

