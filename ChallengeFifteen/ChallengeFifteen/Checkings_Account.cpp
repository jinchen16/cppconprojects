#include "Checkings_Account.h"

Checkings_Account::Checkings_Account(std::string name, double balance)
	: Account{ name, balance }
{
}

bool Checkings_Account::withdraw(double amount)
{
	amount -= fee;
	return Account::withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const Checkings_Account &account) 
{
	os << "Checking account: " + account.name << ", " << account.balance << ", fee per withdrawal: " << account.fee;
	return os;
};
