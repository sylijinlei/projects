#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{
    int i = 10;
    printf("size = %d\n", typeof(i));
    return 0;
}
