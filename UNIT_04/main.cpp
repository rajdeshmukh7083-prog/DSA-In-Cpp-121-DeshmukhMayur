#include <iostream>
#include <string>
using namespace std;

struct BankAccount {
    int accountNo;
    string holderName;
    float balance;
    BankAccount* next;
};

BankAccount* head = NULL;

// Add a new bank account
void addAccount() {
    BankAccount* newAccount = new BankAccount;

    cout << "Enter Account Number: ";
    cin >> newAccount->accountNo;

    // Check for duplicate account numbers
    BankAccount* temp = head;

    while (temp != NULL) {
        if (temp->accountNo == newAccount->accountNo) {
            cout << "Account number already exists!\n";
            delete newAccount;
            return;
        }
        temp = temp->next;
    }

    cout << "Enter Account Holder Name: ";
    getline(cin >> ws, newAccount->holderName);

    cout << "Enter Account Balance: ";
    cin >> newAccount->balance;

    newAccount->next = NULL;

    if (head == NULL) {
        head = newAccount;
    } else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newAccount;
    }

    cout << "Bank Account Added Successfully!\n";
}

// Display all bank accounts
void displayAccounts() {
    if (head == NULL) {
        cout << "No Bank Accounts Available.\n";
        return;
    }

    BankAccount* temp = head;

    cout << "\n--- Bank Account Details ---\n";

    while (temp != NULL) {
        cout << "Account Number: "
             << temp->accountNo << endl;

        cout << "Holder Name: "
             << temp->holderName << endl;

        cout << "Balance: Rs. "
             << temp->balance << endl;

        cout << "---------------------------\n";

        temp = temp->next;
    }
}

// Search a bank account
void searchAccount() {
    if (head == NULL) {
        cout << "No Bank Accounts Available.\n";
        return;
    }

    int number;

    cout << "Enter Account Number to Search: ";
    cin >> number;

    BankAccount* temp = head;

    while (temp != NULL) {
        if (temp->accountNo == number) {
            cout << "\nBank Account Found!\n";

            cout << "Account Number: "
                 << temp->accountNo << endl;

            cout << "Holder Name: "
                 << temp->holderName << endl;

            cout << "Balance: Rs. "
                 << temp->balance << endl;

            return;
        }

        temp = temp->next;
    }

    cout << "Bank Account Not Found.\n";
}

// Main function
int main() {
    int choice;

    do {
        cout << "\n===== BANK ACCOUNT SEARCH SYSTEM =====\n";
        cout << "1. Add Bank Account\n";
        cout << "2. Display All Accounts\n";
        cout << "3. Search Bank Account\n";
        cout << "4. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addAccount();
                break;

            case 2:
                displayAccounts();
                break;

            case 3:
                searchAccount();
                break;

            case 4:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice! Try Again.\n";
        }

    } while (choice != 4);

    // Free allocated memory
    while (head != NULL) {
        BankAccount* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
