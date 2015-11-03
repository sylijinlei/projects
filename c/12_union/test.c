#include <stdio.h>
union U{
    char a;
    int b;
}u;
int main(int argc, char *argv[])
{
    u.a = 100;
    printf("size of union = %d\n", sizeof(u));
    printf("u = %d\n", u.b);
    return 0;
}
