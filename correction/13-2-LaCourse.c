#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
    pid_t pid1, pid2;
    switch(pid1 = fork()) {
        case -1 : printf("Erreur impossible de créer un processus...\n"); return 1;
        case 0 : // enfant 1
            sleep(1);
            for(int i=0; i<1000; i++) {
                printf(".\n");
            }
            break;
        default : // parent
            switch(pid2 = fork()) {
                case -1 : printf("Erreur impossible de créer un processus...\n"); return 1;
                case 0 : // enfant 2
                    sleep(1);
                    for(int i=0; i<1000; i++) {
                        printf("#\n");
                    }
                    break;
                default : // parent
                    pid_t premier = wait(NULL);
                    pid_t second = wait(NULL);
                    printf("le processus %d a gagné (enfant %d)\n", premier, premier==pid1?1:2);
                    break;
            }
            break;
    }
    return 0;
}
