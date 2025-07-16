#include <iostream>
#include <ctime>
#include<string>
using namespace std;
class ATM {
private:
    string accHolder = "milap thakkar";
    string address = "ahemadabad";
    string branch = "isckon cross road";
    int accNumber = 5678;
    int pin = 12345;
    int balance = 20000;
    int initial = 60000;

public:
    ATM() {
        cout << "\n<----------WELCOME TO ATM---------->\n";
        displayDateTime();
    }

    void displayDateTime() {
        time_t now = time(0);
        char* dt = ctime(&now);
        cout << "Current Date and Time: " << dt << endl;
    }

    void mainMenu() {
        int choice;
        cout << "\nEnter 1 to Access Account via PIN\n";
        cout << "Enter 0 to Get Help\n";
        cout << "Choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                accessAccount();
                break;
            case 0:
                help();
                break;
            default:
                cout << "Invalid Choice.\n";
        }
    }

    void accessAccount() {
        int enteredPin;
        cout << "\nEnter Your Acc Pin Access Number [Only one attempt is allowed]: ";
        cin >> enteredPin;

        if (enteredPin == pin) {
            menuScreen();
        } else {
            cout << "\nTHANK YOU!!\nYou had made your attempt which failed!!! No more attempts allowed!! Sorry!!\n";
        }
    }

    void help() {
        cout << "\nATM ACCOUNT STATUS\n";
        cout << "You must have the correct pin number to access this account.\n";
        cout << "See your bank representative for assistance.\n";
    }

    void menuScreen() {
        int option;
        do {
            cout << "\nATM MAIN MENU SCREEN\n";
            cout << "1. Deposit Cash\n2. Withdraw Cash\n3. Balance Inquiry\n0. Exit\n";
            cout << "Please Enter a Selection: ";
            cin >> option;

            switch(option) {
                case 1:
                    depositCash();
                    break;
                case 2:
                    withdrawCash();
                    break;
                case 3:
                    checkBalance();
                    break;
                case 0:
                    cout << "Thank you for using ATM.\n";
                    break;
                default:
                    cout << "Invalid Option\n";
            }
        } while(option != 0);
    }

    void depositCash() {
        int amount;
        cout << "\nATM ACCOUNT DEPOSIT SYSTEM\n";
        displayAccountInfo();
        cout << "Present available balance: Rs. " << balance << endl;
        cout << "Enter the Amount to be Deposited: Rs. ";
        cin >> amount;
        balance += amount;
        cout << "New available balance: Rs. " << balance << "\nThank You!\n";
    }

    void withdrawCash() {
        int amount;
        cout << "\nATM ACCOUNT WITHDRAWAL\n";
        displayAccountInfo();
        cout << "Enter amount to withdraw: Rs. ";
        cin >> amount;
        if (amount > balance) {
            cout << "Insufficient Available Balance in your account.\nSorry!!\n";
        } else {
            balance -= amount;
            cout << "Collect your cash. Remaining balance: Rs. " << balance << endl;
        }
    }

    void checkBalance() {
        cout << "\nYour Current Balance is: Rs. " << balance << endl;
    }

    void displayAccountInfo() {
        cout << "Name: " << accHolder << "\nAddress: " << address
             << "\nBranch: " << branch << "\nAccount No: " << accNumber << endl;
    }
};

int main() {
    ATM atm;
    atm.mainMenu();
    return 0;
}