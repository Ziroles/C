#include <semaphore.h>
#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

typedef struct
{
    unsigned long long min;
    unsigned long long max;
    double somme;
} intervalle;
void *clckre(void *data)
{
    intervalle *inter = (intervalle *)data;
    for (long i = inter->min; i <= inter->max; i++)
    {

        inter->somme += i * i;
    }
    printf("Intervalle du thread : %10llu à %10llu -> %20g\n ", inter->min, inter->max, inter->somme);
    return NULL;
}
int main()
{
    long nombre;
    printf("Entrer un nombre");
    scanf(" %ld", &nombre);

    pthread_t ths[8];
    double res = 0;
    int interval = nombre / 8;
    intervalle inters[8];
    for (int i = 0; i < 8; i++)
    {

        inters[i].min = interval * i + 1;
        inters[i].max = interval * (i + 1);
        inters[i].somme = 0;
        if (pthread_create(&(ths[i]), NULL, &clckre, &inters[i]))
        {
            printf("création de thread impossible\n");
            return 1;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        pthread_join(ths[i], NULL);
        res += inters[i].somme;
    }

    printf(" %lf", res);
    return 0;
}