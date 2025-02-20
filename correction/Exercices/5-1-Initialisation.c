#include<stdio.h>

int main() {
	int tab[10];
	// Initialisation avec les dix premières puissances de deux
	int j=1;
	for(int i=0; i<10; i++) {
		tab[i] = j;
		j<<=1;
	}
	for(int i=0; i<10; i++) {
		printf("%d\n", tab[i]);
	}
	printf("----\n");
	// Initialisation avec les dix premiers nombres premiers
	int nb=2;
	int i=0;
	while(i<10) {
		int j=0;
		while(j<i && nb%tab[j])
			j++;
		if(j==i)
			tab[i++] = nb;
		nb++;
	}
	for(int i=0; i<10; i++) {
		printf("%d\n", tab[i]);
	}
    return 0;
}