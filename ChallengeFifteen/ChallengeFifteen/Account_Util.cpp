#include <iostream>
#include "Account_Util.h"

// Utility helper functions for Account class
void display(const std::vector<Account> &accounts)
{
	std::cout << "\n=== Accounts ============" << std::endl;
	for (const auto &acc : accounts)
		std::cout << acc << std::endl;
}

void deposit(std::vector<Account> &accounts, double amount)
{
	std::cout << "\n=== Depositing to Accounts ============" << std::endl;
	for (auto &acc : accounts)
	{
		if (acc.deposit(amount))
			std::cout << "Deposited " << amount << " to " << acc << std::endl;
		else
			std::cout << "Failed to deposit of " << amount << " to " << acc << std::endl;
	}
}

void withdraw(std::vector<Account> &accounts, double amount)
{
	std::cout << "\n=== Withdrawing to Accounts ============" << std::endl;
	for (auto &acc : accounts)
	{
		if (acc.withdraw(amount))
			std::cout << "Withdrew " << amount << " to " << acc << std::endl;
		else
			std::cout << "Failed to withdraw of " << amount << " to " << acc << std::endl;
	}
}

// Utility helper functions for Saving Account class
void display(const std::vector<Savings_Account> &accounts)
{
	std::cout << "\n=== Saving Accounts ============" << std::endl;
	for (const auto &acc : accounts)
		std::cout << acc << std::endl;
}

void deposit(std::vector<Savings_Account> &accounts, double amount)
{
	std::cout << "\n=== Depositing to Saving Accounts ============" << std::endl;
	for (auto &acc : accounts)
	{
		if (acc.deposit(amount))
			std::cout << "Deposited " << amount << " to " << acc << std::endl;
		else
			std::cout << "Failed to deposit of " << amount << " to " << acc << std::endl;
	}
}

void withdraw(std::vector<Savings_Account> &accounts, double amount)
{
	std::cout << "\n=== Withdrawing to Saving Accounts ============" << std::endl;
	for (auto &acc : accounts)
	{
		if (acc.withdraw(amount))
			std::cout << "Withdrew " << amount << " to " << acc << std::endl;
		else
			std::cout << "Failed to withdraw of " << amount << " to " << acc << std::endl;
	}
}

// Utility helper functions for Checkings_Account
void display(const std::vector<Checkings_Account> &accounts)
{
	std::cout << "\n=== Checkings Accounts ============" << std::endl;
	for (const auto &acc : accounts)
		std::cout << acc << std::endl;
}

void deposit(std::vector <Checkings_Account> &accounts, double amount)
{
	std::cout << "\n=== Depositing to Checkings Accounts ============" << std::endl;
	for (auto &acc : accounts)
	{
		if (acc.deposit(amount))
			std::cout << "Deposited " << amount << " to " << acc << std::endl;
		else
			std::cout << "Failed to deposit of " << amount << " to " << acc << std::endl;
	}
}

void withdraw(std::vector <Checkings_Account>  &accounts, double amount) 
{
	std::cout << "\n=== Withdrawing to Checkings Accounts ============" << std::endl;
	for (auto &acc : accounts)
	{
		if (acc.withdraw(amount))
			std::cout << "Withdrew " << amount << " to " << acc << std::endl;
		else
			std::cout << "Failed to withdraw of " << amount << " to " << acc << std::endl;
	}
}

// Utility helper functions for Trust_Account
void display(const std::vector<Trust_Account> &accounts)
{
	std::cout << "\n=== Trust Accounts ============" << std::endl;
	for (const auto &acc : accounts)
		std::cout << acc << std::endl;
}

void deposit(std::vector <Trust_Account> &accounts, double amount)
{
	std::cout << "\n=== Depositing to Trust Accounts ============" << std::endl;
	for (auto &acc : accounts)
	{
		if (acc.deposit(amount))
			std::cout << "Deposited " << amount << " to " << acc << std::endl;
		else
			std::cout << "Failed to deposit of " << amount << " to " << acc << std::endl;
	}
}

void withdraw(std::vector <Trust_Account>  &accounts, double amount)
{
	std::cout << "\n=== Withdrawing to Trust Accounts ============" << std::endl;
	for (auto &acc : accounts)
	{
		if (acc.withdraw(amount))
			std::cout << "Withdrew " << amount << " to " << acc << std::endl;
		else
			std::cout << "Failed to withdraw of " << amount << " to " << acc << std::endl;
	}
}