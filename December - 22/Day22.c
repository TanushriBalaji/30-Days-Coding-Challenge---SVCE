#include <stdio.h>

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int adj[1000][1000] = {0};

    // Read edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int water[1000];
    for (int i = 0; i < V; i++) {
        scanf("%d", &water[i]);
    }

    int queue[1000];
    int front = 0, rear = 0;

    int time[1000];
    for (int i = 0; i < V; i++) {
        time[i] = -1;
    }

    // Push all initially filled reservoirs
    for (int i = 0; i < V; i++) {
        if (water[i] == 1) {
            queue[rear++] = i;
            time[i] = 0;
        }
    }

    // BFS
    while (front < rear) {
        int curr = queue[front++];

        for (int i = 0; i < V; i++) {
            if (adj[curr][i] == 1 && time[i] == -1) {
                time[i] = time[curr] + 1;
                queue[rear++] = i;
            }
        }
    }

    int maxTime = 0;

    // Check if all reservoirs are filled
    for (int i = 0; i < V; i++) {
        if (time[i] == -1) {
            printf("-1\n");
            return 0;
        }
        if (time[i] > maxTime) {
            maxTime = time[i];
        }
    }

    printf("%d\n", maxTime);
    return 0;
}

