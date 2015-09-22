#include <stdio.h>
#include <signal.h>
void signal_handler(int sig)
{
    static int count = 0;
    if(sig == SIGALRM)
    {
        count++;
        printf("timer count == %d\n", count);
        printf("pid1== %d\n", getpid());
    }
    if(count == 15)
    {
        alarm(0); //取消之前的闹钟,并返回剩余的时间
        kill(getpid(), SIGINT);  //退出程序
       printf("i am thread i will exit\n"); 
        return;
    }
    alarm(2);

}
int main(int argc, char *argv[])
{
   /*signal(SIGINT, SIG_DFL) ;//采用系统默认行为*/
   /*signal(SIGINT, SIG_IGN) ;//忽略信号*/
    signal(SIGALRM, signal_handler);
    alarm(1);
   while(1)
   {
        printf("pid2== %d\n", getpid());
    /*printf("hello!\n");*/
    sleep(1);
   }
   return 0;
}
