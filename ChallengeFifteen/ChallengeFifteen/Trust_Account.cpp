#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
	: Savings_Account{ name, balance, int_rate }
{
}

bool Trust_Account::deposit(double amount)
{
	if (amount > 0)
	{
		if (amount >= max_for_bonus)
		{
			amount += ((amount * int_rate / 100) + bonus_deposit);
		}
		else
		{
			amount += (amount * int_rate / 100);
		}
		return Account::deposit(amount);
	}
	else
		return false;
}

bool Trust_Account::withdraw(double amount)
{
	if (withdraw_times > 0 && amount <= (balance * max_withdraw_percent))
	{
		if (Account::withdraw(amount))
		{
			withdraw_times--;
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

int Trust_Account::get_withdraw_times() const { return withdraw_times; }

std::ostream &operator<<(std::ostream &os, const Trust_Account &account)
{
	os << "Trust Account: " << account.name << ", " << account.balance << ", " << account.int_rate << ", withdraw times left: " << account.withdraw_times;
	return os;
}