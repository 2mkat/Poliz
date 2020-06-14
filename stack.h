#ifndef STACK_LIBRARY_H
#define STACK_LIBRARY_H

#include <stdlib.h>
#include <stdio.h>

typedef struct linked_list {
    int el;     // elements of stack
    struct linked_list* next;      // pointer to the next element
} stack;

void stack_push(stack* st, int pos, int el);
int stack_pop(stack* st, int pos);

#endif //STACK_LIBRARY_H
