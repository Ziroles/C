#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char* CHEMIN = "/thermometre";
    const char FIN = -128;
    const size_t TAILLE = sizeof(char);
    int mem = shm_open(CHEMIN, O_RDONLY, 0666);
    if(mem==-1) {perror("shm_open : "); return 1; }
    char* ptemp = mmap(NULL, TAILLE, PROT_READ, MAP_SHARED, mem, 0);
    if(ptemp == MAP_FAILED) { perror("mmap : "); return 3; }
    while(*ptemp!=FIN) {
        printf("récup : %hhd\n", *ptemp);
        sleep(5);
    }
    munmap(ptemp, TAILLE);
    close(mem);
    return 0;
}