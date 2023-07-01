

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <chrono>
#include <cstdint>
#include <thread>
#include <Windows.h>
#include <WinBase.h>
#include <mutex>
#include <processthreadsapi.h>


std::mutex console_out;

void long_operation(std::atomic<bool>& quit_flag, int core, int nPriority)
{
    //handles for process and threads
    HANDLE hProcess = GetCurrentProcess();
    HANDLE hThread = GetCurrentThread();
    console_out.lock();
    //std::cout << "Thread ID: " << ... << " created. Running on processor #" << ... << " with priority " << ... << std::endl;
    std::cout << "Thread ID: " << GetCurrentThreadId() << " created. Running on processor #" << core << " with priority " << nPriority << std::endl;
    console_out.unlock();
    //set cpu und priority
    // Set the process affinity mask
    DWORD processAffinityMask = 0x00000001 << core; // Run on the first processor by default
    if (!SetProcessAffinityMask(hProcess, processAffinityMask))
    {
        printf("Failed to set process affinity mask. Error code: %d\n", GetLastError());
    }
    // Set the thread priority
    int threadPriority = nPriority;
    if (!SetThreadPriority(hThread, threadPriority))
    {
        printf("Failed to set thread priority. Error code: %d\n", GetLastError());
    }
    //get current settings
    int processid = GetCurrentProcessId();
    int threadid = GetCurrentThreadId();
    int processornum = GetCurrentProcessorNumber();
    DWORD ppriority = GetPriorityClass(hProcess);
    int tpriority = GetThreadPriority(hThread);

    console_out.lock();
    //std::cout << "Thread ID: " << ... << " now running on processor #" << ... << " with mask value: " << ... << " with priority " << ... << std::endl;
    std::cout << "Thread ID: " << threadid << " now running on processor #" << processornum << " with mask value: " << processAffinityMask << " with priority " << tpriority << std::endl;
    console_out.unlock();

    unsigned long long i = 5;
    volatile int vi = 0;
    //processing till quit flag is raised...
    while (!quit_flag) {
        vi = i % 2;
    }
    
}

#define MYNAME "test proccess"

int main()
{
    std::atomic<bool> quit_flag(false);

    //handles for process and threads
    HANDLE hProcess = GetCurrentProcess();
    HANDLE hThread = GetCurrentThread();

    //set main thread on core 3 with priority 0
    // Set the process affinity mask
    DWORD processAffinityMask = 0x00000001; // Run on the first processor by default
    if (!SetProcessAffinityMask(hProcess, processAffinityMask))
    {
        printf("%s: Failed to set process affinity mask. Error code: %d\n", MYNAME, GetLastError());
    }
    // Set the thread priority
    int threadPriority = THREAD_PRIORITY_ABOVE_NORMAL;
    if (!SetThreadPriority(hThread, threadPriority))
    {
        printf("%s: Failed to set thread priority. Error code: %d\n", MYNAME, GetLastError());
    }

    int processid = GetCurrentProcessId();
    int threadid = GetCurrentThreadId();
    int processornum = GetCurrentProcessorNumber();
    DWORD ppriority = GetPriorityClass(hProcess);
    int tpriority = GetThreadPriority(hThread);

    std::cout << "Process ID: " << processid << "\nThread ID: " << threadid << "\nNow running on processor #" << processornum
        << "\nWith process priority class 0x" << std::hex << ppriority << "\nWith thread priority " << tpriority << std::dec << std::endl;

    
    std::cout << "Press any key to start calculation" << std::endl;
    (void)_getch();
    //program running until ESC
    std::cout << "Press any key at any time to stop the program." << std::endl;
    
    //start x amount of threads
    std::thread t1(long_operation, std::ref(quit_flag),1,0);  //#1 = processor 0
    std::thread t2(long_operation, std::ref(quit_flag),2,0);  //#2 = processor 1
    std::thread t3(long_operation, std::ref(quit_flag),4,0);  //#3 = processor 2
    std::thread t4(long_operation, std::ref(quit_flag),8,0);  //#4 = processor 3

    //wating for keyboard hit to avoid unneccessary use of recources 
    (void)_getch();
    printf("Program stopped.\nClosing Threads...\n");
    quit_flag = true;
    //wait for threads being closed
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}
