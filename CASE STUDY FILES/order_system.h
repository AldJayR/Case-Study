#ifndef ORDER_SYSTEM_H_INCLUDED
#define ORDER_SYSTEM_H_INCLUDED

using namespace std;

void printOrderItems();
void orderSystem(string welcomeMessage);
void checkDuplicate();
void checkCart();
int getItemPriceIndex(string itemName);
void updateItem();
void deleteItem();
bool askCheckout();
void orderAgain();
void checkout();
void printReceipt();

#endif // ORDER_SYSTEM_H_INCLUDED
