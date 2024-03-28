#include <iostream>
#include "order_system.h"

using namespace std;

// Initialize global variables

constexpr int g_maxOrders = 10;
string orderCart[g_maxOrders];
int g_orderIndex = 0;
int price[g_maxOrders];
const string itemNames[g_maxOrders] = {"Fries", "Coke", "Chicken with Rice", "Ice Cream", "Menudo", "Burger", "Pizza", "Salad", "Spaghetti", "Sushi"};
constexpr int itemPrices[g_maxOrders] = {40, 25, 70, 25, 50, 60, 100, 45, 80, 120};
int quantityAmount[g_maxOrders];


// Print out hardcoded GUI for Menu (will be dynamic soon)

void printOrderItems()
{
    cout << "+------------------------------------------------------------------------------------------+" << '\n';
    cout << "|                                                                                          |" << '\n';
    cout << "|                                   ORDERING SYSTEM                                        |" << '\n';
    cout << "|                                                                                          |" << '\n';
    cout << "+------------------------------------------------------------------------------------------+"  << '\n';
    cout << "|                                                                                          |" << '\n';
    cout << "|                                   PICK YOUR ORDER                                        |" << '\n';
    cout << "|                                                                                          |" << '\n';
    cout << "|  1. Fries - P40                                  6. Burger - P60                         |" << '\n';
    cout << "|                                                                                          |" << '\n';
    cout << "|  2. Coke - P25                                   7. Pizza - P100                         |" << '\n';
    cout << "|                                                                                          |" << '\n';
    cout << "|  3. Chicken with Rice - P70                      8. Salad - P45                          |" << '\n';
    cout << "|                                                                                          |" << '\n';
    cout << "|  4. Ice Cream - P25                              9. Spaghetti - P80                      |" << '\n';
    cout << "|                                                                                          |" << '\n';
    cout << "|  5. Menudo - P50                                 10. Sushi - P120                        |" << '\n';
    cout << "|                                                                                          |" << '\n';
    cout << "+------------------------------------------------------------------------------------------+" << '\n';
}

// Order prompt system

void orderSystem(string orderMessage)
{
    char prompt;
    cout << orderMessage;
    cin >> prompt;

    // Asks the user for their order

    while (prompt != 'N' && prompt != 'n')
    {
        cout << "\nWhat would you like to order? (1-10) ";
        int item {};
        cin >> item;
        int itemAmount {};

        // Error handling

        if (item < 1 || item > 10)
        {
            cout << "Invalid item number! Please select a valid item." << '\n';
            continue;
        }

        // Successful order

        cout << "You have ordered " << itemNames[item - 1] << '\n';

        // If customer ordered more than 10 items

        do
        {
            cout << "How much would you like? ";
            cin >> itemAmount;

            if (itemAmount > 10)
            {
                cout << "You cannot order more than ten items!" << '\n';
            }
        }
        while (itemAmount > 10);


        // error handling

        if (itemAmount <= 0)
        {
            cout << "Invalid amount! Please enter a positive integer." << '\n';
            continue;
        }

        cout << "You have ordered " << itemAmount << " " << itemNames[item - 1] << "(s)." << '\n';

        // Calculate price

        int totalPrice = itemPrices[item - 1] * itemAmount;


        // Create cart and updates as an order is made.

        quantityAmount[g_orderIndex] = itemAmount;
        orderCart[g_orderIndex] = itemNames[item - 1];
        price[g_orderIndex] = totalPrice;
        g_orderIndex++;

        cout << "Would you like to order more? ";
        cin >> prompt;


    }
}

// Checks for duplicate items and joins them

void checkDuplicate()
{

    for (int i = 0; i < g_orderIndex; i++)
    {
        if (i < g_orderIndex - 1 && orderCart[i + 1] == orderCart[i])
        {
            quantityAmount[i] += quantityAmount[i + 1];
            price[i] += price[i + 1];
            for (int j = i + 1; j < g_orderIndex - 1; j++)
            {
                orderCart[j] = orderCart[j + 1];
                quantityAmount[j] = quantityAmount[j + 1];
                price[j] = price[j + 1];
            }
            g_orderIndex--;
            i--;
        }
    }
}

void checkCart(int *priceSum)
{
    // call the check duplicate function to merge duplicate items

    checkDuplicate();

    // initialize total to 0

    *priceSum = 0;

    // use ASCII art to create GUI for CART

    cout << "\n----------------------------CART-------------------------" << '\n';

    for (int i = 0; i < g_orderIndex; i++)
    {
        if (quantityAmount[i] > 0)
        {
            cout << quantityAmount[i] << "x " << orderCart[i] << " - " << "P" << price[i] << '\n';
            *priceSum += price[i];
        }
    }

    cout << "\nTotal Price is: P" << *priceSum << '\n';
}

// Linear search algorithm to find the correct index for the price in the cart

int getItemPriceIndex(string itemName)
{
    for (int i = 0; i < g_maxOrders; ++i)
    {
        if (itemNames[i] == itemName)
            return i;
    }
    return 1;
}

// Update items

void updateItem()
{
    cout << "Enter Item Number: ";
    int itemNumber;
    cin >> itemNumber;

    if (itemNumber < 1 || itemNumber > g_orderIndex)
    {
        cout << "Invalid item number!" << '\n';
        return;
    }

    // Selecting an item

    cout << "You have selected " << orderCart[itemNumber - 1] << '\n';
    cout << "+ (Add Item) or - (Subtract Item): ";
    char quantityUpdate;
    cin >> quantityUpdate;

    int itemPriceIndex = getItemPriceIndex(orderCart[itemNumber - 1]);


   switch (quantityUpdate)
   {
    case '+':
        {
            cout << "Enter amount you want to add: ";
            int amountUpdate;
            cin >> amountUpdate;

            price[itemNumber - 1] += itemPrices[itemPriceIndex] * amountUpdate; // Item price in the array of the selected item is added to the current price
            quantityAmount[itemNumber - 1] += amountUpdate; // Quantity amount is updated

            if (quantityAmount[itemNumber - 1] > 10)
            {
                cout << "You cannot have more than ten items!" << '\n';
                return;
            }
            break;
        }
    case '-':
        {
            cout << "Enter amount you want to remove: ";
            int amountMinus;
            cin >> amountMinus;

            if (amountMinus > quantityAmount[itemNumber - 1])  // if amount is more than the current items in the cart
            {
                cout << "Cannot remove more items than what you have ordered!" << '\n';
                return;
            }

            price[itemNumber - 1] -= itemPrices[itemPriceIndex] * amountMinus;  // subtract the price
            quantityAmount[itemNumber - 1] -= amountMinus; // subtract the quantity amount

            // removes the item entirely if the amount is the same as the quantity amount in the cart

            if (amountMinus == quantityAmount[itemNumber - 1])
            {
                for (int i = itemNumber - 1; i < g_orderIndex - 1; ++i)
                {
                    orderCart[i] = orderCart[i + 1];
                    quantityAmount[i] = quantityAmount[i + 1];
                    price[i] = price[i + 1];
                }
                orderCart[g_orderIndex - 1] = "";
                quantityAmount[g_orderIndex - 1] = 0;
                price[g_orderIndex - 1] = 0;
                g_orderIndex--;

            }
            break;
        }
    default:
        cout << "Invalid option!" << '\n';
        return;
}


}

// delete item function

void deleteItem()
{
    cout << "Enter Item Number: ";
    int itemNumber;
    cin >> itemNumber;

    if (itemNumber < 1 || itemNumber > g_orderIndex)
    {
        cout << "Invalid item number!" << '\n';
        return;
    }

    cout << "You have selected " << orderCart[itemNumber - 1] << '\n';
    cout << "Are you sure you want to delete this item? ";
    char deleteCart;
    cin >> deleteCart;

    if (deleteCart != 'N' && deleteCart != 'n')
    {
        for (int i = itemNumber - 1; i < g_orderIndex - 1; ++i)
        {
            orderCart[i] = orderCart[i + 1];
            quantityAmount[i] = quantityAmount[i + 1];
            price[i] = price[i + 1];
        }
        orderCart[g_orderIndex - 1] = "";
        quantityAmount[g_orderIndex - 1] = 0;
        price[g_orderIndex - 1] = 0;
        g_orderIndex--;

        cout << "Order deleted successfully!" << '\n';
    }
    else
        cout << "Deletion canceled" << '\n';
}
bool askCheckout()
{
    cout << "\nWould you like to check out? ";
    char secondPrompt;
    cin >> secondPrompt;

    return (secondPrompt != 'N' && secondPrompt != 'n');

}

// checkout, uses pointers and references to reduce use of global variables

int dropOrders()
{
    cout << "\nOrders dropped!" << '\n';

    return 0;
}

void checkout(int *money, int *priceSum)
{
    cout << "\nPayment: ";
    cin >> *money;

    if (*money < *priceSum)
    {
        cout << "You do not have enough cash!"
             << "\nCancel order or provide enough cash? (Y/N) ";
                char continueOrder;
                cin >> continueOrder;
                if (continueOrder != 'N' && continueOrder != 'n')
                {
                    checkout(money, priceSum);
                }
                else
                {
                    dropOrders();
                }

    }
}
void printReceipt()
{
    cout << "\nTHIS IS WHERE THE RECEIPT WILL GO. TO BE HANDLED BY ARDEE, JUSTINE, HANS, JANNEL, RUSSEL" << '\n';

    // RECEIPT TO BE HANDLED BY OTHER MEMBERS
}
