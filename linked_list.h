#ifndef DATA_STRUCTURES__LINKED_LIST_H
#define DATA_STRUCTURES__LINKED_LIST_H

#include <stdlib.h>

struct _linked_list
{
    int el;
    struct _linked_list* next;
};

typedef struct _linked_list linked_list;

void insert(linked_list* ll, int pos, int el);
int delete(linked_list* ll, int pos);
int len(linked_list* ll);
void print(linked_list* head);

#endif //DATA_STRUCTURES__LINKED_LIST_H
