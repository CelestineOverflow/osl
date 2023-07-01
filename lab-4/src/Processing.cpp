// Processing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <cstdint>
#include <thread>

#define MYNAME "Processing"

// Create handles for each event
HANDLE ghStartProcessingEvent = NULL, ghProcessingFinishedEvent = NULL, ghExitEvent = NULL;
DWORD WINAPI Processing(LPVOID);


int main()
{
	//handles for process and threads
	HANDLE hProcess = GetCurrentProcess();
	HANDLE hThread = GetCurrentThread();
	//set priority and processors
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



	//get info
	int processid = GetProcessId(hProcess);
	int threadid = GetThreadId(hThread);
	int processornum = GetCurrentProcessorNumber();
	DWORD ppriority = GetPriorityClass(hProcess);
	int tpriority = GetThreadPriority(hThread);

	std::cout << "Process ID: " << processid << "\nThread ID: " << threadid << "\nNow running on processor #" << processornum
		<< "\nWith process priority class 0x" << std::hex << ppriority << "\nWith thread priority " << tpriority << std::dec << std::endl;
	

	DWORD dwEvent;
	BOOL bContinue = TRUE;
	volatile int vi, i;

	// open StartProcessingEvent:
	ghStartProcessingEvent = OpenEvent(EVENT_ALL_ACCESS | EVENT_MODIFY_STATE, FALSE, TEXT("StartProcessingEvent"));


	if (ghStartProcessingEvent == NULL) {
		printf("%s: Error opening event %s! Are you sure Control is running? Hit any key...\n\n", MYNAME, "StartProcessingEvent");
		(void)_getch();
		return EXIT_FAILURE;
	}
	// open ProcessingFinishedEvent:
	ghProcessingFinishedEvent = OpenEvent(EVENT_ALL_ACCESS | EVENT_MODIFY_STATE, FALSE, TEXT("ProcessingFinishedEvent"));
	if (ghProcessingFinishedEvent == NULL) {
		printf("%s: Error opening event %s! Are you sure Control is running? Hit any key...\n\n", MYNAME, "ProcessingFinishedEvent");
		(void)_getch();
		return EXIT_FAILURE;
	}
	// open quit event:
	ghExitEvent = OpenEvent(EVENT_ALL_ACCESS | EVENT_MODIFY_STATE, FALSE, TEXT("ExitEvent"));

	if (ghExitEvent == NULL) {
		printf("%s: Error opening event %s! Are you sure Control is running? Hit any key...\n\n", MYNAME, "ExitEvent");
		(void)_getch();
		return EXIT_FAILURE;
	}

	// wait for events raised by Control) or the quit event (may be set by every participant):
	HANDLE ghEvents[] = { ghStartProcessingEvent, ghExitEvent , ghProcessingFinishedEvent };
	int nNumEvents = sizeof(ghEvents) / sizeof(ghEvents[0]);

	printf("%s process is running.\n", MYNAME);

	while (bContinue) {
			dwEvent = WaitForMultipleObjects(
			nNumEvents,	// number of objects to wait for
			ghEvents,	// array of objects to wait for
			FALSE,		// wait for any object ...
			INFINITE);	// ...and for a very long time

		switch (dwEvent) // return value indicates, which event is signalled now
		{
		case WAIT_OBJECT_0 + 0: // StartProcessingEvent
				// Some processing..
				for (i = 0; i < 9000000; i++) { vi = i % 2; }

				// Set ProcessingFinishedEvent
				if (!SetEvent(ghProcessingFinishedEvent)) {
					printf("%s: Error setting event %s! Hit any key...\n\n", MYNAME, "ProcessingFinishedEvent");
					(void)_getch();
					return 1;
				}
				break;
		case WAIT_OBJECT_0 + 1: // ExitEvent
			bContinue = FALSE;
			break;
		case WAIT_TIMEOUT:
			// no event but timeout
			break;
		default:
			// invalid return value: Error
			printf("%s: Wait error: %d\n", MYNAME, GetLastError());
			ExitProcess(0);
		}

	}

	printf("\n%s: Process stopped. Hit any key to close Window.\n", MYNAME);
	(void)_getch();
	ExitProcess(0);
}
