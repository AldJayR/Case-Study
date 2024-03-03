#include <iostream>
#include "order_system.h"

using namespace std;

int main()
{
    printOrderItems();
    string welcomeMeeting = "\nWelcome to Ardee's Canteen. Press 'Y' to get started. ";
    string orderingAgain = "\nPress 'Y' to continue: ";
    orderSystem(welcomeMeeting);
    checkCart();

    cout << "\nWould you like to checkout? ";
    char checkoutPrompt;
    cin >> checkoutPrompt;

    if (checkoutPrompt != 'N' && checkoutPrompt != 'n')
        checkout();
    else {
        char orderPrompt;
        cout << "Do you want to modify your existing orders? (Y/N) ";
        cin >> orderPrompt;

        while (orderPrompt != 'N' && orderPrompt != 'n') {
            cout << "\n(1) Delete Item"
                 << "\n(2) Update Item"
                 << "\n(3) Order Again" << '\n';
            int option;
            cin >> option;

            switch (option) {
                case 1:
                    deleteItem();
                    break;
                case 2:
                    updateItem();
                    break;
                case 3:
                    orderSystem(orderingAgain);
                    break;
                default:
                    cout << "Invalid option! Select again";
                    continue;
            }

            cout << "Do you want to modify your existing orders? (Y/N) ";
            cin >> orderPrompt;

            if (orderPrompt != 'Y' && orderPrompt != 'y') {
                checkCart();
                if (askCheckout()) {
                    checkout();
                }
            } else {
                checkCart();
            }
        }
    }

    printReceipt();

    return 0;
}
