#include <iostream>

using namespace std;

const int maxOrders = 100;
string orderCart[maxOrders];
int orderIndex = 0;
int price[maxOrders];
const string itemNames[10] = {"Fries", "Coke", "Chicken with Rice", "Ice Cream", "Menudo", "Burger", "Pizza", "Salad", "Spaghetti", "Sushi"};
int itemPrices[10] = {40, 25, 70, 25, 50, 60, 100, 45, 80, 120};

void printOrderItems()
{
    cout << "--------------------------------------------------------------------------------------------" << '\n';
    cout << "|                                                                                          |" << '\n';
    cout << "|                                   ORDERING SYSTEM                                        |" << '\n';
    cout << "|                                                                                          |" << '\n';
    cout << " ------------------------------------------------------------------------------------------" << '\n';
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
   cout << "\nWelcome to Amiel's Canteen. Press 'Y' to get started. ";
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

        orderCart[orderIndex] = itemNames[item - 1];
        price[orderIndex] = totalPrice;
        orderIndex++;

        cout << "Would you like to order more? ";
        cin >> prompt;


   }
}

void checkCart() {

    int sum = 0;

    cout << "\n----------------------------CART-------------------------" << '\n';
    for (int i = 0; i < orderIndex; i++) {
        cout << orderCart[i] << " - " << "P" << price[i] << '\n';
        sum += price[i];
    }

    cout << "\nTotal Price is: " << sum << '\n';
}


int main()
{
    printOrderItems();
    orderSystem();
    checkCart();

    return 0;
}
