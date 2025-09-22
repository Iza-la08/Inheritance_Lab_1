#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <limits>
#include "BankAccount.h"

BankAccount::BankAccount()	// Constructor
	: accountHolderName(nullptr), accountNumber(""), balance(0.0) {
	accountHolderName = new char[1]; // Allocate memory for empty name
	accountHolderName[0] = '\0';
}

BankAccount::BankAccount(const std::string& accNum, const std::string& name, double bal)
	: accountHolderName(nullptr), accountNumber(accNum), balance(bal) {
	accountHolderName = new char[name.length() + 1]; // Allocate memory for name
	std::strcpy(accountHolderName, name.c_str());
}

BankAccount::BankAccount(const BankAccount& other)
	: accountHolderName(nullptr), accountNumber(other.accountNumber), balance(other.balance) {
	if (other.accountHolderName) {
		std::size_t len = std::strlen(other.accountHolderName);
		accountHolderName = new char[len + 1]; // Allocate memory for name
		std::strcpy(accountHolderName, other.accountHolderName);
	} else {
		accountHolderName = new char[1];
		accountHolderName[0] = '\0';
	}
}

BankAccount& BankAccount::operator=(const BankAccount& other) {
	if (this == &other) {
		return *this;  // Self-assignment check	
	}

	delete[] accountHolderName; // Free existing memory

	accountNumber = other.accountNumber;
	balance = other.balance;

	if (other.accountHolderName) {
		std::size_t len = std::strlen(other.accountHolderName);
		accountHolderName = new char[len + 1]; // Allocate memory for name
		std::strcpy(accountHolderName, other.accountHolderName);
	} else {
		accountHolderName = new char[1];
		accountHolderName[0] = '\0';
	}
	return *this;
}
BankAccount::~BankAccount() {
	delete[] accountHolderName; // Free allocated memory
}





//----------------------------------------------------------------
std::string BankAccount::getAccountHolderName() const {	// Getter for account holder name
	return std::string(accountHolderName);
}
std::string BankAccount::getAccountNumber() const { 
	return accountNumber; }	// Getter for account number
double BankAccount::getBalance() const { 
	return balance; }


void BankAccount::setAccountHolderName(const std::string& newName) {	// Setter for account holder name
	delete[] accountHolderName; // Free existing memory
	accountHolderName = new char[newName.length() + 1];
	std::strcpy(accountHolderName, newName.c_str());
}
void  BankAccount::deposit(double amount) {	// Method to deposit money
	if (amount > 0.0) {
		balance += amount;
		std::cout << "\nDeposited: $" << amount << std::endl;
	}
	else {	// Check for negative deposit
		std::cout << "Deposit amount must be positive. \n" << std::endl;
	}
}



void BankAccount::withdraw(double amount) {	// Method to withdraw money
	if (amount <= 0.0) {	// Check for valid withdrawal
		
		std::cout << "Withdrawal amount must be positive." << std::endl;
	}
	else if (amount > balance) {	// Check for insufficient funds
		std::cout << "Insufficient funds." << std::endl;
	}
	else {	// Check for negative withdrawal
		balance -= amount;
		std::cout << "\nWithdrew: $-" << amount << std::endl;		
	}
}

BankAccount& BankAccount::operator+=(double amount) {	// Deposit money
	if (amount > 0.0) {
		balance += amount;
	}
	else {	// Check for negative deposit
		std::cout << "Deposit amount must be positive." << std::endl;
	}
	return *this;
}

BankAccount& BankAccount::operator-=(double amount) {	// Withdraw money
	if (amount > 0.0 && amount <= balance) {
		balance -= amount;
	}
	else if (amount > balance) {	// Check for insufficient funds
		std::cout << "Insufficient funds." << std::endl;
	}
	else {	// Check for negative withdrawal
		std::cout << "Withdrawal amount must be positive." << std::endl;
	}
	return *this;
}

bool BankAccount::operator==(const BankAccount& other) const {	// Equality operator
	return accountNumber == other.accountNumber;
}

bool BankAccount::operator<(const BankAccount& other) const {	// Less than operator
	return balance < other.balance;
}

bool BankAccount::operator>(const BankAccount& other) const {	// Greater than operator
	return balance > other.balance;
}

// ----------------Static method to print account details--------------------------
void BankAccount::printAccount(const BankAccount& account) {	
	std::cout << "Account Number: " << account.accountNumber << "\n";
	std::cout << "Account Holder: " << account.accountHolderName << "\n";
	std::cout << "Balance: $" << account.balance << "\n";
}

BankAccount BankAccount::createAccountFromInput() {
	std::string accNum, name;
	double initialDeposit = 0.0;

	std::cout << "Enter account number: ";	// Get account details
	std::cin >> accNum;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

	while (true) {	// Get account holder name
		std::cout << "Enter account holder name: ";
		std::cin >> initialDeposit;
		if (!std::cin.fail()) break;
		std::cin.clear(); // clear the error flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
		std::cout << "Invalid input. Please enter a valid name: ";
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

	return BankAccount(accNum, name, initialDeposit);	// Create and return new account
}

