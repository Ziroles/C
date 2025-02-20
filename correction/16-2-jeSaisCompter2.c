#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<semaphore.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

const int MAX = 100;
const char VAL = 0;
const char TEMPS = 1;

const char TEMPS_MAX_FILS = 4;
const char ATTENTE_PERE = 3;

int main() {
    const char* SEMA = "/compte";
    sem_t* semActif = sem_open(SEMA, O_RDWR|O_CREAT|O_EXCL, 0666, 1); // ouvert
    if(semActif == SEM_FAILED) { perror("sem_open"); return 1; }

    const char* MEMP = "/memoirePartagee";
    const size_t TAILLE = sizeof(int)*2;
    int fdMem = shm_open(MEMP, O_CREAT|O_RDWR, 0666);
    if(fdMem==-1) { perror("shm_open"); return 2; }
    if(ftruncate(fdMem, TAILLE)==-1) { perror("ftruncate"); return 3; }
    int* tab = mmap(NULL, TAILLE, PROT_WRITE, MAP_SHARED, fdMem, 0);
    if(tab == MAP_FAILED) { perror("mmap"); return 4; }

    tab[VAL] = 0;
    tab[TEMPS] = time(NULL);

    pid_t p = fork();
    switch(p) {
        case -1:
            printf("Version dégradée à un seul processus...\n");
            for(int i=1; i<=MAX; i++) {
                printf("%d\n", i);
            }
            break;
        case 0 : // fils
            srand(time(NULL));
            int i=0;
            do {
                sleep(rand()%TEMPS_MAX_FILS);
                sem_wait(semActif);
                i = ++tab[VAL];
                if(i<=MAX) {
                    printf("fils : %d\n", i);
                }
                tab[TEMPS] = time(NULL);
                sem_post(semActif);
            } while(i<MAX);
            break;
        default : // père
            int tempsAttente=ATTENTE_PERE, valeur=0;
            do {
                sleep(tempsAttente);
                sem_wait(semActif);
                if(valeur == tab[VAL]) {
                    valeur = ++tab[VAL];
                    printf("père : %d\n", valeur);
                    tab[TEMPS] = time(NULL);
                } else {
                    valeur = tab[VAL];
                }
                tempsAttente = 3 - (time(NULL) - tab[TEMPS]);
                sem_post(semActif);
            } while(valeur<MAX);
            break;
    }
    sem_close(semActif);
    sem_unlink(SEMA);
    return 0;
}