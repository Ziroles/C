#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void timer(pid_t parent_pid, int *stop, int *time)
{

    while (1)
    {
        while (*stop == 0)
        {
            sleep(1);
            time--;
            return;
        }
    }
    return;
}

handle_sigtstp(int *sig, int *time)
{

    *sig = 1;

    printf("Signal SIGTSTP reçu time = %d\n", *time);
    return;
}
int main()
{
    int time = 0;
    int stop = 0;
    signal(SIGTSTP, handle_sigtstp(&stop, &time));
    pid_t pid1;

    pid1 = fork();
    if (pid1 == 0)
    {

        timer(getppid(), &stop, &time);
        return 0;
    }

    return 0;
}
