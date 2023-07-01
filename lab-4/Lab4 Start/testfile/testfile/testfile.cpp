// testfile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
     The SetProcessAffinityMask is inherted to any child process (and threads).
     The SetThreadAffinityMask in threads will be overwritten by this call.
     REALTIME_PRIORITY_CLASS 0x00000100
     HIGH_PRIORITY_CLASS 0x00000080
     ABOVE_NORMAL_PRIORITY_CLASS 0x00008000
     NORMAL_PRIORITY_CLASS 0x00000020
     BELOW_NORMAL_PRIORITY_CLASS 0x00004000
     IDLE_PRIORITY_CLASS 0x00000040
     PROCESS_MODE_BACKGROUND_BEGIN 0x00100000
     PROCESS_MODE_BACKGROUND_END 0x00200000
 */

/*   15
     THREAD_PRIORITY_TIME_CRITICAL, Base priority of 15 for IDLE_PRIORITY_CLASS, BELOW_NORMAL_PRIORITY_CLASS, NORMAL_PRIORITY_CLASS, ABOVE_NORMAL_PRIORITY_CLASS, or HIGH_PRIORITY_CLASS processes, and a base priority of 31 for REALTIME_PRIORITY_CLASS processes.
     2
     THREAD_PRIORITY_HIGHEST, Priority 2 points above the priority class.
     1
     THREAD_PRIORITY_ABOVE_NORMAL, Priority 1 point above the priority class.
     0
     THREAD_PRIORITY_NORMAL, Normal priority for the priority class.
     - 1
     THREAD_PRIORITY_BELOW_NORMAL, Priority 1 point below the priority class.
     - 2
     THREAD_PRIORITY_LOWEST, Priority 2 points below the priority class.
     - 15
     THREAD_PRIORITY_IDLE, Base priority of 1 for IDLE_PRIORITY_CLASS, BELOW_NORMAL_PRIORITY_CLASS, NORMAL_PRIORITY_CLASS, ABOVE_NORMAL_PRIORITY_CLASS, or HIGH_PRIORITY_CLASS processes, and a base priority of 16 for REALTIME_PRIORITY_CLASS processes.
 */

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
    ...

    console_out.lock();
    std::cout << "Thread ID: " << ... << " created. Running on processor #" << ... << " with priority " << ... << std::endl;
    console_out.unlock();
    //set cpu und priority
    ...
    console_out.lock();
    std::cout << "Thread ID: " << ... << " now running on processor #" << ... << " with mask value: " << ... << " with priority " << ... << std::endl;
   console_out.unlock();

    unsigned long long i = 5;
    volatile int vi = 0;
    //processing till quit flag is raised...
    while (!quit_flag) {
        vi = i % 2;
    }
    
}

int main()
{
    std::atomic<bool> quit_flag(false);

    //handles for process and threads
    ... 

    //set main thread on core#3
    ...
    //set priority
    ...

    std::cout << "Process ID: " << ... << " created. Runnig on processor #" << ... << " with process priority: 0x" << std::hex << ... << std::dec << std::endl;
    
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

 