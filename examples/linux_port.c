#include "../eventloop.h"

#include <stdio.h>
#include <sys/time.h>

el_tick_t el_portTickGet(void)
{
    struct timeval tim;
    gettimeofday(&tim, NULL);

    return tim.tv_sec * 1000 + tim.tv_usec / 1000;
}

void async_task1(void *args)
{
    printf("Run this after 1000 ms \n");
}

void async_task2(void *args)
{
    printf("Run this every 200 ms \n");
}

void async_task3(void *args)
{
    printf("Run this every 400 ms , and arg = %d \n", *((int *)args));
}

int main()
{
    int arg = 2023;
    el_setTimeout(async_task1, NULL, 1000);
    el_setInterval(async_task2, NULL, 200);
    el_setInterval(async_task3, &arg, 400);

    el_enterLoop();
}
