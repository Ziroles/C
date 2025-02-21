#include <semaphore.h>
#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>

int main()
{
    const char *PERE = "/pere"; // Nom de la mémoire partagée
    const char *FILS = "/fils"; // Nom de la mémoire partagée

    sem_t *semPERE = sem_open(PERE, O_CREAT, 0666, 1);
    sem_t *semFILS = sem_open(FILS, O_CREAT, 0666, 0);

    pid_t pid1 = fork();

    if (pid1 == 0)
    {
        for (int i = 0; i < 100; i += 2)
        {
            sem_wait(semPERE);
            printf("PERE %d \n", i);
            sem_post(semFILS);
        }
    }
    else
    {
        for (int i = 1; i < 101; i += 2)
        {
            sem_wait(semFILS);
            printf("FILS %d \n", i);
            sem_post(semPERE);
        }
    }

    wait(NULL);
    sem_close(semPERE);
    sem_close(semFILS);
    shm_unlink(PERE);
    shm_unlink(FILS);
    return 0;
}
