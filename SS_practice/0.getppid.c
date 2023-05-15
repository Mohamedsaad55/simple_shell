#include <stdio.h>
#include <unistd.h>

/**
 * PID
 *
 * Returns always 0
 */


int main(void) {
	
    pid_t parent_pid = getppid();
    pid_t my_pid = getpid();
    printf("Parent PID: %d\n", parent_pid);
    printf("PID %u\n",my_pid);
    return 0;
}
