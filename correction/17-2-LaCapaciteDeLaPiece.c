#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int nbPersonnes = 0;
pthread_mutex_t mutex_cpt;

const int CAPACITE = 10;

void* porte(void* donnees) {
    char nomPorte = *(char*)donnees;
    int nbP;
    for(int i=0; i<10; i++) {
        pthread_mutex_lock(&mutex_cpt);
        if(rand()%2) {
            nbP = rand()%5+1;
            if(nbPersonnes + nbP <= CAPACITE) {
                nbPersonnes += nbP;
                printf("Entrée de %d personne%s par la porte %c -> total : %d\n", nbP, nbP>1?"s":"", nomPorte, nbPersonnes);
            } else {
                printf("%1$d personne%2$s bloquée%2$s à la porte %3$c\n", nbP, nbP>1?"s":"", nomPorte);
            }
        } else {
            if(nbPersonnes>0) {
                nbP = nbPersonnes==1?1:rand()%(nbPersonnes-1)+1;
                nbPersonnes -= nbP;
                printf("Sortie de %d personne%s par la porte %c -> total : %d\n", nbP, nbP>1?"s":"", nomPorte, nbPersonnes);
            }
        }
        pthread_mutex_unlock(&mutex_cpt);
        sleep(rand()%3);
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    const int NB_PORTES = 4;

    pthread_mutex_init(&mutex_cpt, NULL);

    pthread_t ids[NB_PORTES];
    char lettresPortes[NB_PORTES];
    for(int i=0; i<NB_PORTES; i++) {
        lettresPortes[i] = 'A' + i;
        if(pthread_create(&(ids[i]), NULL, porte, &(lettresPortes[i]))) {
            printf("création de thread impossible\n");
            return 1;
        }
    }
    double somme = 0;
    for(int i=0; i<NB_PORTES; i++) {
        pthread_join(ids[i], NULL);
    }
    return 0;
}