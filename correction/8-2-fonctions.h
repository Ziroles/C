#pragma once

extern const int NB_PIONS_PAR_COULEUR;
extern const int TAILLE;

void init(char[]);
void afficher(const char[]);
char gagne(const char[]);
char bloque(const char[]);
void joueUnCoup(char[]);