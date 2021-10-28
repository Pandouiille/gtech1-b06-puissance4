#include <stdio.h>
#include <stdlib.h>

#define nbc (7)
#define nbl (6)

char token[]="ox";
char game[nbl][nbc];
int player = 1;
int column;
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
    printf("La grille est pleine ! Match Nul");
  }
}

//Demande au joueur la colonne dans laquelle veut placer son token   
int choosecolumn(){
  int l; 
  int input_ok = 0;
  l = nbl;
  while(input_ok == 0){
    printf("Joueur%d, entrez un nombre entier entre 0 et %d\n",player,nbc);
    int ret = scanf("%d",&column);
    column = column - 1;
    //Si la saisie comporte un caractère, execute le flushstdin pour empecher la boucle infini
    if (ret != 1){
      flushstdin();
      printf("Entrez un nombre entier 0 et %d\n", nbc);
    }
    //vérifie si la saisie est bonne
    if (column<nbc && column>=0){
      input_ok=1;
    }
    else {
      input_ok=0;
      printf("Cette colonne n'existe pas. Entrez une autre colonne entre 0 et %d\n", nbc);
    }
  }
  //Vérifie si la case est pleine, sinon remplace la case par le token
  while(l>=0){
    if (game[l][column] == '.'){
      game[l][column] = token[player];
      break;
    }
    while(game[l][column] != '.'){
      l=l-1;
    }
    if (l<=0){
      printf("La colonne %d est pleine \n",column+1);
    }
  }
}
//Pas fonctionnel
/*
int check_win(int player_win){
  int lgn;
  int col;
  for (lgn=0;lgn<=0;lgn++){
    for (col=0;col<=0;col++){
      if(game[lgn][col]==token[player_win] && game[lgn-1][col]==token[player_win] && game[lgn-2][col]==token[player_win] && game[lgn-3][col]==token[player_win]){
      return 1;
      }
    if (col<=3){
      if (game[lgn][col]==token[player_win] && game[lgn][col+1]==token[player_win] && game[lgn][col+2]==token[player_win] && game[lgn][col+3]==token[player_win]){
	return 1;
      }
    }
    if (lgn>=3){
      if (game[lgn][col]==token[player_win] && game[lgn-1][col+1]==token[player_win] && game[lgn-2][col+2]==token[player_win] && game[lgn-3][col+3]==token[player_win]){
	return 1;
      }	
    }
    if (lgn<=2){
      if (game[lgn][col]==token[player_win] && game[lgn+1][col+1]==token[player_win] && game[lgn+2][col+2]==token[player_win] && game[lgn+3][col+3]==token[player_win]){
	  return 1;
      }
    }
    else{
      return 0;
    }
    }
  }
}
*/
	     
  
  
	
    
  

int main (void){
  int win = 0;
  printf("Bienvenue au puissance 4\n");
  init();
  while ((win) != 1 && (game_full) != 0){
    display();
    choosecolumn(player);
    win = check_win(player);
    if (win == 1){
      printf("Le joueur %d remporte la partie !\n",player);
    }
    player=!player;
  }
}

