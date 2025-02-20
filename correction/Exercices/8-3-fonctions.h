#pragma once

extern const int HAUTEUR;
extern const int LARGEUR;

void initialiser(char[][LARGEUR]);
int saisie(char*, int, int);
void afficher(const char[][LARGEUR]);
void dessinerCaractere(char[][LARGEUR]);
void dessinerRectangle(char[][LARGEUR]);
void changerCaractere(char[][LARGEUR]);
void propager(char[][LARGEUR], int, int, char, char);