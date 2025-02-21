#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

typedef struct
{
    unsigned long long min;
    unsigned long long max;
    double somme;
} intervalle;

void *sommeCarre(void *donnees)
{
    intervalle *inter = (intervalle *)donnees;
    for (unsigned long long i = inter->min; i <= inter->max; i++)
    {
        inter->somme += (double)i * i;
    }
    printf("Intervalle du thread : %10llu à %10llu -> %20g\n", inter->min, inter->max, inter->somme);
    return NULL;
}

int main()
{
    const int NB_THREADS = 8;
    const unsigned long N = 1e9;

    pthread_t ids[NB_THREADS];
    intervalle intervalles[NB_THREADS + 1];

    intervalles[0].min = 1;
    for (int i = 0; i < NB_THREADS; i++)
    {
        intervalles[i].max = (i + 1) * N / NB_THREADS;
        intervalles[i + 1].min = intervalles[i].max + 1;
        intervalles[i].somme = 0;
        if (pthread_create(&(ids[i]), NULL, sommeCarre, &(intervalles[i])))
        {
            printf("création de thread impossible\n");
            return 1;
        }
    }
    double somme = 0;
    for (int i = 0; i < NB_THREADS; i++)
    {
        pthread_join(ids[i], NULL);
        somme += intervalles[i].somme;
    }
    printf("Somme des carrés entre %9llu et %10llu : %20g\n", 1, N, somme);
    return 0;
}