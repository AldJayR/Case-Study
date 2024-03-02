#include <iostream>
#include "order_system.h"

using namespace std;

const int maxOrders = 100;
string orderCart[maxOrders];
int orderIndex = 0;
int price[maxOrders];
const string itemNames[10] = {"Fries", "Coke", "Chicken with Rice", "Ice Cream", "Menudo", "Burger", "Pizza", "Salad", "Spaghetti", "Sushi"};
int itemPrices[10] = {40, 25, 70, 25, 50, 60, 100, 45, 80, 120};
int quantityAmount[maxOrders];
int priceSum = 0;

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

void orderSystem()
{
   char prompt;
   cout << "\nWelcome to Ardee's Canteen. Press 'Y' to get started. ";
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

    cout << "\n----------------------------CART-------------------------" << '\n';


    for (int i = 0; i < orderIndex; i++) {

        cout << quantityAmount[i] << "x " << orderCart[i] << " - " << "P" << price[i] << '\n';
        priceSum += price[i];
    }

    cout << "\nTotal Price is: P" << priceSum << '\n';
}
void updateItem()
{
    cout << "Enter Item Number: ";
    int itemNumber;
    cin >> itemNumber;

    for (int i = 0; i < orderIndex; i++) {
        cout << "+ or - ";
        char quantityUpdate;
        cin >> quantityUpdate;

        if (quantityUpdate == '+') {
            cout << "Enter amount you want to add: ";
            int amountUpdate;
            cin >> amountUpdate;
            price[i] += itemPrices[i] * amountUpdate;
            quantityAmount[i] += amountUpdate;
        }
    }
}
void checkout()
{
    cout << "\nPayment: ";
    int money;
    cin >> money;

    if (money < priceSum) {
        cout << "You do not have enough cash!";
    }
}
