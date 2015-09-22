#include <stdio.h>
#include <pthread.h>

pthread_t thread_id[2];
void * thread1(void *data) 
{
    pthread_detach(pthread_self());
    while(1)
    {
        sleep(1);
        printf("thread1 data = %d\n", *(int*)data);
    }
    pthread_exit(0);
}
void * thread2(void *data) 
{
    pthread_detach(pthread_self());
    while(1)
    {
        sleep(1);
        printf("thread2 data = %d\n", *(int*)data);
    }
    pthread_exit(0);
}
int main(int argc, char *argv[])
{
    int ret;
    int data1 = 101;
    int data2 = 102;
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
    return 0;
    /*pthread_exit(0);*/
}
