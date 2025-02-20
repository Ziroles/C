#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<semaphore.h>
#include<unistd.h>

const int MAX = 100;

int main() {
    const char* FILS = "/fils";
    const char* PERE = "/pere";
    sem_t* semFilsActif = sem_open(FILS, O_RDWR|O_CREAT|O_EXCL, 0666, 1); // ouvert
    sem_t* semPereActif = sem_open(PERE, O_RDWR|O_CREAT|O_EXCL, 0666, 0); // fermé
    if(semFilsActif == SEM_FAILED || semPereActif == SEM_FAILED) { perror("sem_open"); return 1; }
    pid_t p = fork();
    switch(p) {
        case -1:
            printf("Version dégradée à un seul processus...\n");
            for(int i=1; i<=MAX; i++) {
                printf("%d\n", i);
            }
            break;
        case 0 : // fils
            for(int i=1; i<=MAX; i+=2) {
                sem_wait(semFilsActif);
                printf("fils : %d\n", i);
                sem_post(semPereActif);
            }
            break;
        default : // père
            for(int i=2; i<=MAX; i+=2) {
                sem_wait(semPereActif);
                printf("père : %d\n", i);
                sem_post(semFilsActif);
            }
            break;
    }
    sem_close(semFilsActif);
    sem_close(semPereActif);
    sem_unlink(FILS);
    sem_unlink(PERE);
    return 0;
}