#include<stdio.h>
#include<signal.h>
#include <time.h>

int temps = 0;
int debut;
char enPause = 0;

void ecouteSignal(int numSignal, void* gestionnaire) {
    struct sigaction act;
    act.sa_handler = gestionnaire;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(numSignal, &act, NULL);
}

void raz(int numSignal) {
    temps += time(NULL) - debut;
    printf("\n%d -> à la fin\n", temps);
    temps = 0;
    debut = time(NULL);
    printf("0 -> c'est repartit...\n");
}

void pause(int numSignal) {
    if(!enPause) {
        temps += time(NULL) - debut;
        printf("\n%d -> en pause\n", temps);
    } else {
        debut = time(NULL);
        printf("\n%d -> c'est repartit...\n", temps);
    }
    enPause = !enPause;
}

int main() {
    ecouteSignal(SIGINT, &raz);
    ecouteSignal(SIGTSTP, &pause);
    debut = time(NULL);
    char c;
    do {
        scanf(" %c", &c);
    } while(c!='q');
    return 0;
}