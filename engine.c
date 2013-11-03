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


	for(i=0;i<17;i++)
	{
		for(j=0;j<17;j++)
		{	
		printf("%c   ",Maze[i*17+j]);
		}
	printf("\n\n");
	}

	return 0;
}
/*

int shortest_dis(int x, char* Maze,int c)
{
	int visit[288];	
	int i;	
	Queue* q;
	q=queue_new();
	q=queue_push(q,x);
	q=queue_push(q,-1);	

	for(i=0;i<289;i++)
	visit[i]=0;
	
	int dis=shortestDistance(Maze,visit,q,0,c);

	return dis;
}*/
