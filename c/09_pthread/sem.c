#include <stdio.h>
#include <pthread.h>

pthread_t thread_id[2];
sem_t sem;
int tickets = 100;
void * thread1(void *data) 
{   //只卖3的倍数
    pthread_detach(pthread_self());
    while(1)
    {
        sem_wait(&sem);
        while(tickets > 0)
        {
            if(tickets % 3 == 0)
            {
                usleep(5000);
                printf("thread1 tickets = %d\n", tickets);
                tickets--;
            }else
            {
            }
        }
    }
    pthread_exit(0);
}
void * thread2(void *data) 
{
    pthread_detach(pthread_self());
    while(1)
    {
        while(tickets > 0)
        {
            if(tickets % 3 != 0)
            {
                usleep(5000);
                printf("thread2 tickets = %d\n", tickets);
                tickets--;
            }else
            {
            }
        }
    }
    pthread_exit(0);
}
int main(int argc, char *argv[])
{
    int ret;
    int data1 = 101;
    int data2 = 102;
    sem_init(&sem,0,1);
    ret = pthread_create(&thread_id[0], NULL, (void *)thread1, (void*)&data1);
    if (ret != 0)
    {
        printf("thread1 creat failed!\n");
        return -1;
    }
    ret = pthread_create(&thread_id[1], NULL, (void*)thread2, (void*)&data2);
    if (ret != 0)
    {
        printf("thread2 creat failed!\n");
        return -1;
    }
    pause();
    pthread_mutex_destroy(&mutex);
    return 0;
    /*pthread_exit(0);*/
}
