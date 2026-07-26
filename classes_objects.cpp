#include <bits/stdc++.h>
using namespace std;

class FoodOrder
{
public:
    string orderId, customerName;
    vector<string> items;
    vector<int> quentity;
    vector<int> prices;
    string deliveryAddress;
    string paymentMethod;
    string status = "Pending";
    double totalAmount = 0;
    bool isPlaced = false;

    FoodOrder(string id, string name)
    {
        orderId = id;
        customerName = name;
    }

    void setDetails(string address, string payment)
    {
        deliveryAddress = address;
        paymentMethod = payment;
    }
    void addItems(string item, double price, int qty)
    {
        if (isPlaced)
        {
            cout << "order already placed. Cannot add items." << endl;
            return;
        }

        items.push_back(item);
        quentity.push_back(qty);
        prices.push_back(price);
        totalAmount += price * qty;
    }

    void placeOrder()
    {
        if (items.size() == 0)
        {
            cout << "No items to place" << endl;
            return;
        }
        isPlaced = true;
    }

    void updateStatus(string newStatus)
    {
        status = newStatus;
    }
    void display()
    {
        cout << "Order : " << orderId << " | Name : " << customerName << endl;
        cout << "status : " << (isPlaced ? "Placed" : "Pending") << endl;
        for (int i = 0; i < items.size(); i++)
        {
            cout << "- " << items[i] << " x " << quentity[i] << " = " << " $" << prices[i] << endl;
        }
        cout << "Delivery Address : " << deliveryAddress << endl;
        cout << "Payment method : " << paymentMethod << endl;
        cout << "Status : " << status << endl;
        cout << "TotalAmount to pay : $" << totalAmount << endl;
    }
};

int main()
{
    FoodOrder o1("ORD1", "ALICE");
    o1.addItems("Ramen", 50, 2);
    o1.addItems("soju", 78, 2);
    o1.placeOrder();
    o1.setDetails("seol flat 24", "Ipay");
    o1.updateStatus("OUT FOR DELIVERY");
    o1.updateStatus("DELIVERED");
    o1.display();
    return 0;
}