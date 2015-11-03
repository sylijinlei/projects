#include <stdio.h>
int main(int argc, char *argv[])
{
    char *string;
    char *str = " 12abc";
    printf("str = %d\n", strtol(str, &string, 0));
    printf("return = %s\n", string);
    return 0;
}
