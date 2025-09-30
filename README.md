# Inheritance_Lab

## Overview
This project is a **Bank Account Management System** implemented in C++ that demonstrates the use of **inheritance and polymorphism**. The system supports multiple types of bank accounts, including **CheckingAccount** and **SavingsAccount**, each with unique features such as transaction fees and interest rates.

---

## Features
- Create multiple bank accounts (Checking or Savings)
- Deposit and withdraw money
- Apply transaction fees for checking accounts
- Calculate interest for savings accounts
- Polymorphic behavior: base class pointers can call overridden functions
- Input validation for robust user interaction

---

## Classes

### `BankAccount` (Base Class)
- Stores common account information: account number, account holder name, and balance
- Provides virtual functions:
  - `printAccount()`
  - `withdraw()`
- Includes a **virtual destructor** for proper memory management

### `CheckingAccount` (Derived Class)
- Inherits from `BankAccount`
- Adds `transactionFee` attribute
- Overrides `withdraw()` to include the transaction fee
- Overrides `printAccount()` to display transaction fee

### `SavingsAccount` (Derived Class)
- Inherits from `BankAccount`
- Adds `interestRate` attribute
- `calculateInterest()` adds interest to the account balance
- Overrides `printAccount()` to display interest rate

---

## Getting Started

### Prerequisites
- C++ compiler supporting C++11 or later
- CMake or Visual Studio (optional, for project setup)

### Build Instructions
1. Clone the repository:
    ```bash
    git clone https://github.com/your-username/Inheritance_Lab.git
    cd Inheritance_Lab
    ```
2. Compile the project using your preferred IDE or CMake.
3. Run the executable.

---

## Usage
1. Run the program
2. Use the menu to:
   - Create a new account (Checking or Savings)
   - View account details
   - Deposit money
   - Withdraw money
   - Exit the program

---

## Example

