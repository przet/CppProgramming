#include <stdio.h>
#include <thread>
#include <assert.h>

void CPU_Waster(int* pid)
{
    
    printf("CPU Waster Process ID: %d\n", _getpid());
    *pid = _getpid();


}

int main()
{
    int main_process_pid = _getpid();
    printf("Main Process ID: %d\n", main_process_pid);
    
    int cpu_waster_pid = 0;
    CPU_Waster(&cpu_waster_pid);
    assert(cpu_waster_pid == main_process_pid);
    return 0;
}
