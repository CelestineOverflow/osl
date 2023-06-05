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
#define MAX_TEXT 512

struct msg_buffer
{
    long message_type;
    char message_text[MAX_TEXT];
} message;

void readMessagueQueue(int msgid, struct msg_buffer *message, long type)
{
    msgrcv(msgid, message, MAX_TEXT, type, 0);
}

void writeMessageQueue(int msgid, struct msg_buffer *message)
{
    msgsnd(msgid, message, strlen(message->message_text) + 1, 0);
}

void writeTestProccess(int msgid, struct msg_buffer *message, char *text)
{
    message->message_type = 1;
    strcpy(message->message_text, text);
    writeMessageQueue(msgid, message);
}

void readTestProccess(int msgid, struct msg_buffer *message)
{
    readMessagueQueue(msgid, message, 1);
    printf("Data received is: %s\n", message->message_text);
    //remove message queue
    msgctl(msgid, IPC_RMID, NULL);
}

int main(int argc, char **argv)
{
    key_t key = ftok("/some/path", 65);        // create unique key
    int msgid = msgget(key, 0666 | IPC_CREAT); // returns message queue identifier
    //create child process
    pid_t pid = fork();
    if (pid == 0)
    {
        //child process
        //wait for 5 seconds
        sleep(5);
        readTestProccess(msgid, &message);
    }
    else
    {
        //parent process
        writeTestProccess(msgid, &message, "Hello world!");
    }
}