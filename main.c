#include "stack.c"
#include <string.h>
#include <stdio.h>

int  parse(stack* head, int sym){
    int num2 = 0;
    int x = 0;

    switch(sym){
        case ' ':
            break;
        case '=':
            printf("\nResult = %d", stack_pop(head, 0));
            exit ;
        case '+':
            printf("kaka1\n");
            stack_push(head,0, stack_pop(head,0) + stack_pop(head, 0));
            break;
        case '-':
            stack_push(head,0, -stack_pop(head,0) + stack_pop(head, 0));
            break;
        case '*':
            stack_push(head,0, stack_pop(head,0) * stack_pop(head, 0));
            break;
        case '/':
                num2 = stack_pop(head, 0);
                if (num2 == 0)
                    printf("error: zero divisor\n");
                stack_push(head, 0, stack_pop(head, 0) / stack_pop(head, 0));
                break;
        default:
                if (scanf("%d", &x) != 1) {
                    return 1;
                }
                else {
                    stack_push(head, 0, x);
                }
                break;
    }
    return 0;
};

int main() {
    stack* head = calloc(1, sizeof(stack));
    while(!feof(stdin)){
        int sym = getchar();
        parse(head, sym);
    }
    return 0;
}
