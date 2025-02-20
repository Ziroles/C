#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char chemin[256];

    while (1)
    {
        printf("Entrez le chemin du répertoire (ou 0 pour quitter) : ");
        fgets(chemin, sizeof(chemin), stdin);
        chemin[strcspn(chemin, "\n")] = 0;

        if (strcmp(chemin, "0") == 0)
        {
            printf("Programme terminé.\n");
            break;
        }

        char commande[300];
        snprintf(commande, sizeof(commande), "ls -l \"%s\"", chemin);

        int ret = system(commande);
        if (ret == -1)
        {
            perror("Erreur lors de l'exécution de la commande");
        }
    }

    return 0;
}
