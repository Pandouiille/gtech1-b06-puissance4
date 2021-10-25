#include <stdio.h>

#define nbl 6
#define nbc 8
int c;
int l;
char game[nbl][nbc];
int player = 0;
char token[]="ox";


void init(void){
  
  for(l=1;l<nbl;l++){
    for(c=1;c<nbc;c++){
      game[l][c] = '.';
    }
  }
  for(l=0;l<nbl;l++){
    for(c=0;c<1;c++){
      game[l][c]='|';
    }
  }


  for(l=1;l<nbl;l++){                                                                                                                                                                                                                           printf("\n");                                                                                                                                                                                                                               for(c=1;c<nbc;c++){                                                                                                                                                                                                                           printf("%c ", game[l][c]);                                                                                                                                                                                                                 }
  }                                                                                                                                                                                                                                           printf("\n");
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
      printf("Joueur%d choisissez une collonne entre 0 et 6\n",player);
      int ret = scanf("\%d",&column);
      if(column<=nbc && column>=0){
	input_ok=1;
      }
	else{
	  input_ok=0;
	}
    }
    
    printf("okaaay, let's gooo\n");
        
    //while the column is not full, check if token is present or not
    l=nbl;
    while (l<0){
      if (game[l][column] == '.'){
	game[l][column] = token[player];
        l=-1;
	
      }
      else if(game[l][column] != '.'){
	l=l-1;
      }
    }
    //if column is full, ask player to choose an other column
    if (l<0){
	printf("colonne pleine, choisissez en une autre");
    }
    
    for(l=1;l<nbl;l++){
      printf("\n ");
      for(c=1;c<nbc;c++){
	printf("%c", game[l][c]);
      }
    }
    l=nbl;

    
  }

  printf("bienvenue dans le puissance4\n");
  
    while (!win && !game_full){
      if(player){
	choosecolumn(1);
    }
    else if (!player){
      choosecolumn(2);
    }
    else;
      printf("PTDR, t'est qui ?");
    player=!player;
   
  }
}
