#include <bits/stdc++.h>
using namespace std;

enum class OrderStatus
{
    PLACED,
    CONFIRMED,
    SHIPPED,
    DELIVERED,
    CANCELLED
};

enum class PaymentMethod
{
    CASH,
    CARD,
    UPI
};

class Order
{
private:
    int orderId;
    double amount;
    OrderStatus status;
    PaymentMethod payment;

public:
    Order(int id, double amt, PaymentMethod pay)
    {
        orderId = id;
        amount = amt;
        payment = pay;
        status = OrderStatus::PLACED;
    }

    void nextStatus()
    {
        if (status == OrderStatus::PLACED)
        {
            status = OrderStatus::CONFIRMED;
        }
        else if (status == OrderStatus::CONFIRMED)
        {
            status = OrderStatus::SHIPPED;
        }
        else if (status == OrderStatus::SHIPPED)
        {
            status = OrderStatus::DELIVERED;
        }
        else
        {
            cout << "Cannot move forward." << endl;
        }
    }

    void cancleOrder()
    {
        if (status == OrderStatus::PLACED || status == OrderStatus::CONFIRMED)
        {
            status = OrderStatus::CANCELLED;
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
        case OrderStatus::PLACED:
            return "PLACED";
        case OrderStatus::CONFIRMED:
            return "CONFIRMED";
        case OrderStatus::SHIPPED:
            return "SHIPPED";
        case OrderStatus::DELIVERED:
            return "DELIVERED";
        case OrderStatus::CANCELLED:
            return "CANCELLED";
        }
        return "";
    }

    string getPayment()
    {
        switch (payment)
        {
        case PaymentMethod::CASH:
            return "CASH";
        case PaymentMethod::CARD:
            return "CARD";
        case PaymentMethod::UPI:
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
    Order o1(101, 1000, PaymentMethod::CASH);
    o1.display();
    o1.nextStatus();
    o1.nextStatus();
    o1.display();
    o1.cancleOrder();
    o1.nextStatus();
    o1.display();
    return 0;
}