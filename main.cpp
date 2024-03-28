#include <iostream>
#include "order_system.h"

using namespace std;

int main()
{
    int money = 0;
    int priceSum = 0;

    printOrderItems();
    string welcomeMeeting = "\nWelcome to Ardee's Canteen. Press 'Y' to get started. ";
    string orderingAgain = "\nPress 'Y' to continue: ";
    orderSystem(welcomeMeeting);
    checkCart(&priceSum);

    cout << "\nWould you like to checkout? ";
    char checkoutPrompt;
    cin >> checkoutPrompt;

    if (checkoutPrompt != 'N' && checkoutPrompt != 'n')
        checkout(&money, &priceSum);
    else
    {
        char orderPrompt;
        cout << "Do you want to modify your existing orders? (Y/N) ";
        cin >> orderPrompt;

        while (orderPrompt != 'N' && orderPrompt != 'n')
        {
            cout << "\n(1) Delete Item"
                 << "\n(2) Update Item"
                 << "\n(3) Order Again" << '\n';
            int option;
            cin >> option;

            switch (option)
            {
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

            if (orderPrompt != 'Y' && orderPrompt != 'y')
            {
                checkCart(&priceSum);
                if (askCheckout())
                {
                    checkout(&money, &priceSum);
                    printReceipt();
                }
            }
             else
            {
                checkCart(&priceSum);
                continue;
            }
        }
    }



    return 0;
}
