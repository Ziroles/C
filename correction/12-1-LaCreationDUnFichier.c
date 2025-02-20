#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

char choixOuiOuNon(char* const message) {
    printf("%s (o/n)\n", message);
    char rep;
    scanf(" %c", &rep);
    return rep == 'o';
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage : %s nom_fichier\n", argv[0]);
        return 1;
    }
    umask(0);
    int droits = 0;
    printf(" - Droits en lecture\n");
    if(choixOuiOuNon("pour vous ?")) droits|=S_IRUSR;
    if(choixOuiOuNon("pour votre groupe ?")) droits|=S_IRGRP;
    if(choixOuiOuNon("pour les autres ?")) droits|=S_IROTH;
    printf(" - Droits en écriture\n");
    if(choixOuiOuNon("pour vous ?")) droits|=S_IWUSR;
    if(choixOuiOuNon("pour votre groupe ?")) droits|=S_IWGRP;
    if(choixOuiOuNon("pour les autres ?")) droits|=S_IWOTH;
    printf(" - Droits en exécution\n");
    if(choixOuiOuNon("pour vous ?")) droits|=S_IXUSR;
    if(choixOuiOuNon("pour votre groupe ?")) droits|=S_IXGRP;
    if(choixOuiOuNon("pour les autres ?")) droits|=S_IXOTH;
    int fd = open(argv[1], O_WRONLY|O_CREAT|O_EXCL, droits); 
    if(fd == -1) { 
        perror("Open "); 
        return errno; 
    }
    write(fd, "#!/bin/bash\n", 12);
    write(fd, "echo \"Hello World!\"", 19);
    close(fd);
    return 0; 
}