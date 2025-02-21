#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const char* CHEMIN = "/thermometre";
    const char FIN = -128;
    const size_t TAILLE = sizeof(char);

    int mem = shm_open(CHEMIN, O_CREAT|O_RDWR, 0666);
    if(mem==-1) {perror("shm_open"); return 1; }
    if(ftruncate(mem, TAILLE) == -1) { perror("ftruncate"); return 2; }

    char* pTemperature = mmap(NULL, TAILLE, PROT_WRITE, MAP_SHARED, mem, 0);
    if(pTemperature == MAP_FAILED) { perror("mmap"); return 3; }
    
    srand(time(NULL));
    *pTemperature = 19;
    for(int i=0; i<100; i++) {
        sleep(1);
        *pTemperature += rand()%5-2;
        printf("prod : %hhd\n", *pTemperature);
    }
    sleep(1);
    *pTemperature = FIN;
    munmap(pTemperature, TAILLE);
    close(mem);
    shm_unlink(CHEMIN);
    return 0;
}