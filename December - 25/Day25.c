#include <stdio.h>

int main() {
    int M, N;
    scanf("%d %d", &M, &N);

    char grid[50][50];
    for (int i = 0; i < M; i++) {
        scanf("%s", grid[i]);
    }

    int sx, sy;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }

    // visited[row][col][keys]
    int visited[50][50][1024] = {0};

    int qx[100000], qy[100000], qk[100000], qs[100000];
    int front = 0, rear = 0;

    // start BFS
    qx[rear] = sx;
    qy[rear] = sy;
    qk[rear] = 0;      // no keys
    qs[rear] = 0;      // steps
    rear++;

    visited[sx][sy][0] = 1;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (front < rear) {
        int x = qx[front];
        int y = qy[front];
        int keys = qk[front];
        int steps = qs[front];
        front++;

        if (grid[x][y] == 'T') {
            printf("%d\n", steps);
            return 0;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            int newKeys = keys;

            if (nx < 0 || ny < 0 || nx >= M || ny >= N)
                continue;

            char cell = grid[nx][ny];

            if (cell == '#')
                continue;

            // If key
            if (cell >= 'a' && cell <= 'j') {
                newKeys = keys | (1 << (cell - 'a'));
            }

            // If door
            if (cell >= 'A' && cell <= 'J') {
                if (!(keys & (1 << (cell - 'A'))))
                    continue;
            }

            if (!visited[nx][ny][newKeys]) {
                visited[nx][ny][newKeys] = 1;
                qx[rear] = nx;
                qy[rear] = ny;
                qk[rear] = newKeys;
                qs[rear] = steps + 1;
                rear++;
            }
        }
    }

    printf("-1\n");
    return 0;
}
