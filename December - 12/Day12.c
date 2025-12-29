#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int duplicate = -1, missing = -1;

    // find duplicate
    for (int i = 0; i < n; i++) {
        int idx = arr[i];
        if (arr[idx - 1] < 0)
            duplicate = idx;
        else
            arr[idx - 1] = -arr[idx - 1];
    }

    // find missing
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0)
            missing = i + 1;
    }

    printf("Missing Number: %d\n", missing);
    printf("Duplicate Number: %d\n", duplicate);

    return 0;
}
