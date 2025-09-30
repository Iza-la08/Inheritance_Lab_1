#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <limits>
#include "BankAccount.h"
using namespace std;	// Use the standard namespace

class CheckingAccount : public BankAccount {	// Derived class for checking accounts
	private:
		double transactionFee; // Overdraft limit for checking account

public: // 
	CheckingAccount(const std::string& accNum, const std::string& name, double bal, double fee)
			: BankAccount(accNum, name, bal), transactionFee(fee) {}

	void withdraw(double amount) override {
		BankAccount::withdraw(amount + transactionFee);
	}

	void printAccount() const override {
		BankAccount::printAccount();
		cout << "Transaction Fee: $" << transactionFee << "\n";
	}
};

class SavingsAccount : public BankAccount {	// Derived class for savings accounts
private:
	double interestRate; // Interest rate for savings account

public:
	SavingsAccount(const std::string& accNum, const std::string& name, double bal, double rate)
		: BankAccount(accNum, name, bal), interestRate(rate) {
	}

	void calculateInterest() {
		double interest = getBalance() * interestRate / 100;
		deposit(interest);
		cout << "Interest of $" << interest << " added to the account.\n";
	}

	void printAccount() const override {
		BankAccount::printAccount();
		cout << "Interest Rate: " << interestRate << "%\n";
	}
};

int getValidInt() {	// Function to get a valid integer input
	int value;
	while (true) {
		std::cin >> value;
		if (std::cin.fail()) {
			std::cin.clear(); // clear the error flag
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
			std::cout << "Invalid input. Please enter a valid number: ";
		}
		else {
			return value;
		}
	}
}

double getValidDouble() {	// Function to get a valid double input
	double value;
	while (true) {
		std::cin >> value;
		if (std::cin.fail()) {
			std::cin.clear(); // clear the error flag
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
			std::cout << "Invalid input. Please enter a valid amount: ";
		}
		else {
			return value;
		}
	}
}

void displayMenu() {	// Function to display the menu
	std::cout << "\nBank Account Management System\n";
	std::cout << "1. Create a new account\n";
	std::cout << "2. View account details\n";
	std::cout << "3. Deposit money\n";
	std::cout << "4. Withdraw money\n";
	std::cout << "5. Exit\n";
	std::cout << "\nChoose an option: ";
}

// Replace the displayAccountDetails function with this version to accept vector of unique_ptr<BankAccount>
void displayAccountDetails(const std::vector<std::unique_ptr<BankAccount>>& accounts) {
	if (accounts.empty()) {
		std::cout << "No accounts available.\n";
		return;
	}

	std::cout << "\nAccount Details:\n";
	int idx = 1;
	for (const auto& accountPtr : accounts) {
		std::cout << idx++ << ". ";
		if (accountPtr) {
			accountPtr->printAccount();
		}
		std::cout << "\n";
	}
}

// Main program
int main() {	
	std::vector<std::unique_ptr<BankAccount>> accounts;	// Vector to store bank accounts
	int choice;

	do {	// Main loop for menu
		displayMenu();	
		choice = getValidInt();


		switch (choice) {	// Handle menu choices
		case 1: {	// Create a new account
			std::string accNum, name;
			double initialDeposit;

			std::cout << "\nEnter account number: ";	// Get account details
			std::cin >> accNum;
			std::cin.ignore();
			std::cout << "Enter account holder name: ";
			std::getline(std::cin, name);
			std::cout << "Enter initial deposit amount: ";
			initialDeposit = getValidDouble();

			std::cout << "Select account type:\n1. Checking Account\n2. Savings Account\nEnter choice (1 or 2): ";
			int type = getValidInt();

			if (type == 1) {
				std::cout << "Enter transaction fee: ";
				double fee = getValidDouble();
				accounts.push_back(std::make_unique<CheckingAccount>(accNum, name, initialDeposit, fee));
			}
			else if (type == 2) {
				double rate = getValidDouble();
				std::cout << "Enter interest rate: ";
				rate = getValidDouble();
				accounts.push_back(std::make_unique<SavingsAccount>(accNum, name, initialDeposit, rate));
			}
			else {
				std::cout << "Invalid account type selected.\n";
			}
			break;
		}

		case 2: {	// View account details
			displayAccountDetails(accounts);	// Show account details
			break;
		}

		case 3: {	// Deposit money
			if (accounts.empty()) {	// Check if there are any accounts
				std::cout << "No account available. Please create an account first.\n";
				break;
			}
			displayAccountDetails(accounts);	// Show accounts to choose from
			std::cout << "Select account number to deposit into from (1-" << accounts.size() << "): ";
			int index = getValidInt() - 1;

			if (index < 0 || index >= static_cast<int>(accounts.size())) {	// Validate account selection
				std::cout << "Invalid account selection.\n";
				break;
			}
			std::cout << "Enter deposit amount: ";	// Get deposit amount
			double amount = getValidDouble();
			accounts[index]->deposit(amount);
			break;
		}

		case 4: {	// Withdraw money
			if (accounts.empty()) {	// Check if there are any accounts
				std::cout << "No account available. Please create an account first.\n";
				break;
			}
			displayAccountDetails(accounts);	// Show accounts to choose from
            std::cout << "Select account number to withdraw from (1-" << accounts.size() << "): ";
			int index = getValidInt() - 1;
			if (index < 0 || index >= static_cast<int>(accounts.size())) {	// Validate account selection
				std::cout << "Invalid account selection.\n";
				break;
			}
			std::cout << "Enter withdrawal amount: ";	// Get withdrawal amount
			double amount = getValidDouble();
			accounts[index]->withdraw(amount);
			break;
		}

		case 5: {	// Exit
			std::cout << "Exiting the program.\n";
			break;
		}

		default:	// Invalid choice
			std::cout << "Invalid choice. Please try again.\n";	}
		}
	while (choice != 5);	// Continue until user chooses to exit

	return 0;
}
