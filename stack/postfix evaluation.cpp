#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 100
typedef struct {
    int stack[MAX_SIZE];
    int top;
} Stack;
void push(Stack *s, int value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->stack[++s->top] = value;
}
int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->stack[s->top--];
}
int evaluatePostfix(char *expression) {
    Stack s;
    s.top = -1;
    int i, operand1, operand2, result;
    for (i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(&s, expression[i] - '0');
        } else {
            operand2 = pop(&s);
            operand1 = pop(&s);
            switch (expression[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
            push(&s, result);
        }
    }
    return pop(&s);
}
main() 
{
    char expression[MAX_SIZE];
    printf("Enter a postfix expression: ");
    scanf("%s", expression);
    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);
    return 0;
}
