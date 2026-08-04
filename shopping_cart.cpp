#include <bits/stdc++.h>
using namespace std;

class ShoppingCart
{
private:
    map<string, double> items;
    bool discountApplied = false;
    bool isCheckedOut = false;

public:
    void addItem(string name, double price)
    {
        if (!isCheckedOut)
        {
            items[name] = price;
        }
        else
        {
            cout << "Item cannot be added now" << endl;
        }
    }

    bool applyDiscount(string code)
    {
        if (code == "SAVE10" && !discountApplied && !isCheckedOut)
        {
            discountApplied = true;
            return true;
        }

        return false;
    }

    double getTotal()
    {
        double totalAmount = 0;

        for (auto &it : items)
        {
            totalAmount += it.second;
        }

        if (discountApplied)
        {
            totalAmount *= 0.90;
        }

        return totalAmount;
    }

    void checkOut()
    {
        if (!isCheckedOut && !items.empty())
        {
            isCheckedOut = true;
        }
    }
};

int main()
{
    ShoppingCart cart;

    cart.addItem("Laptop", 999.99);
    cart.addItem("Mouse", 29.99);

    cout << "Total: $" << cart.getTotal() << endl;

    cout << "Discount: "<< cart.applyDiscount("SAVE10") << endl;

    cout << "Total: $" << cart.getTotal() << endl;

    cout << "Discount: "<< cart.applyDiscount("SAVE10") << endl;

    cart.checkOut();

    cart.addItem("Keyboard", 79.99);

    cout << "Total: $" << cart.getTotal() << endl;

    return 0;
}