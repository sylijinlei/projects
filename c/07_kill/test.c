#include <stdio.h>
#include <signal.h>

typedef void (*SIGNAL_FUN)(int);

void signal_handler(int a)
{
    printf("a = %d\n", a);
}

int main(int argc, char *argv[])
{
    SIGNAL_FUN p_signal_handler = signal_handler;
    signal(SIGUSR2, signal_handler);
    while(1);
    return 0;
}
