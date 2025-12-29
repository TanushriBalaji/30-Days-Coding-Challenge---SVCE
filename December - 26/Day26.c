#include <stdio.h>

int M, N;
int grid[100][100];
int dp[100][100];

// Directions: up, down, left, right
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int x, int y) {
    // If already computed, return it
    if (dp[x][y] != 0)
        return dp[x][y];

    int maxLen = 1;  // at least the cell itself

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
            if (grid[nx][ny] > grid[x][y]) {
                int len = 1 + dfs(nx, ny);
                if (len > maxLen)
                    maxLen = len;
            }
        }
    }

    dp[x][y] = maxLen;
    return maxLen;
}

int main() {
    scanf("%d %d", &M, &N);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int answer = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int cur = dfs(i, j);
            if (cur > answer)
                answer = cur;
        }
    }

    printf("%d\n", answer);
    return 0;
}
