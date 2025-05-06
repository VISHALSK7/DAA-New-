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
