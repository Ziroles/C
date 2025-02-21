#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
int stop = 0;
int time = 0;
void timer()
{

    while (1)
    {
        if (stop == 0)
        {
            sleep(1);
            printf("time = %d\n", time);
            time++;
        }
    }
}

void handle_sigtstp(int signal)
{
    stop = stop == 0;
    printf("Signal SIGTSTP reçu %d , time = %d\n ", signal, time);
    return;
}
int main()
{

    signal(SIGTSTP, handle_sigtstp);
    pid_t pid1;

    pid1 = fork();
    if (pid1 == 0)
    {

        timer();
    }
    wait(NULL);
    return 0;
}
