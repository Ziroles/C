#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<signal.h>

#define BON 1
#define FAUX -1
#define HORS_DELAIS 0

int timeout;

void finTemps(int numSignal) {
    timeout = 1;
}

void ecouteSignal(int numSignal, void* gestionnaire) {
    struct sigaction act;
    act.sa_handler = gestionnaire;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(numSignal, &act, NULL);
}

int questionLimiteTemps(const char* question, const char* reponseAttendue, int tpsSecondes) {
    timeout = 0;
    pid_t pidc = fork();
    switch(pidc) {
        case -1 : printf("Désolé mais un problème est survenu...\n"); return 1;
        case 0 : // enfant
            sleep(tpsSecondes);
            kill(getppid(), SIGALRM);
            exit(0);
            break;
        default : // parent
            ecouteSignal(SIGALRM, finTemps);
            char reponseDonnee[1000];
            printf("%s\n", question);
            scanf(" %s", reponseDonnee);
            if(timeout == 0) {
                kill(pidc, SIGINT);
                if(strcmp(reponseDonnee, reponseAttendue)) {
                    printf("Faux ! La réponse attendu est \"%s\"\n", reponseAttendue);
                    return FAUX;
                } else {
                    printf("Bravo !\n");
                    return BON;
                }
            } else {
                printf("Trop tard !\n");
                return HORS_DELAIS;
            }
    }
}

int main() {
    int points = 0;
    points += questionLimiteTemps("Quelle est la couleur du cheval blanc d'Henri IV ?", "blanc", 10);
    points += questionLimiteTemps("Quelle est la valeur décimale correspondant à la hexadécimale FF ?", "255", 10);
    points += questionLimiteTemps("Combien de valeurs différentes sont codables avec 1 octets?", "256", 10);
    printf("Vous avez %d points\n", points);
    return 0;
}
