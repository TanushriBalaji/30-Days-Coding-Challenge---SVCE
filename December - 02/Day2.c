#include <stdio.h>
#include <string.h>

void toBinary(int n, char bin[]) {
    int i = 0;
    char temp[20];

    while (n > 0) {
        temp[i++] = (n % 2) + '0';
        n /= 2;
    }

    temp[i] = '\0';

    // Reverse the string
    int len = strlen(temp);
    for (int j = 0; j < len; j++)
        bin[j] = temp[len - j - 1];

    bin[len] = '\0';
}

int main() {
    int N;
    scanf("%d", &N);

    char bin[20], maxBin[20];
    toBinary(N, maxBin);
    int width = strlen(maxBin) + 1;

    for (int i = 1; i <= N; i++) {
        toBinary(i, bin);

        printf("%*d %*o %*X %*s\n",
               width, i,
               width, i,
               width, i,
               width, bin);
    }

    return 0;
}
