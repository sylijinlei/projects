#include <stdio.h>
#include <pthread.h>

pthread_t thread_id[2];
pthread_mutex_t mutex;
pthread_cond_t cond;
int tickets = 100;
void * thread1(void *data) 
{   //只卖3的倍数
    pthread_detach(pthread_self());
    while(1)
    {
        pthread_mutex_lock(&mutex);
        while(tickets > 0)
        {
            if(tickets % 3 != 0)
            {
                pthread_cond_wait(&cond, &mutex);
            }else
            {
                usleep(5000);
                printf("thread1 tickets = %d\n", tickets);
                tickets--;
                pthread_cond_signal(&cond);
            }
        }
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(0);
}
void * thread2(void *data) 
{
    pthread_detach(pthread_self());
    while(1)
    {
        pthread_mutex_lock(&mutex);
        while(tickets > 0)
        {
            if(tickets % 3 == 0)
            {
                pthread_mutex_unlock(&mutex);
            }else
            {
                usleep(5000);
                printf("thread2 tickets = %d\n", tickets);
                tickets--;
                pthread_cond_signal(&cond);
            }
        }
        /*pthread_mutex_unlock(&mutex);*/
    }
    pthread_exit(0);
}
int main(int argc, char *argv[])
{
    int ret;
    int data1 = 101;
    int data2 = 102;
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
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
