#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void print_chars(char c, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%c", c);
        fflush(stdout); 
    }
}

int main()
{
    pid_t pid1, pid2, winner;
    int status;

    pid1 = fork();

    if (pid1 == 0)
    {
        print_chars('A', 1000);
        return 0;
    }

    pid2 = fork();

    if (pid2 == 0)
    {
        print_chars('B', 1000);
        return 0;
    }

    winner = wait(&status);

    printf("\nLe processus %d a gagné !\n", winner);

    wait(NULL);

    return 0;
}
