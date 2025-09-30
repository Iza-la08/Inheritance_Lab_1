#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <iostream>

class BankAccount {
private:
	char* accountHolderName;	// Account holder's name
	std::string accountNumber;		// Account number
	double balance;					// Current balance

public:
	BankAccount();
	BankAccount(const std::string& accNum, const std::string& name, double bal);
	BankAccount(const BankAccount& other); // Copy constructor
	BankAccount& operator=(const BankAccount& other); // Copy assignment operator
	
	virtual~BankAccount(); // Vertual destructor for polymorphism

	std::string getAccountHolderName() const;	// Getter for account holder name
	std::string getAccountNumber() const;	// Getter for account number
	double getBalance() const; // Getter for balance
	void setAccountHolderName(const std::string& newName);	// Setter for account holder name

	void deposit(double amount);

	virtual void withdraw(double amount);
	virtual void printAccount() const;

	BankAccount& operator+=(double amount); // Deposit money
	BankAccount& operator-=(double amount); // Withdraw money
	bool operator==(const BankAccount& other) const; // Equality operator
	bool operator<(const BankAccount& other) const; // Inequality operator
	bool operator>(const BankAccount& other) const; // Greater than operator

	static void printAccount(const BankAccount& account); // Static method to print account details

	static BankAccount createAccountFromInput(); // Static method to create a new account from user input
};

#endif // BANKACCOUNT_H