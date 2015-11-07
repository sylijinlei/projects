#include <stdio.h>
#include "list.h"

void init_head(pListHead list)
{
    list->next = list;
    list->prev= list;
}

void __list_add(pListHead new, pListHead prev, pListHead next)
{
    new->next = next;
    new->prev = prev; 
    next->prev = new;
    prev->next = new;
}
void list_add(pListHead list, pListHead new)
{
    __list_add(new, list, list->next);
}
void list_add_tail(pListHead list, pListHead new)
{
    __list_add(new, list->prev, list);
}
int list_getlen(pListHead list)
{
    pListHead pList = list->next;
    int num = 0;
    for( ; pList != list; pList = pList->next)
    {
        num++; 
    }
    return num;
}

void list_display(pListHead list)
{
    pListHead pList;
    for(pList= list->next  ; pList != list; pList = pList->next)
    {
        printf("id= %d     name = %s\n", pList->data.id, pList->data.name);
    }
}
