#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
    pid_t pid1, pid2;
    char chemin[1024];
    printf("chemin d'accès au répertoire ?\n");
    scanf(" %s", chemin);
    do {
        switch(pid1 = fork()) {
            case -1 : printf("Erreur impossible de créer un processus...\n"); return 1;
            case 0 : // enfant
                execlp("ls", "ls", chemin);
                break;
            default : // parent
                wait(NULL);
                break;
        }
        printf("chemin d'accès au répertoire ou q pour quitter ?\n");
        scanf(" %s", chemin);
    } while(chemin[0]!='q' || chemin[1]!='\0');
    return 0;
}
