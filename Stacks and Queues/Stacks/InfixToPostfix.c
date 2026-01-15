#include <stdio.h>
#include <ctype.h>

char stack[50];
int top = -1;

void push(char op) {
    stack[++top] = op;
}

char pop() {
    return stack[top--];
}

int priority(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    char exp[50], op;

    printf("Enter infix expression: ");
    scanf("%s", exp);

    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (isalnum(ch))
            printf("%c", ch);

        else if (ch == '(')
            push(ch);

        else if (ch == ')') {
            while ((op = pop()) != '(')
                printf("%c", op);
        }

        else {
            while (top != -1 &&
                  (priority(stack[top]) > priority(ch) ||
                  (priority(stack[top]) == priority(ch) && ch != '^')))
                printf("%c", pop());

            push(ch);
        }
    }

    while (top != -1)
        printf("%c", pop());

    return 0;
}
