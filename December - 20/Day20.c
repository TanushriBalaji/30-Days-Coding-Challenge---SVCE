#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int heights[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &heights[i]);
    }

    int result[N];

    for (int i = 0; i < N; i++) {
        result[i] = -1;   // default

        for (int j = i + 1; j < N; j++) {
            if (heights[j] > heights[i]) {
                result[i] = heights[j];
                break;    // first taller tower found
            }
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
