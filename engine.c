/*
 * Name:- Pramod Munemanik & G. KrishnaChaitanya
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "MazeSolver.h"


int main()
{
	char* Maze;
	int i,n,j,c=0,k=0,t=0,p=0	;
	int x,y;
	int S_U=0,S_E=0;	
	
	srand(time(NULL));
	Maze = maze_former();
	system("clear");
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
sleep(3);
printf("			Loading.....");fflush(stdout);
sleep(3);
	mazeprint(Maze);
	system("clear");
	printf("\n");
	int m=0;
	int *end;
	int dir,score=0;
	end = (int*)malloc(sizeof(int));
	*end = 0;
	char input;
	int mir;
/*
while(*end!=1){
		dir=bot2start(Maze,end);
		score = Maze_alter(Maze , dir, 1, end);
		S_U = S_U + score; 
		system("clear");             
		mazeprint(Maze);
		printf("Score of U : %d\nScore of E : %d\n" ,S_U,S_E);
		sleep(1);
		//system("clear");
		scanf("%c",&input);
		if(input=='w')
		mir=0;
		if(input=='d')
		mir=1;
		if(input=='s')
		mir=2;
		if(input=='a')
		mir=3;
		score = Maze_alter(Maze , mir, 0, end);
		S_E = S_E + score;
		system("clear");
		mazeprint(Maze);		
		printf("Score of U : %d\nScore of E : %d\n" ,S_U,S_E);
//		if(*end == 1){ printf("The winner is User bot with a score : %d\n" ,S_U); sleep(10);}
		sleep(1);
		//system("clear");
		
	}	
	return ;


*/









	while(*end!=1){
		dir=bot2start(Maze,end);
		score = Maze_alter(Maze , dir, 1, end);
		S_U = S_U + score; 
		system("clear");             
		mazeprint(Maze);
		printf("Score of U : %d\nScore of E : %d\n" ,S_U,S_E);
		sleep(1);
		//system("clear");
		dir = bot3start(Maze,end);
		score = Maze_alter(Maze , dir, 0, end);
		S_E = S_E + score;
		system("clear");
		mazeprint(Maze);		
		printf("Score of U : %d\nScore of E : %d\n" ,S_U,S_E);
//		if(*end == 1){ printf("The winner is User bot with a score : %d\n" ,S_U); sleep(10);}
		sleep(1);
		//system("clear");
	}	
	if(S_E > S_U) printf("\n\n\nThe winner is Enemy bot with a lead of %d\n" ,(S_E-S_U));
	else if(S_E == S_U) printf("\n\n\nThe game is DRAW with scores %d\n" ,S_E);
	else printf("\n\n\nThe winner is User bot with a lead of %d\n" ,(S_U-S_E));
	sleep(5);
	system("clear");
		 
	return 0;	
}



