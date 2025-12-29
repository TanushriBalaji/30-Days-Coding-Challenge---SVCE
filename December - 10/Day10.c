#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int i = 0, j = n - 1;

    while (i <= j) {
        if (i == j) {
            printf("%d ", arr[i]);   // middle element (odd n)
        } else {
            printf("%d %d ", arr[i], arr[j]);
        }
        i++;
        j--;
    }

    return 0;
}
