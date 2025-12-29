#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);      // number of stones

    int stones[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &stones[i]);   // stone values
    }

    int farthest = 0;
    int canReach = 1;

    for (int i = 0; i < n; i++) {
        if (i > farthest) {
            canReach = 0;
            break;
        }

        if (i + stones[i] > farthest)
            farthest = i + stones[i];
    }

    if (canReach)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
