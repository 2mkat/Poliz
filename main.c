#include "stack.c"
#include <string.h>
#include <stdio.h>

#define ERR_OK 0
#define ERR_TOO_FEW_AGS 1

int bb_errno = ERR_OK;

int check_mistake(stack head){
    if(len(head.ll) < 2){
        printf("Usage: Ammount of operand: %d\nerror: too few arguments to function. Try again", len(head.ll));
        return ERR_TOO_FEW_AGS;
    }

}

int  parse(stack head, int pos, char sym){
    int num2 = 0, current;
    if(pos == 0) {
        current = 0;
    }
     else{
         current = stack_pop(head);
     }
     if(sym >= '0' && sym <= '9'){
        stack_push(head, current * 10 + sym - 48);
     }
     else {
         switch (sym) {
             case '\n':
                 pos = -1;
                 stack_push(head, current);
                 break;
             case ' ':
                 break;
             case '+':
                 check_mistake(head);
                 stack_push(head, stack_pop(head) + stack_pop(head));
                 break;
             case '-':
                 check_mistake(head);
                 num2 = stack_pop(head);
                 stack_push(head, stack_pop(head) - num2);
                 break;
             case '*':
                 check_mistake(head);
                 stack_push(head, stack_pop(head) * stack_pop(head));
                 break;
             case '/':
                 check_mistake(head);
                 num2 = stack_pop(head);
                 if (num2 == 0)
                     printf("error: zero divisor\n");
                 stack_push(head, stack_pop(head) / num2);
                 break;
             case '=':
                 printf("\nResult = %d\n", stack_pop(head));
                 exit;
                 break;
             default:
                 fprintf(stderr, "\nI can't read this symbol. Write new symbol\n");     // the program doт't end
                 return 0;
         }
     }
    return pos;
};

int main(){
    stack head = stack_new();

     int pos = 0;
     char ch = fgetc(stdin);

     while(ch != EOF) {
         pos = parse(head, pos, ch);
         //int x = len(head.ll);
         ch = fgetc(stdin);
         pos++;
     }

    return 0;
}
