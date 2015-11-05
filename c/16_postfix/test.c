#include <stdio.h>
#include <string.h>
int postfix_match(char *str, char *match)
{
    char *pstr = str;
    for( ; *pstr !='.' && *pstr!= '\0'; pstr++);
    if(*pstr == '\0'|| *match == '\0')
    {
        return -1;
    }
    pstr++;
    return strcmp(pstr, match);
}
int main(int argc, char *argv[])
{
    printf("return value = %d\n", postfix_match(argv[1], argv[2]));
    return 0;
}
