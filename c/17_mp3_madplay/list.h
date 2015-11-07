#ifndef  LIST_H
#define  LIST_H
#include "mp3.h"
typedef struct list_head{
    ElemType data;
    struct list_head *prev;
    struct list_head *next;
}ListHead, *pListHead;

void init_head(pListHead list);

void list_add(pListHead list, pListHead new);
void list_add_tail(pListHead list, pListHead new);
int list_getlen(pListHead list);
void list_display(pListHead list);

#endif  // LIST_H
