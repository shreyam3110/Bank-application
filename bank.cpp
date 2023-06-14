#include <iostream>
#include <vector>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    BankAccount(string accNumber, string accHolder, double initialBalance) {
        accountNumber = accNumber;
        accountHolder = accHolder;
        balance = initialBalance;
    }

    string getAccountNumber() {
        return accountNumber;
    }

    string getAccountHolder() {
        return accountHolder;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid amount for deposit." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0) {
            if (balance >= amount) {
                balance -= amount;
                cout << "Withdrawal successful. New balance: " << balance << endl;
            } else {
                cout << "Insufficient funds." << endl;
            }
        } else {
            cout << "Invalid amount for withdrawal." << endl;
        }
    }
};

class Bank {
private:
    vector<BankAccount> accounts;

public:
    void createAccount(string accNumber, string accHolder, double initialBalance) {
        BankAccount newAccount(accNumber, accHolder, initialBalance);
        accounts.push_back(newAccount);
        cout << "Account created successfully." << endl;
    }

    BankAccount* findAccount(string accNumber) {
        for (int i = 0; i < accounts.size(); i++) {
            if (accounts[i].getAccountNumber() == accNumber) {
                return &accounts[i];
            }
        }
        return nullptr;
    }
};

int main() {
    Bank bank;

    while (true) {
        cout << "1. Create Account\n2. Deposit\n3. Withdraw\n4. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string accNumber, accHolder;
                double initialBalance;
                cout << "Enter account number: ";
                cin >> accNumber;
                cout << "Enter account holder name: ";
                cin >> accHolder;
                cout << "Enter initial balance: ";
                cin >> initialBalance;
                bank.createAccount(accNumber, accHolder, initialBalance);
                break;
            }
            case 2: {
                string accNumber;
                double amount;
                cout << "Enter account number: ";
                cin >> accNumber;
                BankAccount* account = bank.findAccount(accNumber);
                if (account != nullptr) {
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    account->deposit(amount);
                } else {
                    cout << "Account not found." << endl;
                }
                break;
            }
            case 3: {
                string accNumber;
                double amount;
                cout << "Enter account number: ";
                cin >> accNumber;
                BankAccount* account = bank.findAccount(accNumber);
                if (account != nullptr) {
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    account->withdraw(amount);
                } else {
                    cout << "Account not found." << endl;
                }
                break;
            }
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}