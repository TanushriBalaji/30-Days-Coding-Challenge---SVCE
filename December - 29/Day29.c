
#include <stdio.h>
#define INF 1000000000

int main() {
    int V, E;
    scanf("%d", &V);
    scanf("%d", &E);

    int dist[505][505];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = (i == j) ? 0 : INF;

    int u, v, w;
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        if (w < dist[u][v]) {
            dist[u][v] = w;
            dist[v][u] = w;
        }
    }

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    int ans = INF;
    for (int i = 0; i < V; i++)
        for (int j = i + 1; j < V; j++)
            if (dist[i][j] != INF)
                ans = (ans < dist[i][j] * 2) ? ans : dist[i][j] * 2;

    if (ans == INF) printf("-1\n");
    else printf("%d\n", ans);
    return 0;
}
