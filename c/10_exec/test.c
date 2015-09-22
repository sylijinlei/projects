#include <stdio.h>
int main(int argc, char *argv[])
{
    /*system("ls -l");*/
    execl("/bin/ls","ls", "-l", NULL);
    printf("hello!\n");
    return 0;
}
