#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/time.h>



int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    int pid_num = getpid(); 

    for (int i = 0; i < 1000; i++)
    {
        if (pid == 0) {
            putchar('O'); 
            usleep(1000);    
        } else {
            putchar('X');
            usleep(1000);

        }
    }
    return 0;
}
