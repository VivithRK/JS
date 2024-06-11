#include <stdio.h>

struct BIG_MALL {
    int item_no, quantity;
    float price;
    char item_name[20];
}s[100], t;

int main() {
    int i, j, n;
    float temp = 3.2f;

    printf("Enter the number of items to purchase (n): ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter the %d Item number: \n", i + 1);
        scanf("%d", &s[i].item_no);
        
        printf("Enter the Item name without spaces: ");
        scanf("%s", s[i].item_name);
        
        printf("Enter the quantity of items: ");
        scanf("%d", &s[i].quantity);
        
        printf("Enter the PRICE of item purchased: ");
        scanf("%f", &temp);
        s[i].price = temp;
    }

    printf("\n PURCHASE details are\n");
    printf("\nItem no\tItem Name\tQuantity\tPrice\n");
    for(i = 0; i < n; i++)
        printf("%d\t%s\t\t%d\t\t%.2f\n", s[i].item_no, s[i].item_name, s[i].quantity, s[i].price);

    // Bubble sort based on quantity
    for(i = 0; i < n; i++) {
        for(j = 0; j < n - 1; j++) {
            if(s[j].quantity > s[j + 1].quantity) {
                t = s[j];
                s[j] = s[j + 1];
                s[j + 1] = t;
            }
        }
    }

    printf("\n PURCHASE details after sorting by quantity are\n");
    printf("\nItem no\tItem Name\tQuantity\tPrice\n");
    for(i = 0; i < n; i++)
        printf("%d\t%s\t\t%d\t\t%.2f\n", s[i].item_no, s[i].item_name, s[i].quantity, s[i].price);

    return 0;
}
