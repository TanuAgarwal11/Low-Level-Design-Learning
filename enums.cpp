#include <bits/stdc++.h>
using namespace std;

enum class orderStatus
{
    PLACED,
    CONFIRMED,
    SHIPPED,
    DELIVERED,
    CANCELLED
};
enum class paymentMethod
{
    CASH,
    UPI,
    CARD
};
class Order
{
private:
    int orderId;
    double amount;
    orderStatus status;
    paymentMethod payment;

public:
    Order(int id, double amt, paymentMethod pay)
    {
        orderId = id;
        amount = amt;
        status = orderStatus::PLACED;
        payment = pay;
    }

    void nextStatus()
    {
        if (status == orderStatus::PLACED)
        {
            status = orderStatus::CONFIRMED;
        }
        else if (status == orderStatus::CONFIRMED)
        {
            status = orderStatus::SHIPPED;
        }
        else if (status == orderStatus::SHIPPED)
        {
            status = orderStatus::DELIVERED;
        }
        else
        {
            cout << "Cannot move forward." << endl;
        }
    }

    void cancelOrder()
    {
        if (status == orderStatus::PLACED || status == orderStatus::CONFIRMED)
        {
            status = orderStatus::CANCELLED;
        }
        else
        {
            cout << "Cannot cancel after shipping." << endl;
        }
    }

    string getStatus()
    {
        switch (status)
        {
        case orderStatus::PLACED:
            return "PLACED";
        case orderStatus::CONFIRMED:
            return "CONFIRMED";
        case orderStatus::SHIPPED:
            return "SHIPPED";
        case orderStatus::DELIVERED:
            return "DELIVERED";
        case orderStatus::CANCELLED:
            return "CANCELLED";
        }
        return "";
    }

    string getPayment()
    {
        switch (payment)
        {
        case paymentMethod::CASH:
            return "CASH";
        case paymentMethod::CARD:
            return "CARD";
        case paymentMethod::UPI:
            return "UPI";
        }
        return "";
    }

    void display()
    {
        cout << "Order ID: " << orderId << endl;
        cout << "Amount: $" << amount << endl;
        cout << "Payment: " << getPayment() << endl;
        cout << "Status: " << getStatus() << endl;
        cout << "----------------------\n";
    }
};

int main()
{
    Order o1(101, 1000, paymentMethod::CASH);
    o1.display();
    o1.nextStatus();
    o1.nextStatus();
    o1.display();
    o1.cancelOrder();
    o1.nextStatus();
    o1.display();
    return 0;
}