#include <iostream>
#include "order_system.h"

using namespace std;

int main() {
    printOrderItems();
    orderSystem();
    checkCart();

    char secondPrompt;
    cout << "\nWould you like to check out? ";
    cin >> secondPrompt;

    if (secondPrompt != 'N' && secondPrompt != 'n')
        checkout();
    else {
        char orderPrompt;
        cout << "Do you want to modify your existing orders? (Y/N)";
        cin >> orderPrompt;

        while (orderPrompt != 'N' && orderPrompt != 'n') {
            cout << "\n(1) Delete Item"
                 << "\n(2) Update Item" << '\n';
            int option;
            cin >> option;

            if (option == 2)
                updateItem();

            cout << "Do you want to modify your existing orders? (Y/N) ";
            cin >> orderPrompt;

            if (orderPrompt != 'Y' && orderPrompt != 'Y')
                checkCart();
        }
    }

    return 0;
}
