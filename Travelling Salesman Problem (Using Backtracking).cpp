#include <stdio.h>
#include <limits.h>

int n = 3, assigned[3] = {0}, minCost = INT_MAX;

void assign(int cost[3][3], int person, int total) {
    if (person == n) {
        if (total < minCost)
            minCost = total;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!assigned[i]) {
            assigned[i] = 1;
            assign(cost, person + 1, total + cost[person][i]);
            assigned[i] = 0;
        }
    }
}

int main() {
    int cost[3][3] = {
        {9, 2, 7},
        {6, 4, 3},
        {5, 8, 1}
    };
    assign(cost, 0, 0);
    printf("Minimum Cost: %d\n", minCost);
    return 0;
}


