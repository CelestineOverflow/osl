#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <cstdint>
#include <thread>

//for threads
#include <cstdint>
#include <thread>

extern "C"
{
#include "medriver.h"
}

#ifdef _WIN64

#pragma comment (lib, "meIDSmain64.lib")

#else

#pragma comment (lib, "meIDSmain.lib")

#endif


#define MYNAME "InputOutput"

// Create handles for each event
HANDLE ghInputEvent = NULL, ghOutputEvent = NULL, ghExitEvent = NULL;

BOOL bContinue = TRUE;

// Forward declaration for callback function on MEids
int _stdcall IrqCallback(int iDevice, int iSubdevice, int iChannel,
	int iIrqCount, int iValue, void* pvContext, int iErrorCode);

const int gen_Device = 0;
const int out_SubDevice = 0;
const int out_Channel = 0;
const int in_IrqSubDevice = 10;
const int in_IrqChannel = 6;
const int in_IrqPin = 48;

int i_config_flags = ME_IO_SINGLE_CONFIG_DIO_BYTE;
int i_write_flags = ME_IO_SINGLE_TYPE_DIO_BYTE;

int i_me_error;

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
	int processid = GetCurrentProcessId();
	int threadid = GetCurrentThreadId();
	int processornum = GetCurrentProcessorNumber();
	DWORD ppriority = GetPriorityClass(hProcess);
	int tpriority = GetThreadPriority(hThread);

	std::cout << "Process ID: " << processid << "thread ID: " << threadid << "processor number: " << processornum << "priority class: " << ppriority << "thread priority: " << tpriority << std::endl;
	DWORD dwEvent;


	// open InputEvent:
	ghInputEvent = OpenEvent(EVENT_ALL_ACCESS | EVENT_MODIFY_STATE, FALSE, TEXT("InputEvent"));
	if (ghInputEvent == NULL) {
		printf("%s: Error opening event %s! Are you sure Control is running? Hit any key...\n\n", MYNAME, "InputEvent");
		(void)_getch();
		return EXIT_FAILURE;
	}
	ghOutputEvent = OpenEvent(EVENT_ALL_ACCESS | EVENT_MODIFY_STATE, FALSE, TEXT("OutputEvent"));
	if (ghOutputEvent == NULL) {
		printf("%s: Error opening event %s! Are you sure Control is running? Hit any key...\n\n", MYNAME, "OutputEvent");
		(void)_getch();
		return EXIT_FAILURE;
	}
	ghExitEvent = OpenEvent(EVENT_ALL_ACCESS | EVENT_MODIFY_STATE, FALSE, TEXT("ExitEvent"));

	if (ghExitEvent == NULL) {
		printf("%s: Error opening event %s! Are you sure Control is running? Hit any key...\n\n", MYNAME, "ExitEvent");
		(void)_getch();
		return EXIT_FAILURE;
	}

	//open ME driver system
	i_me_error = meOpen(0);

	if (i_me_error != ME_ERRNO_SUCCESS)
	{
		if (!SetEvent(ghExitEvent))
		{
			printf("%s: Error %d SetEvent()\n", MYNAME, GetLastError());
			bContinue = FALSE;
		}
		printf("****    meOpen - Error: %d    ****\n\n", i_me_error);

		printf("Press any key to terminate\n\n");

		(void)_getch();

		return -1;
	}

	//reset device (to reset IRQ Counter)
	i_me_error = meIOResetDevice(gen_Device,			//Device 0
		ME_IO_RESET_DEVICE_NO_FLAGS);			// Flags

	//declare callback funktion with fixed parameters
	i_me_error = meIOIrqSetCallback(gen_Device,						// Device index
		in_IrqSubDevice,						// Subdevice index
		IrqCallback,			// Callback routine
		NULL,					// Callback contextz
		ME_IO_IRQ_SET_CALLBACK_NO_FLAGS);		// Flags

	if (i_me_error != ME_ERRNO_SUCCESS)
	{
		if (!SetEvent(ghExitEvent))
		{
			printf("%s: Error %d SetEvent()\n", MYNAME, GetLastError());
			bContinue = FALSE;
		}
		printf("****    meIOIrqSetCallback - Error: %d    ****\n\n", i_me_error);

		printf("Press any key to terminate\n");

		(void)_getch();

		meClose(0);

		return -1;
	}

	//start interrupt function PIN48
	i_me_error = meIOIrqStart(gen_Device,							// Device index
		in_IrqSubDevice,							// Subdevice index
		in_IrqChannel,							// Channel index 	
		ME_IRQ_SOURCE_DIO_LINE,		// IRQ source
		ME_IRQ_EDGE_RISING,			// Type of signal edge
		ME_VALUE_NOT_USED,			// Additional argument - Not required here
		ME_IO_IRQ_START_NO_FLAGS);	// Flags

	if (i_me_error != ME_ERRNO_SUCCESS)
	{
		if (!SetEvent(ghExitEvent))
		{
			printf("%s: Error %d SetEvent()\n", MYNAME, GetLastError());
			bContinue = FALSE;
		}
		printf("****    meIOIrqStart - Error: %d    ****\n\n", i_me_error);

		printf("Press any key to terminate\n");

		(void)_getch();

		meClose(0);

		return 1;
	}

	//  Configure the output device

	i_me_error = meIOSingleConfig(gen_Device,				// Device index
		out_SubDevice,										// Subdevice index,
		out_Channel,										// Channel index
		ME_SINGLE_CONFIG_DIO_OUTPUT,						// Single config
		ME_VALUE_NOT_USED,									// Reference 
		ME_TRIG_CHAN_DEFAULT,								// Trigger channel
		ME_TRIG_TYPE_NONE,									// Trigger type
		ME_VALUE_NOT_USED,									// Trigger edge
		i_config_flags);	// Flags


	if (i_me_error != ME_ERRNO_SUCCESS)
	{
		if (!SetEvent(ghExitEvent))
		{
			printf("%s: Error %d SetEvent()\n", MYNAME, GetLastError());
			bContinue = FALSE;
		}
		printf("****    meIOSingleConfig - Error (output config): %d    ****\n\n", i_me_error);

		printf("Press any key to terminate\n");


		(void)_getch();

		meClose(0);

		return -1;
	}

	//Create output array
	meIOSingle_t io_single[1];

	io_single[0].iDevice = gen_Device;
	io_single[0].iSubdevice = out_SubDevice;
	io_single[0].iChannel = out_Channel;
	io_single[0].iDir = ME_DIR_OUTPUT;
	io_single[0].iValue = 0;
	io_single[0].iTimeOut = 0;							// No timeout - not required for software output
	io_single[0].iFlags = i_write_flags;


	// wait for StartProcessing command (raised by the ececution control) or the quit event (may be set by every participant):
	HANDLE ghEvents[] = { ghOutputEvent, ghExitEvent }; 
	int nNumEvents = sizeof(ghEvents) / sizeof(ghEvents[0]);

	printf("%s process is running.\n", MYNAME);
	printf("Press the ESC key at any time to stop this process\n");

	while (bContinue) {
		dwEvent = WaitForMultipleObjects(
			nNumEvents,	// number of objects to wait for
			ghEvents,	// array of objects to wait for
			FALSE,		// wait for any object ...
			2);	// ... timeout after 2 ms

		switch (dwEvent) // return value indicates, which event is signalled now
		{
		case WAIT_OBJECT_0 + 0: // OutputEvent
			//Set Output to high level
			io_single[0].iValue |= (1 << 0);
			i_me_error = meIOSingle(&io_single[0],				// Output list
				1,							// Number of elements in the above list
				ME_IO_SINGLE_NO_FLAGS);	// Flags

			if (i_me_error != ME_ERRNO_SUCCESS)
			{
				//printf("****    meIOSingle (output) - Error: %d    ****\n\n", i_me_error);

				//printf("Press any key to terminate\n");

				(void)_getch();

				meClose(0);

				return -1;
			}
			break;

		case WAIT_OBJECT_0 + 1: // ExitEvent
			printf("%s: I got the event %s!\n\n", MYNAME, "ExitEvent");
			bContinue = FALSE;
			break;

		case WAIT_TIMEOUT:
			// timeout after Set output low
			
			io_single[0].iValue &= ~(1 << 0); //Clear Bit 0 , for Bit 2 (1 << 2) etc...
			i_me_error = meIOSingle(&io_single[0],				// Output list
				1,							// Number of elements in the above list
				ME_IO_SINGLE_NO_FLAGS);	// Flags

			if (i_me_error != ME_ERRNO_SUCCESS)
			{
				if (!SetEvent(ghExitEvent))
				{
					printf("%s: Error %d SetEvent()\n", MYNAME, GetLastError());
					bContinue = FALSE;
				}
				printf("****    meIOSingle (output) - Error: %d    ****\n\n", i_me_error);

				printf("Press any key to terminate\n");

				(void)_getch();

				meClose(0);

				return -1;
			}
			break;
		default:
			// invalid return value: Error
			printf("%s: Wait error: %d\n", MYNAME, GetLastError());
			ExitProcess(0);
		}

		if (_kbhit() != 0)
		{
			if (_getch() == 27)
			{
				if (!SetEvent(ghExitEvent))
				{
					printf("%s: Error %d SetEvent()\n", MYNAME, GetLastError());
					bContinue = FALSE;
				}
				break;
			}
		}
	}

	printf("\n%s: Process stopped. Hit any key to close Window.\n", MYNAME);
	(void)_getch();

	//close callback funktion
	i_me_error = meIOIrqStop(0,							// Device index
		10, 						// Subdevice index
		0,							// Channel index 	
		ME_IO_IRQ_STOP_NO_FLAGS);	// Flags

	if (i_me_error != ME_ERRNO_SUCCESS)
	{
		//printf("****    meIOIrqStop - Error: %d    ****\n\n", i_me_error);

		//printf("Press any key to terminate\n");

		(void)_getch();

		meClose(0);

		return(-1);
	}

	//Close ME driver System
	meClose(0);

	ExitProcess(0);
}


//Callback function from ME driver

int _stdcall IrqCallback(int iDevice, int iSubdevice, int iChannel,
	int iIrqCount, int iValue, void* pvContext, int iErrorCode)
{
	if (iErrorCode == ME_ERRNO_SUCCESS)
	{
		//printf("Interrupt: IRQ Count: %d  Value: %d\n", iIrqCount, iValue);
		if (!SetEvent(ghInputEvent))
		{
			printf("%s: Error %d SetEvent()\n", MYNAME, GetLastError());
			bContinue = FALSE;
		}

	}
	else
	{
		if (!SetEvent(ghExitEvent))
		{
			printf("%s: Error %d SetEvent()\n", MYNAME, GetLastError());
			bContinue = FALSE;
		}
		printf("****    IrqCallback - Error: %d    ****\n\n", iErrorCode);
	}

	return(0);
}

