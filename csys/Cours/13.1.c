#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t pidc = fork();
    switch (pidc)
    {
    case -1:
        printf("erreur le fork n'a pu avoir lieu...");
        break;
    case 0:
        printf("enfant : %d %d %d\n", pidc, getpid(), getppid());
        break;
    default:
        printf("père : %d %d %d\n", pidc, getpid(), getppid());
        sleep(1);
        break;
    }
    return 0;
}