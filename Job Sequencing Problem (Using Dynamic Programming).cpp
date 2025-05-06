#include <stdio.h>
#include <stdlib.h>

struct Job { int id, deadline, profit; };

int compare(const void* a, const void* b) {
    return ((struct Job*)b)->profit - ((struct Job*)a)->profit;
}

int main() {
    struct Job jobs[] = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};
    int n = 5, maxSlot = 3;
    int slot[3] = {0}, totalProfit = 0;

    qsort(jobs, n, sizeof(struct Job), compare);

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (!slot[j]) {
                slot[j] = 1;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Maximum Profit: %d\n", totalProfit);
    return 0;
}

