# Inheritance_Lab

A C++ project demonstrating **inheritance, polymorphism, and object-oriented programming** by simulating a bank account management system.  
This project was developed as part of an Object-Oriented Programming (OOP) lab to practice classes, objects, encapsulation, and managing collections with `std::vector` and smart pointers.

---

## Overview

This system supports multiple types of bank accounts:

- **BankAccount** (base class) – common attributes like account number, account holder name, and balance.  
- **CheckingAccount** (derived class) – adds a transaction fee that is applied on withdrawals.  
- **SavingsAccount** (derived class) – adds an interest rate and a method to calculate interest.  

The project demonstrates **polymorphic behavior**, where a base class pointer can call overridden functions in derived classes, e.g., `withdraw()` and `printAccount()`.

---

## Bank Account Data Dictionary

| Attribute             | Data Type     | Description                              |
|-----------------------|---------------|------------------------------------------|
| `accountNumber`       | `std::string` | Unique identifier for the bank account.  |
| `accountHolderName`   | `std::string` | Name of the account holder.              |
| `balance`             | `double`      | Current balance of the account.          |
| `transactionFee`      | `double`      | Fee applied on withdrawals (CheckingAccount only). |
| `interestRate`        | `double`      | Interest rate applied to balance (SavingsAccount only). |

---

## Methods List

| Method Signature                                                 | Return Type   | Description                                   |
|------------------------------------------------------------------|---------------|-----------------------------------------------|
| `BankAccount()`                                                  | (Constructor) | Default constructor. Initializes empty data.  |
| `BankAccount(std::string accNum, std::string name, double bal)`  | (Constructor) | Parameterized constructor. Initializes data.  |
| `virtual ~BankAccount()`                                         | (Destructor)  | Virtual destructor to allow proper cleanup.   |
| `std::string getAccountNumber() const`                           | `std::string` | Returns the account number.                   |
| `std::string getAccountHolderName() const`                       | `std::string` | Returns the account holder’s name.            |
| `double getBalance() const`                                      | `double`      | Returns the current balance.                  |
| `void setAccountHolderName(const std::string& newName)`          | `void`        | Updates the account holder’s name.            |
| `void deposit(double amount)`                                    | `void`        | Deposits funds into the account.              |
| `virtual void withdraw(double amount)`                           | `void`        | Withdraws funds (can be overridden).          |
| `virtual void printAccount() const`                               | `void`        | Prints account details (overridden in derived classes). |
| `void calculateInterest()`                                        | `void`        | Adds interest to balance (SavingsAccount only). |

---

## Features

- Create multiple bank accounts of **different types** (Checking or Savings)
- Deposit and withdraw money with proper validation
- Apply **transaction fees** for checking accounts
- Calculate **interest** for savings accounts
- Demonstrates **polymorphism** using `std::vector<std::unique_ptr<BankAccount>>`
- Virtual destructor ensures proper cleanup of derived objects
- Input validation for robust user interaction

---

## Usage

1. Run the program.
2. Use the menu to:
   - Create a new account (Checking or Savings)
   - View account details
   - Deposit money
   - Withdraw money
   - Exit the program
3. Polymorphic behavior allows withdrawals and account printing through base class pointers.

---
