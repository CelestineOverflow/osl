#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <signal.h>

#define TEXT_SIZE 100
#define IS_CHILD 0
#define IS_PARENT 1
#define LOOP_ITERATIONS 10
#define FILE_PATH "file.txt"

void truncateFile(const char *filePath)
{
    int fileDescriptor = open(filePath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fileDescriptor < 0)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    close(fileDescriptor);
}

void writeFileProcess(const char *filePath, const char *text, pid_t processID)
{
    int fileDescriptor = open(filePath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fileDescriptor < 0)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    struct flock fileLock;
    fileLock.l_type = F_WRLCK;
    fileLock.l_whence = SEEK_SET;
    fileLock.l_start = 0;
    fileLock.l_len = TEXT_SIZE;
    fileLock.l_pid = getpid();
    fcntl(fileDescriptor, F_SETLKW, &fileLock);
    write(fileDescriptor, text, strlen(text));
    printf("Wrote %ld bytes to %s\n", strlen(text), filePath);
    fileLock.l_type = F_UNLCK;
    fcntl(fileDescriptor, F_SETLK, &fileLock);
    close(fileDescriptor);
    kill(processID, SIGUSR1);
}

void readFileProcess(const char *filePath, int processType)
{
    pause();
    printf("Process %s is reading ---", processType == IS_CHILD ? "child" : "parent");
    int fileDescriptor = open(filePath, O_RDONLY);
    if (fileDescriptor < 0)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    struct flock fileLock;
    fileLock.l_type = F_RDLCK;
    fileLock.l_whence = SEEK_SET;
    fileLock.l_start = 0;
    fileLock.l_len = TEXT_SIZE;
    fileLock.l_pid = getpid();
    fcntl(fileDescriptor, F_SETLKW, &fileLock);
    char buffer[1024];
    int bytesRead = read(fileDescriptor, buffer, 1024);
    if (bytesRead < 0)
    {
        perror("Error reading file");
        exit(EXIT_FAILURE);
    }
    buffer[bytesRead] = '\0';
    printf("Read %d bytes from %s ---", bytesRead, filePath);
    printf("%s\n", buffer);
    fileLock.l_type = F_UNLCK;
    fcntl(fileDescriptor, F_SETLK, &fileLock);
    close(fileDescriptor);
    truncateFile(filePath);
}

void signalHandler(int signalNumber)
{
    return;
}

int main()
{
    signal(SIGUSR1, signalHandler);
    pid_t processID = fork();
    if (processID == IS_CHILD) 
    {
        pid_t parentProcessID = getppid();
        // sleep(1);
        for (int i = 0; i < LOOP_ITERATIONS; i++)
        {
            // writeFileProcess(FILE_PATH, "Hello from child", parentProcessID);
            readFileProcess(FILE_PATH, IS_CHILD);
            writeFileProcess(FILE_PATH, "Hello from child", parentProcessID);
        }
    }
    else if (processID > IS_CHILD) 
    {
        pid_t childProcessID = processID;
        sleep(1);
        for (int i = 0; i < LOOP_ITERATIONS; i++)
        {
            // readFileProcess(FILE_PATH, IS_PARENT);
            writeFileProcess(FILE_PATH, "Hello from parent", childProcessID);
            readFileProcess(FILE_PATH, IS_PARENT);
        }
    }
    else
    {
        fprintf(stderr, "Error creating child process\n");
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}
