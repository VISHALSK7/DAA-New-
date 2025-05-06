#1
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

#2TSP
#include <stdio.h>
#include <limits.h>

int visited[4] = {0}, minCost = INT_MAX;

void tsp(int graph[4][4], int pos, int count, int cost, int start) {
    if (count == 4 && graph[pos][start]) {
        if (minCost > cost + graph[pos][start])
            minCost = cost + graph[pos][start];
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (!visited[i] && graph[pos][i]) {
            visited[i] = 1;
            tsp(graph, i, count + 1, cost + graph[pos][i], start);
            visited[i] = 0;
        }
    }
}

int main() {
    int graph[4][4] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    visited[0] = 1;
    tsp(graph, 0, 1, 0, 0);
    printf("Minimum cost: %d\n", minCost);
    return 0;
}

#3Job Assign
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

#4Job Sequen
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
