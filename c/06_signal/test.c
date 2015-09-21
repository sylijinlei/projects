#include <stdio.h>
#include <signal.h>
int main(int argc, char *argv[])
{
   /*signal(SIGINT, SIG_DFL) ;//采用系统默认行为*/
   signal(SIGINT, SIG_IGN) ;//忽略信号
   while(1)
   {
    printf("hello!\n");
    sleep(1);
   }
   return 0;
}
