#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage : %s nom_fichier\n", argv[0]);
        return 1;
    }
    int fd = open(argv[1], O_RDONLY);
    if(fd==-1) {
        perror("open :");
        return errno;
    }
    const int MAX = 10;
    int nbLu, total=0;
    char buffer[MAX+1];
    while(nbLu = read(fd, buffer, MAX)) {
        total += nbLu;
    }
    printf("total = %d\n", total);
    return 0;
}