#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{
    DIR *dir = NULL;
    struct dirent *entry;
    dir = opendir("testdir");
    if(dir == NULL)
    {
        printf("open dir error\n");
    }
    while(entry = readdir(dir))
    {
        printf("filename = %s\n", entry->d_name);
    }
    closedir(dir);
    return 0;
}
