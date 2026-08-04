#include <bits/stdc++.h>
using namespace std;

class BankAccount
{
    string accountHolder;
    double balance = 1000;

public:
    BankAccount(string name)
    {
        accountHolder = name;
    }

    void deposit(double amount)
    {
        balance += amount;
    }

    bool withdraw(double amount)
    {
        if (balance < amount)
        {
            return false;
        }

        balance -= amount;
        return true;
    }

    void displayDetails()
    {
        cout << "Account Holder name : " << accountHolder << endl;
    }

    double getBalance()
    {
        return balance;
    }
};

int main()
{
    BankAccount a1("Sia");
    a1.displayDetails();
    cout << a1.getBalance() << endl;
    a1.deposit(2000);
    cout << a1.getBalance() << endl;
    if (a1.withdraw(4000))
    {
        cout << "Withdrawal successful" << endl;
    }
    else
    {
        cout << "Insufficient balance" << endl;
    }
    cout << a1.getBalance() << endl;
    return 0;
}