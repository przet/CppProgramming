#include <stdio.h>
#include <thread>
#include <assert.h>

void CPU_Waster(int* pid, std::thread::id* tid)
{
    
    printf("CPU Waster Process ID: %d\n", _getpid());
    printf("CPU Waster Thread ID: %d\n", std::this_thread::get_id());
    *pid = _getpid();
    *tid = std::this_thread::get_id();
}

int main()
{
    int main_process_pid = _getpid();
    std::thread::id main_tid = std::this_thread::get_id();
    printf("Main Process ID: %d\n", main_process_pid);
    printf("Main Thread ID: %d\n", main_tid);
    
    int cpu_waster_pid = 0;
    std::thread::id cpu_waster_tid;
    CPU_Waster(&cpu_waster_pid, &cpu_waster_tid);

    assert(cpu_waster_pid == main_process_pid);
    assert(cpu_waster_tid == main_tid);
    
    
    return 0;
}
