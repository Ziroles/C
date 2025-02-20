#include <stdio.h>
#include <string.h>

#define MAX_CHAR 128

typedef struct {
    char car;
    int nb;
} Letter;

int main() {
    Letter letters[MAX_CHAR] = {0};  // Initialisation des structures
    char input[256];  // Pour stocker le texte de l'utilisateur
    int i;

    // Initialisation des lettres
    for (i = 0; i < MAX_CHAR; i++) {
        letters[i].car = (char)i;
        letters[i].nb = 0;
    }

    // Saisie utilisateur
    printf("Entrez un texte : ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // Supprimer le saut de ligne

    // Comptage des occurrences
    for (i = 0; i < strlen(input); i++) {
        letters[(int)input[i]].nb++;
    }

    // Affichage du résultat
    printf("Occurrences des lettres :\n");
    for (i = 0; i < MAX_CHAR; i++) {
        if (letters[i].nb > 0 && ((letters[i].car >= 'a' && letters[i].car <= 'z') || 
                                  (letters[i].car >= 'A' && letters[i].car <= 'Z'))) {
            printf("%c : %d\n", letters[i].car, letters[i].nb);
        }
    }

    return 0;
}
