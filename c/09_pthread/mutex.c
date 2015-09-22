#include <stdio.h>
#include <pthread.h>

pthread_t thread_id[2];
pthread_mutex_t mutex;
int tickets = 100;
void * thread1(void *data) 
{
    pthread_detach(pthread_self());
    while(1)
    {
        pthread_mutex_lock(&mutex);
        if(tickets > 0)
        {
            usleep(5000);
            printf("thread1 tickets = %d\n", tickets);
            tickets--;
        }else                //卖完了
        {
            break;
        }
        pthread_mutex_unlock(&mutex);
        pthread_yield();
    }
    pthread_exit(0);
}
void * thread2(void *data) 
{
    pthread_detach(pthread_self());
    while(1)
    {
        pthread_mutex_lock(&mutex);
        if(tickets > 0)
        {
            usleep(5000);
            printf("thread2 tickets = %d\n", tickets);
            tickets--;
        }else
        {
            break;
        }
            pthread_mutex_unlock(&mutex);
        pthread_yield();
    }
    pthread_exit(0);
}
int main(int argc, char *argv[])
{
    int ret;
    int data1 = 101;
    int data2 = 102;
    pthread_mutex_init(&mutex, NULL);
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
