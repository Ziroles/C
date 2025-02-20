#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>

int main() {
    int choix;
    do {
        printf("=== Menu ===\n1. Afficher le contenu du répertoire courant\n2. Créer un nouveau fichier vide\n3. Quitter\n");
        scanf(" %d", &choix);
        switch(choix) {
            case 1:
            case 2:
                pid_t pidc = fork();
                switch(pidc) {
                    case -1: printf("Désolé mais une erreur est survenue. L'action n'a pas pu être réalisée.\n"); break;
                    case 0 : //enfant
                        if(choix==1) {
                            execlp("ls", "ls", NULL);
                            printf("Désolé mais une erreur est survenue. L'action n'a pas pu être réalisée.\n");
                            exit(1);
                        } else {
                            char parametre[256];
                            printf("Nom du fichier à créer ?\n");
                            scanf(" %s", parametre);
                            execlp("touch", "touch", parametre, NULL);
                            printf("Désolé mais une erreur est survenue. L'action n'a pas pu être réalisée.\n");
                            exit(1);
                        }
                        break;
                    default: // parent
                        wait(NULL);
                        break;
                }
                break;
            case 3: break;
            default:
                printf("Saisie incorrecte\n");
                break;
        }
    } while(choix != 3);
    return 0;
}