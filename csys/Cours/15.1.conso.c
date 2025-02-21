#include <sys/mman.h>
#include <sys/stat.h> /* For mode constants */
#include <fcntl.h>    /* For O_* constants */
#include <unistd.h>
#include <stdio.h>
/*
Toutes les secondes, un processus renseigne la température actuelle dans une zone de mémoire
partagée. Comme nous n’avons pas accès à un véritable capteur, les valeurs sont en réalité des
valeurs pseudo aléatoires. Au terme de 100 valeurs, une valeur particulière est positionnée dans la
mémoire partagée afin d’indiquer que le capteur a terminé ses mesures.
Un autre processus lit dans la mémoire partagée la température toutes les 5 secondes. Il l’affiche
sur la console.
*/

int main()
{
    const char *CHEMIN = "/thermometre"; // Nom de la mémoire partagée
    const size_t TAILLE = sizeof(char);
    int mem = shm_open(CHEMIN, O_RDONLY, 0666);                      // création mémoire partager
    char *ptemp = mmap(NULL, TAILLE, PROT_READ, MAP_SHARED, mem, 0); // Mappage de la mémoire partagée

    while (1)
    {
        printf("récup : %hhd\n", *ptemp);
    }

    *ptemp = -10;
    munmap(ptemp, TAILLE);
    close(mem);
    shm_unlink(CHEMIN);
}
