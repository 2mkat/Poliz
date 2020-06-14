#include "stack.h"

void stack_push(stack* st, int pos, int el){
    for (int i = 0; i < pos; i++){
        st = st->next;
    }
    stack* stack1 = calloc(1, sizeof(stack));   // create new object
    stack1->el = el;
    stack1->next = st->next;
    st->next = stack1;
};

int stack_pop(stack* st, int pos){
    for (int i = 0; i < pos; i++) {
        st = st->next;
    }

    int el = st->next->el;
    stack* stack1 = st->next;
    st->next = st->next->next;

    free(stack1);

    return el;
};