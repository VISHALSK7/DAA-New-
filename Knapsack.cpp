#include <stdio.h>
#include <stdlib.h>  // Include this for qsort

struct Item { int weight, value; };

int compare(const void* a, const void* b) {
    double r1 = (double)((struct Item*)a)->value / ((struct Item*)a)->weight;
    double r2 = (double)((struct Item*)b)->value / ((struct Item*)b)->weight;
    return (r2 > r1) ? 1 : (r2 < r1) ? -1 : 0;
}

int main() {
    struct Item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int n = 3, capacity = 50;
    qsort(items, n, sizeof(struct Item), compare);

    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            break;
        }
    }
    printf("Max value: %.1f\n", totalValue);
    return 0;
}

