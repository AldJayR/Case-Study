#include "order_system.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
  // Initialize variables for money and total price sum
    int money = 0;
    int priceSum = 0;

  // Print the menu of order items
    printOrderItems();

  // Prompt the user to start ordering
    string welcomeMeeting =
      "\nWelcome to Ardee's Canteen. Press 'Y' to get started. ";
    string orderingAgain = "\nPress 'Y' to continue: ";

orderSystem(welcomeMeeting);

  // Check and display the items in the cart
checkCart(&priceSum);

  // Prompt the user if they want to checkout
cout << "\nWould you like to checkout? (Y/N) ";
char decision;
cin >> decision;

// Proceed to checkout or modify existing orders based on user input
    if (toupper(decision) != 'N')
    {
    checkout(&money, &priceSum);
    printReceipt();
    return 0;
  } else {
    // Prompt the user if they want to modify existing orders
    char orderPrompt;
    cout << "Do you want to modify your existing orders? (Y/N) ";
    cin >> orderPrompt;

    // Allow the user to modify orders until they are satisfied
    while (toupper(orderPrompt) != 'N') {
      // Display options to delete, update, or order again
      cout << "\n(1) Delete Item"
           << "\n(2) Update Item"
           << "\n(3) Order Again" << '\n';
      int option;
      cin >> option;

      // Process user's choice
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

      checkCart(&priceSum);

      // Prompt the user again if they want to modify orders
      cout << "Do you want to modify your existing orders? (Y/N) ";
      cin >> orderPrompt;

      // If the user doesn't want to modify orders, proceed to checkout
      if (toupper(orderPrompt) != 'Y') {
        if (askCheckout()) {
          checkout(&money, &priceSum);
          printReceipt();
        }
      }
      // If the user wants to modify orders, continue the loop
      else {
        checkCart(&priceSum);
        continue;
      }
    }
  }

  return 0;
}
