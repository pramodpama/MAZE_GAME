/*
 * Name:- Pramod Munemanik
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"MazeSolver.h"


int main()
{
	char* Maze;

	int i,n,j,c=0,k=0,t=0,p=0	;
	int x,y;
	int S_U=0,S_E=0;	
	
	srand(time(NULL));
	
	Maze = maze_former();
	system("clear");
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");	
printf("		MMMMMMMM               MMMMMMMM  \n");                                                     
printf("		M:::::::M             M:::::::M       \n");                                                
printf("		M::::::::M           M::::::::M       \n");                                                
printf("		M:::::::::M         M:::::::::M       \n");                                                
printf("		M::::::::::M       M::::::::::M  aaaaaaaaaaaaa   zzzzzzzzzzzzzzzzz    eeeeeeeeeeee    \n");
printf("		M:::::::::::M     M:::::::::::M  a::::::::::::a  z:::::::::::::::z  ee::::::::::::ee  \n");
printf("		M:::::::M::::M   M::::M:::::::M  aaaaaaaaa:::::a z::::::::::::::z  e::::::eeeee:::::ee\n");
printf("		M::::::M M::::M M::::M M::::::M           a::::a zzzzzzzz::::::z  e::::::e     e:::::e\n");
printf("		M::::::M  M::::M::::M  M::::::M    aaaaaaa:::::a       z::::::z   e:::::::eeeee::::::e\n");
printf("		M::::::M   M:::::::M   M::::::M  aa::::::::::::a      z::::::z    e:::::::::::::::::e \n");
printf("		M::::::M    M:::::M    M::::::M a::::aaaa::::::a     z::::::z     e::::::eeeeeeeeeee  \n");
printf("		M::::::M     MMMMM     M::::::Ma::::a    a:::::a    z::::::z      e:::::::e           \n");
printf("		M::::::M               M::::::Ma::::a    a:::::a   z::::::zzzzzzzze::::::::e          \n");
printf("		M::::::M               M::::::Ma:::::aaaa::::::a  z::::::::::::::z e::::::::eeeeeeee  \n");
printf("		M::::::M               M::::::M a::::::::::aa:::az:::::::::::::::z  ee:::::::::::::e \n");
printf("		MMMMMMMM               MMMMMMMM  aaaaaaaaaa  aaaazzzzzzzzzzzzzzzzz    eeeeeeeeeeeeee  \n");

printf("\n\n");  
printf("press enter to start game");
getchar();                                                                                    
   // sleep(5);
	system("clear");
	mazeprint(Maze);
	system("clear");
	printf("\n");
	int m=0;
	int *end;
	int dir,score=0;
	end = (int*)malloc(sizeof(int));
	*end = 0;
	while(*end!=1){
		dir=botstart(Maze,end);
		score = Maze_alter(Maze , dir, 1, end);
		S_U = S_U + score;              //put comment
		mazeprint(Maze);
		printf("%d\n\n" ,S_U);
		if(*end == 1){ printf("The winner is User bot with a score : %d\n" ,S_U); sleep(10);}
		sleep(1);
		system("clear");
	}	
	
		//mazeprint(Maze); 
	return 0;
	
}



