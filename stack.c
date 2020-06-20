#include "stack.h"
#include "linked_list.c"
#include <stdio.h>

stack stack_new()
{
    linked_list* head = calloc(1, sizeof(linked_list));
    stack res ={ .ll = head};
    return res;
}

void stack_push(stack s, int element)
{
    insert(s.ll, 0, element);
}

int stack_pop(stack s)
{
    return delete(s.ll, 0);
}
