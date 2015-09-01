#include <stdio.h>
 typedef int (fun_p)(int , int );
int add(int a, int b)
{
    return a + b;
}
int main(int argc, char *argv[])
{
    int a = 102;
    int b = 103;
    fun_p *arr[2];
    arr[1] = add;
    fun_p **p = arr;
    printf("a + b = %d\n", p[1](a , b));
    return 0;
}
