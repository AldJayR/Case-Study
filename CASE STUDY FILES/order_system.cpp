#include <iostream>
#include "order_system.h"

using namespace std;

const int maxOrders = 100;
string orderCart[maxOrders];
int orderIndex = 0;
int price[maxOrders];
const string itemNames[10] = {"Fries", "Coke", "Chicken with Rice", "Ice Cream", "Menudo", "Burger", "Pizza", "Salad", "Spaghetti", "Sushi"};
const int itemPrices[10] = {40, 25, 70, 25, 50, 60, 100, 45, 80, 120};
int quantityAmount[maxOrders];
int priceSum;
int money;

void printOrderItems()
{
    cout << "--------------------------------------------------------------------------------------------" << '\n';
    cout << "|                                                                                          |" << '\n';
    cout << "|                                   ORDERING SYSTEM                                        |" << '\n';
    cout << "|                                                                                          |" << '\n';
    cout << " ------------------------------------------------------------------------------------------"  << '\n';
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
    cout << "-------------------------------------------------------------------------------------------" << '\n';
}

void orderSystem(string orderMessage)
{
    char prompt;
    cout << orderMessage;
    cin >> prompt;

    while (prompt != 'N' && prompt != 'n') {
        cout << "\nWhat would you like to order? ";
        int item{};
        cin >> item;
        int itemAmount{};

        if (item < 1 || item > 10) {
            cout << "Invalid item number! Please select a valid item." << '\n';
            continue;
        }
        cout << "You have ordered " << itemNames[item - 1] << '\n';
        cout << "How much would you like? ";
        cin >> itemAmount;
        if (itemAmount <= 0) {
            cout << "Invalid amount! Please enter a positive integer." << '\n';
            continue;
        }
        cout << "You have ordered " << itemAmount << " " << itemNames[item - 1] << "(s)." << '\n';

        int totalPrice = itemPrices[item - 1] * itemAmount;


        quantityAmount[orderIndex] = itemAmount;
        orderCart[orderIndex] = itemNames[item - 1];
        price[orderIndex] = totalPrice;
        orderIndex++;

        cout << "Would you like to order more? ";
        cin >> prompt;


    }
}

void checkDuplicate()
{

    for (int i = 0; i < orderIndex; i++) {
        if (i < orderIndex - 1 && orderCart[i + 1] == orderCart[i]) {
            quantityAmount[i] += quantityAmount[i + 1];
            price[i] += price[i + 1];
            for (int j = i + 1; j < orderIndex - 1; j++) {
                orderCart[j] = orderCart[j + 1];
                quantityAmount[j] = quantityAmount[j + 1];
                price[j] = price[j + 1];
            }
            orderIndex--;
            i--;
        }
    }
}

void checkCart()
{
    checkDuplicate();

    priceSum = 0;

    cout << "\n----------------------------CART-------------------------" << '\n';

    for (int i = 0; i < orderIndex; i++) {
        if (quantityAmount[i] > 0) {
            cout << quantityAmount[i] << "x " << orderCart[i] << " - " << "P" << price[i] << '\n';
            priceSum += price[i];
        }
    }

    cout << "\nTotal Price is: P" << priceSum << '\n';
}

int getItemPriceIndex(string itemName) {
    for (int i = 0; i < 10; ++i) {
        if (itemNames[i] == itemName) {
            return i;
        }
    }
    return -1;
}
void updateItem()
{
    cout << "Enter Item Number: ";
    int itemNumber;
    cin >> itemNumber;

    if (itemNumber < 1 || itemNumber > orderIndex) {
        cout << "Invalid item number!" << '\n';
        return;
    }

    cout << "You have selected " << orderCart[itemNumber - 1] << '\n';
    cout << "+ (Add Item) or - (Subtract Item): ";
    char quantityUpdate;
    cin >> quantityUpdate;

    int itemPriceIndex = getItemPriceIndex(orderCart[itemNumber - 1]);

   switch (quantityUpdate) {
    case '+':
        {
            cout << "Enter amount you want to add: ";
            int amountUpdate;
            cin >> amountUpdate;
            price[itemNumber - 1] += itemPrices[itemPriceIndex] * amountUpdate;
            quantityAmount[itemNumber - 1] += amountUpdate;
            break;
        }
    case '-':
        {
            cout << "Enter amount you want to remove: ";
            int amountMinus;
            cin >> amountMinus;

            if (amountMinus > quantityAmount[itemNumber - 1]) {
                cout << "Cannot remove more items than what you have ordered!" << '\n';
                return;
            }

            price[itemNumber - 1] -= itemPrices[itemPriceIndex] * amountMinus;
            quantityAmount[itemNumber - 1] -= amountMinus;

            if (amountMinus == quantityAmount[itemNumber - 1]) {
                orderCart[itemNumber - 1] = "";
                quantityAmount[itemNumber - 1] = 0;
                price[itemNumber - 1] = 0;
                orderIndex--;
            }
            break;
        }
    default:
        cout << "Invalid option!" << '\n';
        return;
}


}
void deleteItem() {
    cout << "Enter Item Number: ";
    int itemNumber;
    cin >> itemNumber;

    if (itemNumber < 1 || itemNumber > orderIndex) {
        cout << "Invalid item number!" << '\n';
        return;
    }

    cout << "You have selected " << orderCart[itemNumber - 1] << '\n';
    cout << "Are you sure you want to delete this item? ";
    char deleteCart;
    cin >> deleteCart;

    if (deleteCart != 'N' && deleteCart != 'n') {
        for (int i = itemNumber - 1; i < orderIndex - 1; ++i) {
            orderCart[i] = orderCart[i + 1];
            quantityAmount[i] = quantityAmount[i + 1];
            price[i] = price[i + 1];
        }
        orderCart[orderIndex - 1] = "";
        quantityAmount[orderIndex - 1] = 0;
        price[orderIndex - 1] = 0;
        orderIndex--;

        cout << "Order deleted successfully!" << '\n';
    } else {
        cout << "Deletion canceled" << '\n';
    }
}
bool askCheckout() {
    cout << "\nWould you like to check out? ";
    char secondPrompt;
    cin >> secondPrompt;

    return (secondPrompt != 'N' && secondPrompt != 'n');

}

void checkout()
{
    cout << "\nPayment: ";
    cin >> money;

    if (money < priceSum) {
        cout << "You do not have enough cash!";
    }
}
void printReceipt() {
    cout << "\nTHIS IS WHERE THE RECEIPT WILL GO. TO BE HANDLED BY ARDEE, JUSTINE, HANS, JANNEL, RUSSEL" << '\n';
}
