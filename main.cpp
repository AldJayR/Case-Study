#include <iostream>
#include "order_system.h"

using namespace std;

int main()
{
    // Initialize variables for money and total price sum
    int money = 0;
    int priceSum = 0;

    // Print the menu of order items
    printOrderItems();

    // Prompt the user to start ordering
    string welcomeMeeting = "\nWelcome to Ardee's Canteen. Press 'Y' to get started. ";
    string orderingAgain = "\nPress 'Y' to continue: ";
    orderSystem(welcomeMeeting);

    // Check and display the items in the cart
    checkCart(&priceSum);

    // Prompt the user if they want to checkout
    cout << "\nWould you like to checkout? ";
    char checkoutPrompt;
    cin >> checkoutPrompt;

    // Proceed to checkout or modify existing orders based on user input
    if (checkoutPrompt != 'N' && checkoutPrompt != 'n')
    {
        checkout(&money, &priceSum);
        printReceipt();
    }
    else
    {
        // Prompt the user if they want to modify existing orders
        char orderPrompt;
        cout << "Do you want to modify your existing orders? (Y/N) ";
        cin >> orderPrompt;

        // Allow the user to modify orders until they are satisfied
        while (orderPrompt != 'N' && orderPrompt != 'n')
        {
            // Display options to delete, update, or order again
            cout << "\n(1) Delete Item"
                 << "\n(2) Update Item"
                 << "\n(3) Order Again" << '\n';
            int option;
            cin >> option;

            // Process user's choice
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

            // Prompt the user again if they want to modify orders
            cout << "Do you want to modify your existing orders? (Y/N) ";
            cin >> orderPrompt;

            // If the user doesn't want to modify orders, proceed to checkout
            if (orderPrompt != 'Y' && orderPrompt != 'y')
            {
                // Display the updated cart and proceed to checkout
                checkCart(&priceSum);
                if (askCheckout())
                {
                    checkout(&money, &priceSum);
                    printReceipt();
                }
            }
            // If the user wants to modify orders, continue the loop
            else
            {
                checkCart(&priceSum);
                continue;
            }
        }
    }

    return 0;
}
