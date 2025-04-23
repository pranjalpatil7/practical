#include <stdio.h>
#include <unistd.h> 

int main() 
{
    pid_t pid = fork(); 

    if (pid < 0) 
    {
        printf("Fork failed!\n");
        return 1;
    }

    if (pid == 0) 
    {
        printf("Child Process:\n");
        printf("PID (Child): %d\n", getpid());
        printf("PPID (Parent): %d\n", getppid());
    } 
    else 
    {
        printf("Parent Process:\n");
        printf("PID (Parent): %d\n", getpid());
        printf("Child PID: %d\n", pid);
    }

    return 0;
}
