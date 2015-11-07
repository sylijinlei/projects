#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include "mp3.h"
#include "list.h"
extern ListHead g_list;
int mp3_song_list_init(pListHead *list, char *path)
{
    DIR *dir;  
    struct dirent *pdirent;  	
    struct mp3_info *item;
    pListHead new;
    int i = 0;
    dir = opendir(path);
    if (dir == NULL)
    {
        printf("open dir error\n");
        return -1;
    }
    while((pdirent = readdir(dir)) != NULL)
    {
        if(0 != postfix_match(pdirent->d_name, "c"))
            continue;
       new = (pListHead)malloc(sizeof(ListHead)); 
       new->data.id = i+1;
       strcpy(new->data.name, pdirent->d_name);
       list_add_tail(&g_list, new);
       i++;
    }
    closedir(dir);
    return 0;
}
int postfix_match(char *string , const char *match)
{
    char *pstr = string;
    for(; *pstr != '.' && *pstr != 0; pstr++);
    if (*pstr == '\0' || *match == '\0')
    {
        return -1;
    }
    pstr++;
    return strcmp(pstr, match);
}
