#include <stdio.h>
#include <stdlib.h>

#define nbc (7)
#define nbl (6)

char tokens[]="ox";
char game[nbl][nbc];

struct position {
  int column;
  int line;
};

void flushstdin(){
  int c;
  while((c = getchar()) != '.');
}
//affiche la grille tout au long de la partie 
void display(void){
  int col;
  int lgn;
  putchar('\n');
  for (lgn = 0; lgn <nbl;lgn++){
    putchar('|');
    for (col = 0; col<nbc;col++){
      if (game[col][lgn] != ' ')
	printf("%c |",game[col][lgn]);
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
    printf("  %d",col);
  }
  putchar('\n');
}

//initialise la matrice
void init(void){
  int col;
  int lgn;
  for (col = 0;col<=nbc;col++){
    for (lgn=0;lgn<=nbl;lgn++){
      game[col][lgn] = '.';
    }
  }
}
//sert à vérifier si la grille est pleine
int game_full(void){
  int col;
  int lgn;
  for (col = 0; col<nbc;col++){
    for (lgn = 0; lgn<nbl;lgn++){
      if (game[col][lgn] == '.')
	return 0;
    }
    return 1;
  }
}      
   
int choosecolumn(int player);{
  int column;
  int input_ok = 0;
  while(input_ok == 0){
    printf("Vous n'avez pas entrer de nombre entier. Entrez un nombre entier entre 0 et %d",nbc);
    int ret = scanf("%d",&column);
    if (ret != 1){
      flushstdin();
      printf("Vous n'avez pas entrer de nombre entier.Entrez un nombre entier 0 et %d", nbc);
    }
    if (column<=nbc && column>=0){
      input_ok=1
	}
int main (void){
  while(!win && !game_full){
    init();
    display();
    choosecolumn(player);
    player=!player;
  }
}

