#include <bits/stdc++.h>
using namespace std;

class PaymentGateway
{
public:
    virtual void initiatePayment(double amount) = 0;
};

class StripePayment : public PaymentGateway
{
public:
    void initiatePayment(double amount) override
    {
        cout << "Processing Stripe Payment : " << amount << endl;
    }
};

class RazorpayPayment : public PaymentGateway
{
public:
    void initiatePayment(double amount) override
    {
        cout << "Processing Razorpay Payment : " << amount << endl;
    }
};

class CheckoutService
{
    PaymentGateway *paymentGateway;

public:
    CheckoutService(PaymentGateway *gateway)
    {
        paymentGateway = gateway;
    }

    void checkout(double amount)
    {
        paymentGateway->initiatePayment(amount);
    }
};

int main()
{
    StripePayment stripe;
    CheckoutService Service1(&stripe);
    Service1.checkout(1000);

    RazorpayPayment razorpay;
    CheckoutService Service2(&razorpay);
    Service1.checkout(2000);
    return 0;
}