#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);   // number of operations

    char ops[1000][10];
    for (int i = 0; i < n; i++) {
        scanf("%s", ops[i]);
    }

    int stack[1000];
    int top = -1;

    for (int i = 0; i < n; i++) {
        if (strcmp(ops[i], "C") == 0) {
            top--;   // remove last score
        }
        else if (strcmp(ops[i], "D") == 0) {
            stack[++top] = 2 * stack[top];
        }
        else if (strcmp(ops[i], "+") == 0) {
            stack[++top] = stack[top] + stack[top - 1];
        }
        else {
            stack[++top] = atoi(ops[i]); // convert string to integer
        }
    }

    int sum = 0;
    for (int i = 0; i <= top; i++) {
        sum += stack[i];
    }

    printf("%d\n", sum);
    return 0;
}
