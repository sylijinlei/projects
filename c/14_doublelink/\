#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct list_head{
    int item;
    struct list_head *prior;
    struct list_head *next;
};
struct list_head * init_head(int data)
{
    struct list_head *list;
    list = (struct list_head *)malloc(sizeof(struct list_head));
    list->item= data;
    list->next = list;
    list->prior = list;
    return list;
}
void list_add(struct list_head *list, int data)
{
    struct list_head *new = (struct list_head *)malloc(sizeof (struct list_head)); 
    new->item = data;
    new->next = list->next;
    new->prior = list;
    list->next->prior = new;
    list->next = new;
}
void list_add_tail(struct list_head *list, int data)
{
    struct list_head *new = (struct list_head *)malloc(sizeof (struct list_head)); 
    new->item = data;
    new->next = list;
    new->prior = list->prior;
    list->prior->next = new;
    list->prior = new;
}
void list_display(struct list_head *list)
{
    struct list_head *pList;
    pList= list;
    for( ;pList->next != list; pList = pList->next)
    {
        printf("item = %d\n", pList->item);
    }
     printf("item = %d\n", pList->item);
}
int list_getlen(struct list_head *list)
{
   struct list_head *pList = list;
   int num = 0;
   for( ; pList->next != list; pList = pList->next)
   {
       num++; 
   }
   num++;
   return num;
}
int main(int argc, char *argv[])
{
    struct list_head *list;
    list = init_head(1);
    list_add(list, 2);
    list_add(list, 3);
    list_add(list, 4);
    list_add_tail(list, 5);
    list_add_tail(list, 6);
    list_add_tail(list, 7);
    list_display(list);
    printf("list length = %d\n", list_getlen(list));

    return 0;
}
