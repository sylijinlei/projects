#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "list.h"
#include "mp3.h"
ListHead g_list;
int main(int argc, char *argv[])
{
    init_head(&g_list);
    mp3_song_list_init(&g_list, "./"); 
    list_display(&g_list);
    printf("list length = %d\n", list_getlen(&g_list));
    return 0;
}
