#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void timer(pid_t parent_pid)
{
    int time = 5;
    while (time > 0)
    {
        sleep(1);
        time--;
    }
    // La fonction est de type void, on ne retourne pas de valeur
    return;
}

int askQuestion()
{
    int score = 0, reponse;
    int NB_QUESTIONS = 3;
    for (int i = 0; i < NB_QUESTIONS; i++)
    {
        printf("\nQuestion %d\nQuel est le résultat de 2 + 2 ?\n", i + 1);
        if (scanf("%d", &reponse) != 1)
        {
            while (getchar() != '\n')
                ;
            continue;
        }
        if (reponse == 4)
            score++;
    }
    return score;
}

int main()
{
    pid_t pid1, pid2, winner;
    int status;

    pid1 = fork();
    if (pid1 == 0)
    {

        timer(getppid());
        return 0;
    }

    pid2 = fork();
    if (pid2 == 0)
    {

        askQuestion();
        return 0;
    }

    winner = wait(&status);

    if (winner == pid1)
    {
        printf("\nChrono terminé perdu\n");
    }
    else if (winner == pid2)
    {
        printf("\nBravo\n");
    }

    return 0;
}
