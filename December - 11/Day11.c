#include <stdio.h>

int main() {
    int N;
    printf("Enter N: ");
    scanf("%d", &N);

    int count = 0;

    for (int i = 2; i < N; i++) {
        int isPrime = 1;

        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }

        if (isPrime)
            count++;
    }

    printf("The count of prime numbers less than %d is: %d\n", N, count);

    return 0;
}
