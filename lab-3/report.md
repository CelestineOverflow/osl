# OSL Lab 3 Report

## Table of Contents

* Execution of a TCP server via internet superdaemon
* Message queues
* Shared memory

## Execution of a TCP server via internet superdaemon

we created a service that reads from the stdin and write the data to a file as follows

### task1.c

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  const char * filename = argv[1];
  FILE *fp = fopen(filename, "a");
  if (fp == NULL) {
    printf("Cannot open file %s\n", filename);
    exit(1);
  }
  char str[4096];
  while (fgets(str, sizeof str, stdin)) {
    fputs(str, fp);
    fflush(fp);
  }
  fflush(fp);
  fclose(fp);
  return 0;
}
```

we added the service to the inetd.conf file as follows

### inetd.conf

```conf
# Packages should modify this file by using update-inetd(8)
#
# <service_name> <sock_type> <proto> <flags> <user> <server_path> <args>
#
#:INTERNAL: Internal services
#discard		stream	tcp	nowait	root	internal
#discard		dgram	udp	wait	root	internal
#daytime		stream	tcp	nowait	root	internal
#time		stream	tcp	nowait	root	internal

#:STANDARD: These are standard services.

telnet		stream	tcp	nowait	telnetd	/usr/sbin/tcpd	/usr/sbin/in.telnetd
celeste-net	dgram	udp	wait	root	/home/celeste/lab-3/task1 task1 /home/celeste/lab-3/test0.txt
```

we then modified the /etc/services file to add the service as follows

### services

```conf
# Local services

celeste-net	9999/udp			#celeste testing ground =^.^=
```

we then restarted the virtual machine and tested the service with a python script as follows

### test.py

```python

import socket

udp_server_ip = 'localhost'
udp_server_port = 9999

def sendStringToServer(udp_server_ip, udp_server_port, string_to_send):
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    client_socket.sendto(string_to_send.encode(), (udp_server_ip, udp_server_port))
    client_socket.close()
    
sendStringToServer(udp_server_ip, udp_server_port, 'Hedddllrfghjklo World\n')

```

we then checked the file and it had the string we sent

### test0.txt

```txt
Hedddllrfghjklo World
```
## Message queues

### task2.c

```c
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
```

we then compiled the program and executed it

```bash
gcc task2.c -o task2
./task2
```

we then checked the output and it was as expected

```bash
Data received is: Hello world!
```

## Shared memory

### task3.c

```c
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
```

we then compiled the program and executed it

```bash
gcc task3.c -o task3
./task3
```

we then checked the output and it was as expected

```bash
Write Data : Hello world!
Data read from memory: Hello world!
```

