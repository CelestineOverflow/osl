// Control.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <cstdint>
#include <thread>

#define MYNAME "Control"

HANDLE ghInputEvent;
HANDLE ghStartProcessingEvent;
HANDLE ghProcessingFinishedEvent;
HANDLE ghOutputEvent;
HANDLE ghExitEvent;

DWORD WINAPI Control(LPVOID);

int main()
{
	// handles for process and threads
	HANDLE hProcess = GetCurrentProcess();
	HANDLE hThread = GetCurrentThread();

	// set priority and processors
	int threadPriorityMask = THREAD_PRIORITY_NORMAL;
	DWORD processAffinityMask = 0x00000001;

	if (!SetThreadPriority(hThread, threadPriorityMask))
	{
		printf("SetThreadPriority failed process name: %s, error: %d\n", MYNAME, GetLastError());
		return EXIT_FAILURE;
	}
	if (!SetThreadAffinityMask(hThread, processAffinityMask))
	{
		printf("SetThreadAffinityMask failed process name: %s, error: %d\n", MYNAME, GetLastError());
		return EXIT_FAILURE;
	}
	// get info
	int processid = GetProcessId(hProcess);
	int threadid = GetThreadId(hThread);
	int processornum = GetCurrentProcessorNumber();
	DWORD ppriority = GetPriorityClass(hProcess);
	int tpriority = GetThreadPriority(hThread);

	std::cout << "Process ID: " << processid << "\nThread ID: " << threadid << "\nNow running on processor #" << processornum
			  << "\nWith process priority class 0x" << std::hex << ppriority << "\nWith thread priority " << tpriority << std::dec << std::endl;

	BOOL bContinue = TRUE;
	DWORD dwEvent;

	// Create events

	// create input event:
	ghInputEvent = CreateEvent(
		NULL,				 // default security attributes
		FALSE,				 // Auto Reset! Only one process / thread gets this
		FALSE,				 // initial state: nonsignaled
		TEXT("InputEvent")); // name of the event to adress from other processes
	// check if event was created successfully:
	if (ghInputEvent == NULL)
	{
		printf("%s: Create InputEvent error: %d\n", MYNAME, GetLastError());
		ExitProcess(0);
	}

	// create start processing event:
	ghStartProcessingEvent = CreateEvent(
		NULL,						   // default security attributes
		FALSE,						   // Auto Reset! Only one process / thread gets this
		FALSE,						   // initial state: nonsignaled
		TEXT("StartProcessingEvent")); // name of the event to adress from other processes
	if (ghStartProcessingEvent == NULL)
	{
		printf("%s: Create StartProcessingEvent error: %d\n", MYNAME, GetLastError());
		ExitProcess(0);
	}

	// create processing finished event:
	ghProcessingFinishedEvent = CreateEvent(
		NULL,							  // default security attributes
		FALSE,							  // Auto Reset! Only one process / thread gets this
		FALSE,							  // initial state: nonsignaled
		TEXT("ProcessingFinishedEvent")); // name of the event to adress from other processes
	if (ghProcessingFinishedEvent == NULL)
	{
		printf("%s: Create ProcessingFinishedEvent error: %d\n", MYNAME, GetLastError());
		ExitProcess(0);
	}

	// create output event:
	ghOutputEvent = CreateEvent(
		NULL,				  // default security attributes
		FALSE,				  // Auto Reset! Only one process / thread gets this
		FALSE,				  // initial state: nonsignaled
		TEXT("OutputEvent")); // name of the event to adress from other processes
	if (ghOutputEvent == NULL)
	{
		printf("%s: Create OutputEvent error: %d\n", MYNAME, GetLastError());
		ExitProcess(0);
	}

	// create exit event:
	ghExitEvent = CreateEvent(
		NULL,				// default security attributes
		TRUE,				// Manual Reset! All processes / threads wait for this
		FALSE,				// initial state: nonsignaled
		TEXT("ExitEvent")); // name of the event to adress from other processes

	if (ghExitEvent == NULL)
	{
		printf("%s: Create ExitEvent error: %d\n", MYNAME, GetLastError());
		ExitProcess(0);
	}

	HANDLE ghEvents[] = {ghInputEvent, ghProcessingFinishedEvent, ghExitEvent};
	int nNumEvents = sizeof(ghEvents) / sizeof(ghEvents[0]);

	printf("%s process is running.\n", MYNAME);

	while (bContinue)
	{
		dwEvent = WaitForMultipleObjects(
			nNumEvents, // number of objects to wait for
			ghEvents,	// array of objects to wait for
			FALSE,		 // wait for all objects to be signaled
			INFINITE);	 // wait infinite time
		printf("%s: I got the event %d!\n\n", MYNAME, dwEvent);
		switch (dwEvent)
		{
		case WAIT_OBJECT_0 + 0: // InputEvent
			if (!SetEvent(ghStartProcessingEvent))
			{
				printf("%s: SetEvent error: %d\n", MYNAME, GetLastError());
				ExitProcess(0);
			}
			else
			{
				printf("%s: SetEvent %s\n", MYNAME, "StartProcessingEvent");
			}
			break;
		case WAIT_OBJECT_0 + 1: // ProcessingFinishedEvent
			if (!SetEvent(ghOutputEvent))
			{
				printf("%s: SetEvent error: %d\n", MYNAME, GetLastError());
				ExitProcess(0);
			}
			else
			{
				printf("%s: SetEvent %s\n", MYNAME, "OutputEvent");
			}
			break;
		case WAIT_OBJECT_0 + 2: // ExitEvent
			bContinue = FALSE;
			break;
		case WAIT_TIMEOUT:
			break;

		default:
			printf("%s: Wait error: %d\n", MYNAME, GetLastError());
			ExitProcess(0);
		}

		printf("\n%s: Process stopped. Hit any key to close Window.\n", MYNAME);
		(void)_getch();

		for (int i = 0; i < nNumEvents; i++)
		{
			CloseHandle(ghEvents[i]);
		}
		ExitProcess(0);
	}
}
