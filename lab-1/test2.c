#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/time.h>

void print_long(long value)
{
    if (value < 0)
    {
        putchar('-');
        value = -value;
    }
    if (value / 10)
    {
        print_long(value / 10);
    }
    putchar('0' + value % 10);
}

int print_current_time()
{
    struct timespec current_time;
    if (clock_gettime(CLOCK_REALTIME, &current_time) == -1)
    {
        perror("Error: Failed to get the current time");
        return 1;
    }
    print_long(current_time.tv_sec);
    putchar('.');
    for (int i = 8; i >= 0; i--)
    {
        long nsec = current_time.tv_nsec;
        for (int j = 0; j < i; j++)
        {
            nsec /= 10;
        }
        putchar('0' + nsec % 10);
    }
    putchar(' ');
    putchar('s');
    putchar('e');
    putchar('c');
    putchar('o');
    putchar('n');
    putchar('d');
    putchar('s');
    putchar('\n');
    return 0;
}

int main()
{

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("Fork failed");
        exit(1);
    }
    int pid_num = getpid();

    for (int i = 0; i < 10000; i++)
    {

        if (pid == 0)
        {
            putchar('0');
        }
        else
        {
            putchar('1');
        }
        usleep(1000);
        putchar(' ');
        print_current_time();
    }

    return 0;
}