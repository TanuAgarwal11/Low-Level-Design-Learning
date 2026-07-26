#include <bits/stdc++.h>
using namespace std;

class BankAccount
{
private:
    string ownerName;
    int accountNumber;
    double balance = 0;

public:
    BankAccount(string name, int accNum)
    {
        ownerName = name;
        accountNumber = accNum;
    }

    void depositMoney(double amount)
    {
        if (amount > 0)
        {

            balance += amount;
        }
        else
        {
            cout << "Invalid amount." << endl;
            return;
        }
    }

    void withdrawlMoney(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
        }
        else
        {
            cout << "Not enough balance." << endl;
            return;
        }
    }

    void getBalance()
    {
        cout << "Current Account Balance is : " << balance << endl;
    }

    void displayDetails()
    {
        cout << "Account holder name : " << ownerName << endl;
        cout << "Account Number : " << accountNumber << endl;
    }
};

int main()
{
    BankAccount acc("Alixe", 101);
    acc.displayDetails();
    acc.depositMoney(10000);
    acc.getBalance();
    acc.withdrawlMoney(4000);
    acc.getBalance();
    return 0;
}
