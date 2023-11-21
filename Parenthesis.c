#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char exp[25];
    int len = 0;
    int top = -1;
    printf("Enter an expression: ");
    scanf("%s", exp);
    len = strlen(exp);
    char stack[len];

    for (int i = 0; i < len; i++) {
        if (exp[i] == '(') {
            stack[++top] = exp[i];
        } else if (exp[i] == ')') {
            if ((top == -1) || (exp[i] == ')' && stack[top] != '(')) {
                printf("Not Balanced\n");
                return 0; // exit the program when unbalanced
            } else {
                top--;
            }
        }
    }

    if (top == -1) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }

    return 0;
}
