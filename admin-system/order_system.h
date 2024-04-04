#ifndef ORDER_SYSTEM_H_INCLUDED
#define ORDER_SYSTEM_H_INCLUDED

using namespace std;

void printOrderItems();
void orderSystem(string welcomeMessage, bool &admin);
void checkDuplicate();
void checkCart(int *priceSum);
int getItemPriceIndex(string itemName);
void updateItem();
void deleteItem();
bool askCheckout();
int dropOrders();
void checkout(int *money, int *priceSum);
void printReceipt();

#endif // ORDER_SYSTEM_H_INCLUDED
