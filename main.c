#include "stack.c"
#include <string.h>
#include <stdio.h>

int  parse(stack head, int pos, char sym){
    int num2 = 0, current;
    if(pos == 0) {
        current = 0;
    }
     else{
         //puts("Before pop");
         current = stack_pop(head);
         //puts("After pop");
     }
     if(sym >= '0' && sym <= '9'){
        stack_push(head, current * 10 + sym - 48);
     }
      switch(sym) {
          case '\n':
              pos = 0;
              break;
          case ' ':
              break;
          case '+':
              stack_push(head, stack_pop(head) + stack_pop(head));
              break;
          case '-':
              stack_push(head, -stack_pop(head) + stack_pop(head));
              break;
          case '*':
              stack_push(head,stack_pop(head) * stack_pop(head));
              break;
          case '/':
              num2 = stack_pop(head);
              if (num2 == 0)
                  printf("error: zero divisor\n");
              stack_push(head, stack_pop(head) / stack_pop(head));
              break;
          case '=':
              printf("\nResult = %d", stack_pop(head));
              exit;
      }
    return pos;
};

int main(){
    stack head = stack_new();

     int pos = 0;
     char ch = fgetc(stdin);

     while(ch != EOF) {
         parse(head, pos, ch);
         ch = fgetc(stdin);
         pos++;
     }

    return 0;
}
