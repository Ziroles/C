#pragma once

#include<stdio.h>

unsigned char saisie(char* const message, unsigned char min, unsigned char max);
void creer(char** dessin, unsigned char* largeur, unsigned char* hauteur);
void afficher(char* dessin, unsigned char largeur, unsigned char hauteur);
void ecrireAffichage(char* dessin, unsigned char largeur, unsigned char hauteur, FILE* sortie);
void dessinerCaractere(char* dessin, unsigned char largeur, unsigned char hauteur);
void dessinerRectangle(char* dessin, unsigned char largeur, unsigned char hauteur);
void changerCaractere(char* dessin, unsigned char largeur, unsigned char hauteur);
void proposerEnregistrement(char* dessin, unsigned char largeur, unsigned char hauteur);
void enregistrer(char* dessin, unsigned char largeur, unsigned char hauteur);
void charger(char** dessin, unsigned char* largeur, unsigned char* hauteur);