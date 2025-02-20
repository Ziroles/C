#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
    pid_t pid1, pid2;
    switch(pid1 = fork()) {
        case -1 : printf("Erreur impossible de créer un processus...\n"); return 1;
        case 0 : // enfant
            printf("Je suis ton fils\n");
            break;
        default : // parent
            printf("Je suis ton père\n");
            sleep(1);
            break;
    }
    return 0;
}
