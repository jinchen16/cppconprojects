#pragma once
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checkings_Account.h"
#include "Trust_Account.h"

// Utility helper functions for Account class
void display(const std::vector<Account> &accounts);
void deposit(std::vector <Account> &accounts, double amount);
void withdraw(std::vector <Account>  &accounts, double amount);

// Utility helper functions for Saving Account class
void display(const std::vector<Savings_Account> &accounts);
void deposit(std::vector <Savings_Account> &accounts, double amount);
void withdraw(std::vector <Savings_Account>  &accounts, double amount);

// Utility helper functions for Checkings_Account
void display(const std::vector<Checkings_Account> &accounts);
void deposit(std::vector <Checkings_Account> &accounts, double amount);
void withdraw(std::vector <Checkings_Account>  &accounts, double amount);

// Utility helper functions for Trust_Account
void display(const std::vector<Trust_Account> &accounts);
void deposit(std::vector <Trust_Account> &accounts, double amount);
void withdraw(std::vector <Trust_Account>  &accounts, double amount);