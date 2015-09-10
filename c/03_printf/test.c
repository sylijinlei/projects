#include <stdio.h>
#define Loge(...) printf( __VA_ARGS__) ;
int main(int argc, char *argv[])
{
    int a = 10;
    Loge("a = %d!\n", a);
    return 0;
}
