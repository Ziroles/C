#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>

/*
Réaliser un programme permettant de réaliser une addition entre deux matrices. Le calcul de
chaque valeur de la matrice résultat est effectué par un processus différent.
*/

int main()
{
    const char *CHEMIN = "/thermometre";                // Nom de la mémoire partagée
    const size_t TAILLE = sizeof(int) * 12;             // Taille de la mémoire que l'ont veut allouer
    int mem = shm_open(CHEMIN, O_CREAT | O_RDWR, 0666); // création mémoire partager
    if (ftruncate(mem, TAILLE) == -1)
    {
        perror("ftruncate");
        return 2;
    }
    int *matrice1 = mmap(NULL, TAILLE, PROT_WRITE, MAP_SHARED, mem, 0);
    int *matrice2 = matrice1 + sizeof(int) * 4;
    int *matrice3 = matrice1 + sizeof(int) * 8;

    pid_t pid1 = fork();
    pid_t pid2 = fork();
    srand(time(NULL));
    for (int i = 0; i < 4; i++)
    {
        matrice1[i] = rand() % 201 - 100;
        matrice2[i] = rand() % 201 - 100;
    }

    if (pid1 == 0)
    {
        if (pid2 == 0)
        {
            matrice3[2] = matrice1[2] + matrice2[2];
        }
        else
        {
            matrice3[0] = matrice1[0] + matrice2[0];
        }
    }
    else
    {
        if (pid2 == 0)
        {
            matrice3[1] = matrice1[1] + matrice2[1];
        }
        else
        {
            matrice3[3] = matrice1[3] + matrice2[3];
            wait(NULL);
            printf("%d %d + %d %d = %d %d\n", matrice1[0], matrice1[1], matrice2[0], matrice2[1], matrice3[0], matrice3[1]);
            printf("%d %d + %d %d = %d %d\n", matrice1[2], matrice1[3], matrice2[2], matrice2[3], matrice3[2], matrice3[3]);
            munmap(matrice1, TAILLE);
            munmap(matrice2, TAILLE);
            munmap(matrice3, TAILLE);
            close(mem);
            shm_unlink(CHEMIN);
        }
    }
}