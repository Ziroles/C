#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>

int main() {
    const char* CHEMIN = "/matrices";
    const size_t TAILLE = sizeof(int)*12;
    int mem = shm_open(CHEMIN, O_CREAT|O_RDWR, 0666);
    if(mem==-1) {perror("shm_open"); return 1; }
    if(ftruncate(mem, TAILLE) == -1) { perror("ftruncate"); return 2; }
    int* matrice1 = mmap(NULL, TAILLE, PROT_WRITE, MAP_SHARED, mem, 0);
    int* matrice2 = matrice1 + sizeof(int)*4;
    int* matriceRes = matrice1 + sizeof(int)*8;
    if(matrice1 == MAP_FAILED || matrice2 == MAP_FAILED || matriceRes == MAP_FAILED) { perror("mmap"); return 3; }

    srand(time(NULL));
    for(int k=0; k<4; k++) {
        matrice1[k] = rand()%201-100;
        matrice2[k] = rand()%201-100;
    }

    pid_t p1 = fork();
    pid_t p2 = fork();
    if(p1 == -1 || p2 == -1) { perror("fork"); return 4; }
    if(p1 == 0) {
        if(p2 == 0) {
            matriceRes[0] = matrice1[0]+matrice2[0];
        } else {
            matriceRes[1] = matrice1[1]+matrice2[1];
            wait(NULL);
        }
    } else {
        if(p2 == 0) {
            matriceRes[2] = matrice1[2]+matrice2[2];
        } else {
            matriceRes[3] = matrice1[3]+matrice2[3];
            wait(NULL);
            wait(NULL);
            printf("| %4d %4d |   | %4d %4d |   | %4d %4d |\n", matrice1[0], matrice1[1], matrice2[0], matrice2[1], matriceRes[0], matriceRes[1]);
            printf("| %4d %4d | + | %4d %4d | = | %4d %4d |\n", matrice1[2], matrice1[3], matrice2[2], matrice2[3], matriceRes[2], matriceRes[3]);
            munmap(matrice1, sizeof(int)*4);
            munmap(matrice2, sizeof(int)*4);
            munmap(matriceRes, sizeof(int)*4);
            close(mem);
            shm_unlink(CHEMIN);
        }
    }
    return 0;
}