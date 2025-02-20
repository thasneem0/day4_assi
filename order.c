#include <stdio.h>

struct order {
    int orderID;
    char customerName[200];
    char product[100];
    int amount;
};
typedef struct order o;

void readOrders(o orders[], int n);
void displayOrders(o orders[], int n);
void searchOrder(o orders[], int n, int orderID);
void saveToFile(o orders[], int n);

int main() {
    int num;
    printf("Enter number of orders: ");
    scanf("%d", &num);

    o orders[1000];

    readOrders(orders, num);
    displayOrders(orders, num);
    saveToFile(orders, num);

    int orderID;
    printf("\nEnter Order ID to search: ");
    scanf("%d", &orderID);
    searchOrder(orders, num, orderID);

    return 0;
}

void readOrders(o orders[], int n) {
    printf("Enter order details (Order ID, Customer Name, Product, Amount):\n");
    for (int i = 0; i < n; i++) {
        printf("Order %d: ", i + 1);
        scanf("%d %s %s %d", &orders[i].orderID, orders[i].customerName, orders[i].product, &orders[i].amount);
    }
}

void displayOrders(o orders[], int n) {
    printf("\nOrder Records:\n");
    for (int i = 0; i < n; i++) {
        printf("Order ID: %d, Customer: %s, Product: %s, Amount: ₹%d\n",
               orders[i].orderID, orders[i].customerName, orders[i].product, orders[i].amount);
    }
}

void searchOrder(o orders[], int n, int orderID) {
    for (int i = 0; i < n; i++) {
        if (orders[i].orderID == orderID) {
            printf("Order Found: %s - %s - ₹%d\n",
                   orders[i].customerName, orders[i].product, orders[i].amount);
            return;
        }
    }
    printf("Order with ID %d not found.\n", orderID);
}

void saveToFile(o orders[], int n) {
    FILE *file = fopen("orders.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d, %s, %s, ₹%d\n",
                orders[i].orderID, orders[i].customerName, orders[i].product, orders[i].amount);
    }
    fclose(file);
    printf("Record saved in \"orders.txt\"\n");
}

