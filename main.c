#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>

int main() 
{   
    int n = 2;
    printf("PID: %d, forking off %d child processes\n", getpid(), n);
    int f = 1;
    srand(time(NULL));

    for (int i = 0; i < n; ++i) // create the children
    {
        if (f = fork())
        {
            rand(); // to make sure the children don't all get the first rand() value
        } 
        else
        {
            break;
        }
    }
    if(f)
    {   
        int status;
        int pid = wait(&status);
        printf("child with PID: %d slept for %d seconds and is now finished\n", pid, WEXITSTATUS(status));
        printf("The other one might still be running but I'm done, bye\n");
        return 0;
    }
    if (!f) 
    {
        printf("child with PID: %d going to sleep\n", getpid());
        int s = rand() % 9 + 2;
        sleep(s);
        printf("child with PID: %d is finished\n", getpid());
        return s;
    }
    
}
        

