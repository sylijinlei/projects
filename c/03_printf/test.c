#include <stdio.h>
#define Loge(...) printf( __VA_ARGS__) 
#define NVTBIT(start,end) ((0xFFFFFFFFUL >> (31 - start)) & (0xFFFFFFFFUL >>end  << end))

int main(int argc, char *argv[])
{
    int a = 10;
    unsigned int test = NVTBIT(28, 17);
    Loge("a = %d!\n", a);
    Loge("test = 0x%x\n", test); 
    return 0;
}
