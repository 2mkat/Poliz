#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

void insert(linked_list* ll, int pos, int el){
    for (int i = 0; i < pos; i++){
        ll = ll->next;
    }
    linked_list* ll1 = calloc(1, sizeof(linked_list));
    ll1->el = el;
    ll1->next = ll->next;
    ll->next = ll1;
};

int delete(linked_list* ll, int pos){
    for (int i = 0; i < pos; i++){
        ll = ll->next;
    }
//puts("lala1");
    int el1 = ll->next->el;
//puts("lala2");
    linked_list* ll1 = ll->next;
    ll->next = ll->next->next;
    free(ll1);

    return el1;
};

int len(linked_list* ll){
    int res=0;
    while (ll->next != NULL){
        ll = ll->next;
        res++;
    }
    return res;
};

void print(linked_list* head){
    linked_list* next = head->next;
    while (next != NULL){
        printf("%d ", next->el);
        next = next->next;
    }
};
