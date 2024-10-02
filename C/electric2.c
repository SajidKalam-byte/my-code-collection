#include <stdio.h>

void main() {
    int unit;
    float price = 0.0;

    printf("Enter the total UNIT: ");
    scanf("%d", &unit);

    switch (unit) {
        case 1 ... 99:
            price = unit * 4.50;
            break;

        case 100 ... 299:
            price = 99 * 4.50 + (unit - 99) * 5.80;
            break;

        case 300 ... 499:
            price = 99 * 4.50 + 199 * 5.80 + (unit - 299) * 6.70;
            break;

        case 500 ... 699:
            price = 99 * 4.50 + 199 * 5.80 + 199 * 6.70 + (unit - 499) * 8.75;
            break;

        case 700 ... 99999:
            price = 99 * 4.50 + 199 * 5.80 + 199 * 6.70 + 199 * 8.75 + (unit - 699) * 10.60;
            break;

        default:
            printf("Invalid input!\n");
            return;
    }

    printf("Price: %.2f\n", price);
}
