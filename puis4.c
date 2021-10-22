#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define colonnes (7)
#define lignes (6)

char grille [lignes][colonnes];

//print 
void affiche_grille(void){
  int col;
  int lgn;
  putchar('\n');
  for (lgn = 0; lgn <lignes;lgn++){
    putchar('|');
    for (col = 0; col<colonnes;col++){
      if (isalpha(grille[col][lgn]))
	printf("%c |",grille[col][lgn]);
      else
	printf("%c |", ' ');
    }
    putchar('\n');
    putchar('+');

    for (col = 1; col<=colonnes;col++){
      printf("--+");
    }
    putchar('\n');
  }
  for (col = 1;col<= colonnes; col++){
    printf("  %d",col);
  }
  putchar('\n');
}

void initialise_grille(void){
  int col;
  int lgn;
  for (col = 0;col<=colonnes;col++){
    for (lgn=0;lgn<=lignes;lgn++){
      grille[col][lgn] = '.';
    }
  }
}

int main (void){
  initialise_grille();
  affiche_grille();
}

