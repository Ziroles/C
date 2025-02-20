#include<stdio.h>
int main () {
    char c = 'E' ;
    printf ("\tAffichage d'un caractere\n") ;
    printf ("%%c -> %c\n", c) ;
    printf ("%%d -> %d\n", c) ;
    printf ("%%x -> %x\n", c) ;
    
    int e = 72;
    printf ("\tAffichage d'un entier\n") ;
    printf ("%%c -> %c\n", e) ;
    printf ("%%d -> %d\n", e);
    printf ("%%x -> %x\n", e) ;
    
    float f = 19.6F/100;
    printf ("\tAffichage d'un nombre reel\n") ;
    printf ("%%f -> %f\n", f);
    printf ("%%.3f -> %.3f\n", f) ;
    printf ("%%.2f -> %.3f\n", f) ;
    
    printf ("\tAffichage d'un texte\n") ;
    printf ("%%s -> %s\n", "3iL ingé") ;
    printf ("%%.3s -> %.3s\n", "3il ingé") ;
    printf ("bonjour %%-*.*s! -> bonjour %-*.*s!\n", 4, 2, "Julie");
    return 0;
}