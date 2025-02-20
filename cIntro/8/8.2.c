#include <stdio.h>

#define SIZE 7  // Taille du tableau, avec un espace vide au centre

// Fonction pour afficher l'état du tableau
void afficherPlateau(char plateau[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%c ", plateau[i]);
    }
    printf("\n");
}

// Fonction pour vérifier si un mouvement est valide
int mouvementValide(char plateau[], int indexSource, int indexDestination) {
    if (indexDestination < 0 || indexDestination >= SIZE) {
        return 0;  // Destination hors du tableau
    }
    if (plateau[indexDestination] != ' ') {
        return 0;  // La destination doit être vide
    }
    if (plateau[indexSource] == '>') {
        return (indexDestination == indexSource + 1 || indexDestination == indexSource + 2);
    } else if (plateau[indexSource] == '<') {
        return (indexDestination == indexSource - 1 || indexDestination == indexSource - 2);
    }
    return 0;  // Mouvement non valide
}

// Fonction pour déplacer un mouton
void deplacer(char plateau[], int indexSource, int indexDestination) {
    plateau[indexDestination] = plateau[indexSource];
    plateau[indexSource] = ' ';
}

// Fonction pour vérifier si le jeu est terminé
int jeuTermine(char plateau[]) {
    for (int i = 0; i < SIZE / 2; i++) {
        if (plateau[i] != '<') {
            return 0;
        }
    }
    for (int i = SIZE / 2 + 1; i < SIZE; i++) {
        if (plateau[i] != '>') {
            return 0;
        }
    }
    return 1;
}

int main() {
    char plateau[SIZE] = {'>', '>', '>', ' ', '<', '<', '<'};  // Plateau initial
    int source, destination;

    printf("Bienvenue dans le jeu du saut de moutons !\n");

    while (!jeuTermine(plateau)) {
        afficherPlateau(plateau);

        // Saisie utilisateur
        printf("Entrez l'index du pion à déplacer : ");
        scanf("%d", &source);
        printf("Entrez l'index de la destination : ");
        scanf("%d", &destination);

        if (mouvementValide(plateau, source, destination)) {
            deplacer(plateau, source, destination);
        } else {
            printf("Mouvement invalide. Essayez à nouveau.\n");
        }
    }

    printf("Félicitations ! Vous avez terminé le jeu.\n");
    return 0;
}
