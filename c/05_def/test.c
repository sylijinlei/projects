#include "stdio.h"
#define fun(a, b) a##b
#define fun2(a) #a
int main(int argc, char *argv[])
{
    int x = 3, y = 5;
    int xy ;
    char *str = fun2(abcd);
   fun(x, y) = 44;
   printf("xy = %d\n", fun(x,y));
   printf("str = %s\n", str);

    return 0;
}
