#include <stdio.h>

int main() {
    int N;
    int beads[100];
    int i, isPalindrome = 1;

    // Input number of beads
    scanf("%d", &N);

    // If necklace is empty
    if (N == 0) {
        printf("The necklace is empty.");
        return 0;
    }

    // Input bead values
    for (i = 0; i < N; i++) {
        scanf("%d", &beads[i]);
    }

    // Check palindrome
    for (i = 0; i < N / 2; i++) {
        if (beads[i] != beads[N - i - 1]) {
            isPalindrome = 0;
            break;
        }
    }

    // Output result
    if (isPalindrome) {
        printf("The necklace is mirrored.");
    } else {
        printf("The necklace is not mirrored.");
    }

    return 0;
}
