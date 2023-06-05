#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
//include fork and wait
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    // ftok to generate unique key
    key_t key = ftok("/some/path", 65);

    // shmget returns an identifier in shmid
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    // shmat to attach to shared memory
    char *str = (char *)shmat(shmid, (void *)0, 0);

    // create child process
    pid_t pid = fork();
    if (pid == 0)
    {
        // child process
        // wait for 5 seconds
        sleep(5);
        printf("Data read from memory: %s\n", str);

        //detach from shared memory
        shmdt(str);

        // destroy the shared memory
        shmctl(shmid, IPC_RMID, NULL);
    }
    else
    {
        // parent process
        printf("Write Data : ");
        fgets(str, 100, stdin);
        printf("Data written in memory: %s\n", str);

        //detach from shared memory
        shmdt(str);
    }

    return 0;
}