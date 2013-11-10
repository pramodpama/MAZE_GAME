/*
 * Name:- Pramod Munemanik
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "MazeSolver.h"


int main()
{
	char Maze[289];
	int i,n,j,c=0,k=0,t=0,p=0	;
	int x,y;
	int ER,UR;	
	
	srand(time(NULL));
	
	for(i=0;i<17;i++)
		Maze[i]='#';
	
	for(i=0;i<17;i++)
		Maze[i*17]='#';
	
	for(i=0;i<17;i++)
		Maze[16*17+i]='#';
	
	for(i=0;i<17;i++)
		Maze[i*17+16]='#';
	
	for(i=1;i<16;i++){
		for(j=1;j<16;j++)
		{
			n = rand()%288;
			if(n%4==0)
			Maze[i*17+j]='#';
			else 
			Maze[i*17+j]='.';
		}			
	}
	
	
	for(i=1;i<16;i++){
		for(j=1;j<16;j++)
		{
			n = rand()%288;
			if(n%10==0 && Maze[i*17+j]=='.' && c<15){
				Maze[i*17+j]='2';
				c++;	
			}
			if(Maze[i*17+j]=='#' && k==0 && (n+11)%10==0){
				Maze[i*17+j]='E';
				k++;
			}
			if(Maze[i*17+j]=='#' && (n+3)%10==0 && t==0){
				Maze[i*17+j]='U';
				t++;
			}
		}
	}			
	

	for(i=5;i<16;i++){
		for(j=5;j<16;j++)
		{
			n = rand()%288;
			if( Maze[i*17+j]=='#' && p==0 && (n)%17==0) {
				
					Maze[i*17+j]='R';
					p++;
								
			}
		}
	}
	printf("MMMMMMMM               MMMMMMMM  \n");                                                     
printf("M:::::::M             M:::::::M       \n");                                                
printf("M::::::::M           M::::::::M       \n");                                                
printf("M:::::::::M         M:::::::::M       \n");                                                
printf("M::::::::::M       M::::::::::M  aaaaaaaaaaaaa   zzzzzzzzzzzzzzzzz    eeeeeeeeeeee    \n");
printf("M:::::::::::M     M:::::::::::M  a::::::::::::a  z:::::::::::::::z  ee::::::::::::ee  \n");
printf("M:::::::M::::M   M::::M:::::::M  aaaaaaaaa:::::a z::::::::::::::z  e::::::eeeee:::::ee\n");
printf("M::::::M M::::M M::::M M::::::M           a::::a zzzzzzzz::::::z  e::::::e     e:::::e\n");
printf("M::::::M  M::::M::::M  M::::::M    aaaaaaa:::::a       z::::::z   e:::::::eeeee::::::e\n");
printf("M::::::M   M:::::::M   M::::::M  aa::::::::::::a      z::::::z    e:::::::::::::::::e \n");
printf("M::::::M    M:::::M    M::::::M a::::aaaa::::::a     z::::::z     e::::::eeeeeeeeeee  \n");
printf("M::::::M     MMMMM     M::::::Ma::::a    a:::::a    z::::::z      e:::::::e           \n");
printf("M::::::M               M::::::Ma::::a    a:::::a   z::::::zzzzzzzze::::::::e          \n");
printf("M::::::M               M::::::Ma:::::aaaa::::::a  z::::::::::::::z e::::::::eeeeeeee  \n");
printf("M::::::M               M::::::M a::::::::::aa:::az:::::::::::::::z  ee:::::::::::::e \n");
printf("MMMMMMMM               MMMMMMMM  aaaaaaaaaa  aaaazzzzzzzzzzzzzzzzz    eeeeeeeeeeeeee  \n");

printf("\n\n");                                                                                      
                             
	mazeprint(Maze);
	system("clear");
	printf("\n");
	int end=0;
	while(end!=1){
		
		end=botstart((Maze+0));              //put comment
		mazeprint(Maze);
		
		sleep(1);
		system("clear");
		
		
	}	
	
		//mazeprint(Maze); 
	return 0;
	
}


