#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/time.h>

int main()
{
    pid_t pid = fork();
    clock_t start, endOfParent, endOfChild;
    if (pid < 0)
    {
        perror("Fork failed");
        exit(1);
    }
    while (1)
    {
        start = clock();

        if (pid > 0)
        { // fork() returns the parent process, the process ID of the child process.
            printf("I'm Parent with pid:\t%d\n", getpid());
            endOfParent = clock();
            printf("Elapsed t_exec - Parent:\t%.4f s\n", ((double)endP - start) * 1e3 / CLOCKS_PER_SEC);
        }
        else if (pid == 0)
        { // fork() returns the child process, "0".
            printf("I'm Child with pid:\t%d\n", getpid());
            endOfChild = clock();
            printf("Elapsed t_exec - Child:\t%.4f s\n", ((double)endP - start) * 1e3 / CLOCKS_PER_SEC);
        }
    }

    return 0;
}
