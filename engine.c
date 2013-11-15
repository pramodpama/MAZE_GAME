/*
 * Name:- Pramod Munemanik & G. KrishnaChaitanya
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "MazeSolver.h"
#include <unistd.h>
#include <termios.h>
#define delay 1
#define size size

int main()
{

	 struct termios old_tio, new_tio;
    unsigned char input,ch;

    /* get the terminal settings for stdin */
    tcgetattr(STDIN_FILENO,&old_tio);

    /* we want to keep the old setting to restore them a the end */
    new_tio=old_tio;

    /* disable canonical mode (buffered i/o) and local echo */
    new_tio.c_lflag &=(~ICANON & ~ECHO);

    /* set the new settings immediately */
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);

    
	char* Maze;
	int i,n,j;
	int x,y;
	int S_U=0,S_E=0;	
	
	srand(time(NULL));
	Maze = maze_former();
	system("clear");

printf("    \n\n\n\n                 		                                         credits:- Krishna chaitanya\n");
printf("                                                                                   Pramod Munemanik\n");
printf("                                                                                   Jitendra Vaghela");
printf("\n\n\n\n\n\n");
printf("          ______   ______    _______   _______  _______  __    __  .__   __. \n ");   
printf("         |      | |  __  |  |       | |   ____||   ____||  |  |  | |  | |  | \n  ");   
printf("        |  ,----'|  |  |  | |  .--.  ||  |__   |  |__   |  |  |  | |   ||  | \n  ");   
printf("        |  |     |  |  |  | |  |  |  ||   __|  |   __|  |  |  |  | |  . `  | \n ");   
printf("        |  `----.|  `--'  | |  '--'  ||  |____ |  |     |  `--'  | |  ||   | \n ");   
printf("         |______| |______/  |_______/ |_______||__|      |______/  |__| |__| \n ");   
                                                                     

	printf("\n\n\n\n\n\n\n\n");
	
printf("        MMMMMMMM               MMMMMMMM  \n");                                                     
printf("        M:::::::M             M:::::::M       \n");                                                
printf("        M::::::::M           M::::::::M       \n");                                                
printf("        M:::::::::M         M:::::::::M       \n");                                                
printf("        M::::::::::M       M::::::::::M  aaaaaaaaaaaaa   zzzzzzzzzzzzzzzzz    eeeeeeeeeeee    \n");
printf("        M:::::::::::M     M:::::::::::M  a::::::::::::a  z:::::::::::::::z  ee::::::::::::ee  \n");
printf("        M:::::::M::::M   M::::M:::::::M  aaaaaaaaa:::::a z::::::::::::::z  e::::::eeeee:::::ee\n");
printf("        M::::::M M::::M M::::M M::::::M           a::::a zzzzzzzz::::::z  e::::::e     e:::::e\n");
printf("        M::::::M  M::::M::::M  M::::::M    aaaaaaa:::::a       z::::::z   e:::::::eeeee::::::e\n");
printf("        M::::::M   M:::::::M   M::::::M  aa::::::::::::a      z::::::z    e:::::::::::::::::e \n");
printf("        M::::::M    M:::::M    M::::::M a::::aaaa::::::a     z::::::z     e::::::eeeeeeeeeee  \n");
printf("        M::::::M     MMMMM     M::::::Ma::::a    a:::::a    z::::::z      e:::::::e           \n");
printf("        M::::::M               M::::::Ma::::a    a:::::a   z::::::zzzzzzzze::::::::e          \n");
printf("        M::::::M               M::::::Ma:::::aaaa::::::a  z::::::::::::::z e::::::::eeeeeeee  \n");
printf("        M::::::M               M::::::M a::::::::::aa:::az:::::::::::::::z  ee:::::::::::::e \n");
printf("        MMMMMMMM               MMMMMMMM  aaaaaaaaaa  aaaazzzzzzzzzzzzzzzzz    eeeeeeeeeeeeee  \n\n\n\n\n\n");

printf("			Loading.....");fflush(stdout);
sleep(3);
	printf("\n\n	 press 'c' to start single player game \n\n"); 
	
	printf(" 	 press 'b' to start double player game \n");	
	
	scanf("%c",&ch);
	mazeprint(Maze);
	system("clear");
	printf("\n");
	int m=0,dir2=0;
	int *end;
	int dir,score=0;
	end = (int*)malloc(sizeof(int));
	*end = 0;

	if(ch=='c'){
	while(*end!=1){
		dir=bot2start(Maze,end);
		score = Maze_alter(Maze , dir , 1, end);
		S_U = S_U + score; 
		system("clear");             
		mazeprint(Maze);
		printf("Score of U : %d\nScore of E : %d\n" ,S_U,S_E);

		scanf("%c",&input);


		if(input=='w')
		dir2=0;

		if(input=='d')
		dir2=1;

		if(input=='s')
		dir2=2;

		if(input=='a')
		dir2=3;

		score = Maze_alter(Maze , dir2, 0, end);
		S_E = S_E + score;

		system("clear");
		mazeprint(Maze);		
		printf("Score of U : %d\nScore of E : %d\n" ,S_U,S_E);

	}	

	
	} 
	if(ch=='b'){
	while(*end!=1){
		dir=bot2start(Maze,end);
		score = Maze_alter(Maze , dir, 1, end);
		S_U = S_U + score; 
		system("clear");             
		mazeprint(Maze);
		printf("Score of U : %d\nScore of E : %d\n" ,S_U,S_E);
		sleep(delay);
		//system("clear");
		dir = bot3start(Maze,end);
		score = Maze_alter(Maze , dir, 0, end);
		S_E = S_E + score;
		system("clear");
		mazeprint(Maze);		
		printf("Score of U : %d\nScore of E : %d\n" ,S_U,S_E);
//		if(*end == 1){ printf("The winner is User bot with a score : %d\n" ,S_U); sleep(10);}
		sleep(delay);
		//system("clear");
	}	
	}
	if(S_E > S_U) printf("\n\n\nThe winner is Enemy bot with a lead of %d\n" ,(S_E-S_U));
	else if(S_E == S_U) printf("\n\n\nThe game is DRAW with scores %d\n" ,S_E);
	else printf("\n\n\nThe winner is User bot with a lead of %d\n" ,(S_U-S_E));
	sleep(5);
	system("clear");
		 
	return 0;
		
}



