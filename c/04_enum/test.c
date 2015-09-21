#include <stdio.h>
enum PixelFormat{
    MON,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN,
}weekday;
int main(int argc, char *argv[])
{
    weekday = 19;
    printf("week = %d\n", weekday);
    return 0;
}
