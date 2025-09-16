#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;	// Use the standard namespace

class BankAccount {	// Class to represent a bank account
private:	// Private member variables
	std::string accountHolderName;	// Account holder's name
	std::string accountNumber;		// Account number
	double balance;					// Current balance

public:	// Public member functions
	BankAccount() : accountHolderName(""), accountNumber(""), balance(0.0) {}

	BankAccount(std::string accNum, std::string name, double bal)
		: accountHolderName(name), accountNumber(accNum), balance(bal) {
	}

	std::string getAccountHolderName() const {	// Getter for account holder name
		return accountHolderName;
	}
	std::string getAccountNumber() const { return accountNumber; }	// Getter for account number
	double getBalance() const { return balance; }

	void setAccountHolderName(const std::string& newName) {	// Setter for account holder name
		accountHolderName = newName;
	}
	void  deposit(double amount) {	// Method to deposit money
		if (amount > 0) {	// Check for valid deposit
			balance += amount;
			std::cout << "Deposited: $" << amount << std::endl;
		}
		else {	// Check for negative deposit
			std::cout << "Deposit amount must be positive." << std::endl;
		}
	}

	void withdraw(double amount) {	// Method to withdraw money
		if (amount > 0 && amount <= balance) {	// Check for valid withdrawal
			balance -= amount;
			std::cout << "Withdrew: $" << amount << std::endl;
		}
		else if (amount > balance) {	// Check for insufficient funds
			std::cout << "Insufficient funds." << std::endl;
		}
		else {	// Check for negative withdrawal
			std::cout << "Withdrawal amount must be positive." << std::endl;
		}
	}
};

void displayMenu() {	// Function to display the menu
	std::cout << "\nBank Account Management System\n";	
	std::cout << "1. Create a new account\n";
	std::cout << "2. View account details\n";
	std::cout << "3. Deposit money\n";
	std::cout << "4. Withdraw money\n";
	std::cout << "5. Exit\n";
	std::cout << "Choose an option: ";
}

void displayAccountDetails(const std::vector<BankAccount>& accounts) {	// Function to display account details
	if (accounts.empty()) {	// Check if there are any accounts
		std::cout << "No accounts available.\n";
		return;
	}

	std::cout << "\nAccount Details:\n";	// Display details of all accounts
	for (const auto& accounts : accounts) {	// Range-based for loop
		std::cout << "Account Number: " << accounts.getAccountNumber() << "\n";
		std::cout << "Account Holder: " << accounts.getAccountHolderName() << "\n";
		std::cout << "Balance: $" << accounts.getBalance() << "\n\n";
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

			std::cout << "Enter account number: ";	// Get account details
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
