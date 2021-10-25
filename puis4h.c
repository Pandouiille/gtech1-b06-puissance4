#include <stdio.h>

#define nbl 6
#define nbc 8
int c;
int l;
char game[nbl][nbc];
int player = 0;
char token[]="ox";


void init(void){
  
  for(l=0;l<nbl;l++){
    for(c=0;c<nbc;c++){
      game[l][c] = '.';
    }
  }

  for(l=0;l<nbl;l++){                                                                                                                                                                                                                           printf("\n");                                                                                                                                                                                                                               for(c=0;c<nbc;c++){                                                                                                                                                                                                                           printf("%c ", game[l][c]);                                                                                                                                                                                                                 }
  }                                                                                                                                                                                                                                           printf("\n");
}


void flushstdin() {
  int c;
  while((c = getchar()) != '\n' && c != EOF)
    ;
    }
  

void main(void){

  int win;
  int game_full;
  init(); 

  int choosecolumn(int player){
    /*---player imnput---*/
    
    int column, return_input;
    /*ask the player to choose a column
    test the input,it need to be lower than the max column number and higher than minium column 
    while player input is wrong, ask again the player to choose a column*/
    int input_ok=0;
    while (input_ok==0){
      printf("Joueur%d choisissez une collonne entre 0 et %d\n",player,nbc);
      int ret = scanf("\%d",&column);
      if (ret == 0){
	flushstdin();
	printf("Vous n'avez pas entrer de nombre entier. Entrez un nombre entier entre 0 et %d",nbc);
      }


      if(column<=nbc && column>=0){
	input_ok=1;
      }
	else{
	  input_ok=0;
	}
    }
          
    //while the column is not full, check if token is present or not
    l=nbl;
    while(l>=0){
      if (game[l][column] == '.'){
	game[l][column] = token[player];
	l=-1;   
      }
      while(game[l][column] != '.'){
	l=l-1;
      }
    }  
    //if column is full, ask player to choose an other column
    if (l==0){
      printf("colonne pleine,choisissez en une autre");
    }
    
    for(l=0;l<nbl;l++){
      printf("\n ");
      for(c=0;c<nbc;c++){
	printf("%c", game[l][c]);
      }
    }
    l=nbl;
    printf("\n");
  }

  printf("bienvenue dans le puissance4\n");
  
    while (!win && !game_full){
         
        
      choosecolumn(player);	 
  
      player=!player;
   
  }
}
