#include <stdio.h>
#include <stdlib.h>

#define nbc (7)
#define nbl (6)

char token[]="ox";
char game[nbl][nbc];
int player = 1;

void flushstdin(){
  int c;
  while((c = getchar()) != '\n' && c != EOF);
}

//affiche la grille tout au long de la partie 
void display(void){
  int col;
  int lgn;
  putchar('\n');
  for (lgn = 0; lgn <nbl;lgn++){
    putchar('|');
    for (col = 0; col<nbc;col++){
      if (game[lgn][col] != ' ')
	printf("%c |",game[lgn][col]);
      else
	printf("%c |", ' ');
    }
    putchar('\n');
    putchar('+');

    for (col = 1; col<=nbc;col++){
      printf("--+");
    }
    putchar('\n');
  }
  for (col = 1;col<= nbc; col++){
    printf(" %d ",col);
  }
  putchar('\n');
}

//initialise la matrice
void init(void){
  int col;
  int lgn;
  for (lgn = 0;lgn<nbl;lgn++){
    for (col = 0;col<nbc;col++){
      game[lgn][col] = '.';
    }
  }
}

//sert à vérifier si la grille est pleine
int game_full(void){
  int col;
  int lgn;
  for (lgn = 0; lgn<nbl;lgn++){
    for (col = 0; col<nbc;col++){
      if (game[lgn][col] == '.');
	return 1;
    }
    return 0;
  }
}      
   
int choosecolumn(){
  int l;
  int column; 
  int input_ok = 0;
  l = nbl;
  while(input_ok == 0){
    printf("Joueur%d, entrez un nombre entier entre 0 et %d\n",player,nbc);
    int ret = scanf("%d",&column);
    column = column - 1;
    if (ret != 1){
      flushstdin();
      printf("Entrez un nombre entier 0 et %d\n", nbc);
    }
    if (column<nbc && column>=0){
      input_ok=1;
    }
    else {
      input_ok=0;
      printf("Cette colonne n'existe pas. Entrez une autre colonne entre 0 et %d\n", nbc);
    }
  }
  while(l>=0){
    if (game[l][column] == '.'){
      game[l][column] = token[player];
      break;
    }
    while(game[l][column] != '.'){
      l=l-1;
    }
    if (l==0){
      printf("Colonne plein\n");
    }
  }
}


  
  
	
    
  

int main (void){
  int win;
  printf("Bienvenue au puissance 4\n");
  init();
  while (!win && (game_full) != 0){
    display();
    choosecolumn(player);
    player=!player;
  }
}

