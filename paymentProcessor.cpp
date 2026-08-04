#include <bits/stdc++.h>
using namespace std;

class PaymentProcessor
{
private:
    string cardNumber;
    double amount;

    string maskedCardNumber(string cardNumber)
    {
        return "****-****-****-" + cardNumber.substr(cardNumber.length() - 4);
    }

public:
    PaymentProcessor(string number, double amt)
    {
        cardNumber = maskedCardNumber(number);
        amount = amt;
    }

    void payPayment()
    {
        cout << "Processing payment of $" << amount << " for the Card " << cardNumber << endl;
    }
};

int main()
{
    PaymentProcessor payment("1234567812345678", 250.00);
    payment.payPayment();
    return 0;
}