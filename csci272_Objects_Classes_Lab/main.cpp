#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "BankAccount.h"
using namespace std;	// Use the standard namespace

void displayMenu() {	// Function to display the menu
	std::cout << "\nBank Account Management System\n";
	std::cout << "1. Create a new account\n";
	std::cout << "2. View account details\n";
	std::cout << "3. Deposit money\n";
	std::cout << "4. Withdraw money\n";
	std::cout << "5. Exit\n";
	std::cout << "\nChoose an option: ";
}

void displayAccountDetails(const std::vector<BankAccount>& accounts) {	// Function to display account details
	if (accounts.empty()) {	// Check if there are any accounts
		std::cout << "No accounts available.\n";
		return;
	}

	std::cout << "\nAccount Details:\n";	// Display details of all accounts
	for (const auto& account : accounts) {
		std::cout << "Account Number: " << account.getAccountNumber() << "\n";
		std::cout << "Account Holder: " << account.getAccountHolderName() << "\n";
		std::cout << "Balance: $" << account.getBalance() << "\n\n";
	}
}

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

int main() {	// Main function
	std::vector<BankAccount> accounts;	// Vector to store bank accounts
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

			accounts.push_back(BankAccount(accNum, name, initialDeposit));	// Create and add new account
			std::cout << "Account created successfully!\n";
			break;
		}

		case 2: {	// View account details
			displayAccountDetails(accounts);
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
			accounts[index].deposit(amount);
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
			accounts[index].withdraw(amount);
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
