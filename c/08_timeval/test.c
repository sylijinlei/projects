#include <stdio.h>
#include <sys/time.h>
int main(int argc, char *argv[])
{
    struct timeval tv;
   gettimeofday(&tv, NULL);    //获取1970年1月1号到现在的时间
   printf("sec = %u, micro_sec = %u\n", tv.tv_sec, tv.tv_usec);
   sleep(1);
   gettimeofday(&tv, NULL); 
   printf("sec = %u, micro_sec = %u\n", tv.tv_sec, tv.tv_usec);
    return 0;
}
