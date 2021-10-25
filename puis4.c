#include <stdio.h>
#include <stdlib.h>

#define colonnes (7)
#define lignes (6)

#define jetons_J1 ('o')
#define jetons_J2 ('x')

char grille [lignes][colonnes];

struct position {
  int colonne;
  int ligne;
};
//affiche la grille tout au long de la partie 
void affiche_grille(void){
  int col;
  int lgn;
  putchar('\n');
  for (lgn = 0; lgn <lignes;lgn++){
    putchar('|');
    for (col = 0; col<colonnes;col++){
      if (grille[col][lgn] != ' ')
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

//initialise la matrice
void initialise_grille(void){
  int col;
  int lgn;
  for (col = 0;col<=colonnes;col++){
    for (lgn=0;lgn<=lignes;lgn++){
      grille[col][lgn] = '.';
    }
  }
}
//sert à vérifier si la grille est pleine
int grille_pleine(void){
  int col;
  int lgn;
  for (col = 0; col<colonnes;col++){
    for (lgn = 0; lgn<lignes;lgn++){
      if (grille[col][lgn] == '.')
	return 0;
    }
    return 1;
  }
}
//change le coup en numéro de colonne|ligne      
void change_pos(int coup, struct position *pos){
  int lgn;
  pos->colonne = coup ;
  for (lgn = lignes-1;lgn>=0;lgn--){
    if (grille[pos->colonne][lgn] == '.'){
      pos->ligne = lgn;
      break;
    }
  }
}
      
   

int main (void){
  initialise_grille();
  affiche_grille();
}

