#include<stdbool.h>  
#include<stdio.h>  
#include<stdlib.h>  
#include<conio.h>
#define PATH ' '   
#define WALL '#'   
#define START 'S'   
#define END 'E'   
#define PLAYER 'P'
void intro(){  //funtion for introduction
	printf("\n");	printf("\n");
	printf("\t\tMMM MMM  AAAAA  ZZZZZ  EEEEE    GGGGGG  AAAAA  MMM MMM  EEEEE         	         ABDUL WASAY\n");
	printf("\t\tM  M  M  A   A     ZZ  E        G       A   A  M  M  M  E    \n");
	printf("\t\tM  M  M  AAAAA    Z    EEE      G  GGG  AAAAA  M  M  M  EEE               BY:    UMAIS MUSTAFA\n");
	printf("\t\tM     M  A   A  ZZ     E        G    G  A   A  M     M  E    \n");
	printf("\t\tM     M  A   A  ZZZZZ  EEEEE    GGGGGG  A   A  M     M  EEEEE                    ASHAR ADNAN\n");
	printf("\n");printf("\n \t\t\t\t~~~ESCAPE OR REPEAT SEMESTER  ^.^ ~~~\n");
	printf("\nIn this maze game, your goal is to navigate from the starting point to the exit by finding the correct path through the maze. Use the W,S,A,D keys (up, down, left, right) to move through the maze, avoiding walls and dead ends.Try to find the quickest route to the exit. Be careful not to get stuck—if you do, you can restart the game or use the reset option to try again!\n");
}
void printMatrix(char *arr,int r, int c){ //function to print matrix
    for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){	
			printf("%c ",*((arr + i * c) + j));
		}
		printf("\n");	}}
struct position {  //structure for storing row and column position
	int rowIndex, colIndex;};
//the below structure is for getting position of start(S) and End(E) 	
struct position getPositionOfCharacter(char * maze, int numRows, int numCols, char character) {
	struct position positionOfCharacter = { -1, -1 };
	bool isFound = false;
	for(int row = 0; row < numRows && !isFound; row++) {
	for(int col = 0; col < numCols && !isFound; col++) {
	if(*((maze + row * numCols) + col) == character) {
		positionOfCharacter.rowIndex = row;
		positionOfCharacter.colIndex = col;
		isFound = true;}}}
	return positionOfCharacter;};
char getCharacterAtPosition(char * maze, int numCols, struct position playerPosition) { //check if the required index is wall or empty
	return *((maze + playerPosition.rowIndex * numCols) + playerPosition.colIndex);}
void setCharacterAtPosition(char * maze, int numCols, struct position playerPosition, char value) {
		*((maze + playerPosition.rowIndex * numCols) + playerPosition.colIndex) = value;}
bool game(char* maze, int r, int c){ //function which controls the flow of game
	struct position startingPosition = getPositionOfCharacter(maze, r, c, START);
	struct position endingPosition = getPositionOfCharacter(maze, r, c, END);
	struct position playerPosition = startingPosition;
	printMatrix(maze,r,c); //first matrix will be printed
	bool hasWon = true;
	while(playerPosition.rowIndex != endingPosition.rowIndex || playerPosition.colIndex != endingPosition.colIndex){ //loop for each move
	fflush(stdin);
	printf("W(UP)  S(DOWN)  A(LEFT)  D(RIGHT)  1(Exit)\n");
	char move = getch(); //get move from user
	struct position newPlayerPosition = playerPosition;
	if(move == '1'){  //game will exit if 1 is pressed
	hasWon = false;
	break;}
	if(move == 'W' || move == 'w' && playerPosition.rowIndex > 0){//these nested if else-if checks the input and move the character accordingly
		newPlayerPosition.rowIndex -= 1;
	}else if(move == 'S' || move=='s' && playerPosition.rowIndex < r){
		newPlayerPosition.rowIndex += 1;
	}else if(move == 'A' || move == 'a'&& playerPosition.colIndex > 0){
		newPlayerPosition.colIndex -= 1;
	}else if(move == 'D' || move == 'd'&& playerPosition.colIndex < c){
		newPlayerPosition.colIndex += 1;
	}else{
		printf("\nInvalid Move!!\n");
	continue;}
	if(getCharacterAtPosition(maze, c, newPlayerPosition) != WALL) {//if next position is not wall , player will move 
		setCharacterAtPosition(maze, c, playerPosition, PATH);
		setCharacterAtPosition(maze, c, newPlayerPosition, PLAYER);
		playerPosition = newPlayerPosition;	}
	system("cls");	//clear screen after each move
	printMatrix(maze,r,c);	}	//print maze with updated player position	
	return hasWon;	}
			//~~~~~~ ALL LEVELS ~~~~~~~~
char lvl_1[6][6] = {
        {WALL, WALL, WALL, WALL, WALL, WALL},	
        {WALL, START, PATH, WALL, WALL, WALL},
        {WALL, WALL, PATH, WALL, WALL, WALL},
        {WALL, WALL, PATH, PATH, WALL, WALL},
        {WALL, WALL, WALL, PATH, PATH, END },
        {WALL, WALL, WALL, WALL, WALL, WALL},	};
char lvl_2[7][7]={
        {WALL, WALL, WALL, WALL, WALL, WALL, WALL},	
        {WALL, START, PATH, PATH, PATH, PATH, WALL},
        {WALL, WALL, WALL, WALL, WALL, PATH, WALL},
        {WALL, PATH, PATH, WALL, PATH, PATH, WALL},
        {WALL, WALL, PATH ,WALL, WALL, PATH, WALL},
        {WALL, PATH, PATH, PATH, PATH, END, WALL},
        {WALL, WALL, WALL, WALL, WALL, WALL, WALL},};
	char lvl_3[8][8] = {
  	    {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
        {WALL, START, PATH, PATH, PATH, PATH, PATH, WALL},
        {WALL, WALL, WALL, WALL, WALL, PATH, PATH, WALL},
        {WALL, PATH, PATH, PATH, WALL, PATH, WALL, WALL},
        {WALL, WALL, PATH, PATH, PATH, PATH, PATH, WALL},
        {WALL, PATH, PATH, WALL, WALL, WALL, WALL, WALL},
        {WALL, WALL, PATH, PATH, PATH, PATH, END, WALL},
        {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},};
    char lvl_4[9][9] = {
    	{WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
        {WALL, START, PATH, PATH, PATH, PATH, PATH, PATH, WALL},
        {WALL, WALL, WALL, WALL, WALL, PATH, WALL, PATH, WALL},
        {WALL, PATH, PATH, PATH, PATH, PATH, WALL, PATH, WALL},
        {WALL, WALL, WALL, WALL, WALL, PATH, PATH, PATH, WALL},
        {WALL, PATH, PATH, WALL, WALL, WALL, PATH, WALL, WALL},
        {WALL, WALL, PATH, PATH, PATH, WALL, PATH, PATH, WALL},
        {WALL, PATH, PATH, PATH, PATH, PATH, PATH, END, WALL},
        {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},};
     char lvl_5[10][10] = {
     	{WALL,WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL,WALL},
        {WALL,START, PATH, PATH, PATH, PATH, PATH, PATH, PATH,WALL},
        {WALL,WALL, WALL, WALL, PATH, PATH, PATH, WALL, PATH,WALL},
        {WALL,PATH, PATH, PATH, PATH, WALL, PATH, WALL, WALL,WALL},
        {WALL,WALL, WALL, WALL, WALL, WALL, PATH, WALL, PATH,WALL},
        {WALL,PATH, PATH, WALL, PATH, WALL, PATH, PATH, PATH,WALL},
        {WALL,WALL, PATH, PATH, WALL, PATH, WALL, PATH, PATH,WALL},
        {WALL,PATH, WALL, PATH, PATH, WALL, WALL, PATH, WALL,WALL},
        {WALL,PATH, PATH, PATH, WALL, WALL, PATH, PATH, PATH, END},
        {WALL,WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL,WALL},};
	char lvl_6[11][11] = {
	    {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL}, 
        {WALL, START, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, WALL},
        {WALL, WALL, WALL, WALL, PATH, WALL, WALL, PATH, PATH, WALL, WALL},
        {WALL,PATH, PATH, PATH, WALL, PATH, PATH, PATH, WALL, PATH, WALL},
        {WALL,WALL, WALL, WALL, WALL, WALL, WALL, PATH, WALL, WALL, WALL},
        {WALL,PATH, PATH, WALL, PATH, WALL, PATH, PATH, PATH, WALL, WALL},
        {WALL,WALL, PATH, WALL, WALL, WALL, PATH, PATH, PATH, PATH, WALL},
        {WALL,PATH, PATH, PATH, PATH, PATH, WALL, WALL, WALL, PATH, WALL},
        {WALL,WALL, PATH, PATH, WALL, WALL, PATH, WALL, WALL, PATH, WALL},
        {WALL,PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, END, WALL},
        {WALL,WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},};
	char lvl_7[12][12] = {
	    {WALL,WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
        {WALL,START, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, WALL},
        {WALL,WALL, WALL, PATH, WALL, PATH, PATH, WALL, PATH, WALL, WALL, WALL},
        {WALL,PATH, PATH, PATH, WALL, WALL, PATH, PATH, WALL, PATH, PATH, WALL},
        {WALL,WALL, WALL, PATH, PATH, PATH, WALL, WALL, PATH, PATH, WALL, WALL},
        {WALL,PATH, WALL, PATH, WALL, PATH, PATH, PATH, WALL, PATH, PATH, WALL},
        {WALL,WALL, PATH, PATH, WALL, PATH, WALL, WALL, PATH, PATH, WALL, WALL},
        {WALL,PATH, PATH, PATH, WALL, PATH, PATH, WALL, PATH, PATH, PATH, WALL},
        {WALL,WALL, WALL, PATH, PATH, PATH, WALL, PATH, WALL, PATH, WALL, WALL},
        {WALL,PATH, WALL, WALL, WALL, PATH, PATH, PATH, PATH, WALL, PATH, WALL},
        {WALL,PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, END, WALL},
        {WALL,WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},};
        //~~~~~FUNCTION FOR CONTINOUS GAME~~~~
	void runTheGame(){
		if(!game(&lvl_1[0][0],6,6)){
			printf("Game Over\n");
			return;
		}else
			printf("You have Completed Level 1\n");
		if(!game(&lvl_2[0][0],7,7)){
			printf("Game Over\n");
			return;
		}else
			printf("You have Completed Level 2\n");
		if (!game(&lvl_3[0][0], 8, 8)) {
        	printf("Game Over!\n");
        	return;  
		}else
    		printf("You have Completed Level 3\n");
		if (!game(&lvl_4[0][0], 9, 9)) {
        	printf("Game Over!\n");
        	return;  }
    		printf("You have Completed Level 4\n");
    	if (!game(&lvl_5[0][0], 10, 10)) {
        	printf("Game Over!\n");
        	return;  }
    		printf("You have Completed Level 5\n");
    	if (!game(&lvl_6[0][0], 11, 11)) {
        	printf("Game Over!\n");
        	return;  }
    		printf("You have Completed Level 6\n");
    	if (!game(&lvl_7[0][0], 12, 12)) {
        	printf("Game Over!\n");
        	return;  }
    		printf("You have Completed Level 7\n");
    	printf("Congratulations! You've completed all levels!\n");}
    	//~~~~~ALL FUNCTIONS ARE CALLED IN THIS FUNCTION 
	void finalfunc(){
		int n , n1;
    	printf("CHOOSE GAME MODE :\n1.CONTINOUS\n2.CHOOSE LVL.\n0.EXIT GAME\nPRESS RESPECTIVE NUMBER\n");scanf("%d",&n);
    	switch(n){ 	//switch case for menu
    		case 1:
    			runTheGame();		break;
    		case 2:
		    	printf("ENTER LEVEL NUMBER\n");scanf("%d",&n1);
			    switch(n1){	//switch case for choosing levels
				    case 1:		game(&lvl_1[0][0], 6, 6);	finalfunc();	break;
	            	case 2:		game(&lvl_2[0][0], 7, 7);	finalfunc();	break;
	            	case 3:		game(&lvl_3[0][0], 8, 8);	finalfunc();	break;
	            	case 4:		game(&lvl_4[0][0], 9, 9);	finalfunc();	break;
	            	case 5:		game(&lvl_5[0][0], 10, 10);	finalfunc();	break;
	            	case 6:		game(&lvl_6[0][0], 11, 11);	finalfunc();	break;
	            	case 7:    	game(&lvl_7[0][0], 12, 12);	finalfunc();	break;
					default:  printf("LEVELS ARE BETWEEN 1 TO 7!"); finalfunc();  break;	}
		    case 0:	 printf("GAME EXITED SUCCESSFUL"); 		break;	
		    default: printf("PRESSED THE WRONG KEY\n");   finalfunc();		break;	}
	}
int main(){
	intro(); 		//intro function 
	finalfunc();	//final funtion which contain every function	
}
