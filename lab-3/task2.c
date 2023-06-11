// implement message queue
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
//include fork and wait
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define MAX_TEXT 100

struct msg_buffer
{
    long message_type;
    char message_text[MAX_TEXT];
} message;

void writeTestProccess(int msgid, struct msg_buffer *message, char *text)
{
    message->message_type = 1;
    strcpy(message->message_text, text);
    msgsnd(msgid, message, strlen(message->message_text) + 1, 0);
}

#define __USE_BLOCKING

void readTestProccess(int msgid, struct msg_buffer *message)
{
    #ifdef __USE_BLOCKING
        //blocking until message arrive
        msgrcv(msgid, message, MAX_TEXT, 1, 0);
        printf("Data Received is : %s \n", message->message_text);
    #endif

    #ifdef __USE_NON_BLOCKING
        //non blocking
        if (msgrcv(msgid, message, MAX_TEXT, 1, IPC_NOWAIT) == -1)
        {
            printf("No data\n");
        }
        else
        {
            printf("Data Received is : %s \n", message->message_text);
        }
    #endif
}

int main(int argc, char **argv)
{
    key_t key = ftok("/some/path", 65);        // create unique key
    //create message queue
    int msgid = msgget(key, 0666 | IPC_CREAT | IPC_EXCL); // create message queue and return id
    if (msgid == -1)
    {
        printf("Message queue already exist\n");
        msgid = msgget(key, 0666);
    }
    else
    {
        printf("Message queue created\n");
    }
    //create child process
    pid_t pid = fork();
    if (pid == 0)
    {
        //child process
        //read all message from message queue
        for(int i = 0 ; i < 10 ; i++)
        {
            readTestProccess(msgid, &message);
        }
    }
    else
    {
        //parent process
        //
        sleep(5);
        int times = atoi(argv[1]);
        printf("times: %d\n", times);
        for (int i = 0; i < times; i++)
        {
            printf("writing message to message queue %d\n", i);
            char msg[MAX_TEXT];
            sprintf(msg, "Hello from parent process %d", i);
            writeTestProccess(msgid, &message, msg);
        }
        printf("Data has been sent\n");
    }
}