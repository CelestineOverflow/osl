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
    FILE *fp = fopen(filePath, "w");
    if (fp == NULL)
    {
        printf("Error: Unable to open the file.\n");
        return;
    }
    fclose(fp);
    printf("Successfully erased the file.\n");
}

void writeFileProcess(const char *filePath, const char *text, pid_t processID)
{
    FILE *fp = fopen(filePath, "w");
    if (fp == NULL)
    {
        printf("Error: Unable to open the file.\n");
        return;
    }
    fprintf(fp, "%s", text);
    fclose(fp);
    kill(processID, SIGUSR1);
}

void readFileProcess(const char *filePath, int processType)
{
    pause();
    printf("Process %s is reading ---", processType == IS_CHILD ? "child" : "parent");
    FILE *fp = fopen(filePath, "r");
    if (fp == NULL)
    {
        printf("Error: Unable to open the file.\n");
        return;
    }
    char ch;
    printf("File content: ");
    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }
    printf("\n");
    fclose(fp);
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
