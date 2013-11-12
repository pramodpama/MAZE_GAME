/*
 * Name:- Pramod Munemanik
 *
 */

#include<stdio.h>
#include"MazeSolver.h"

int* botstart(char* Maze,int* end )
{
//	mazeprint(Maze);
	int start=posn(Maze,'U');                      //position of U
	int next_posn= wheremove(Maze,start);
	int direction = next_posn - start;
	if(direction == -52) direction = 0;
	else if(direction == 1) direction = 1;
	else if(direction == 52) direction = 2;
	else direction = 3;
	int y=posn(Maze,'R');     // next position
//	Maze[start]='.';
//	Maze[next_posn]='U';
///	mazeprint(Maze);		
	//maze_print(Maze);
	
	//move(Maze,next_posn);
//	mazeprint(Maze);
	//maze_print(Maze);	
	
//	int y=posn(Maze,'R');
//	mazeprint(Maze);	
	if(next_posn==y)
	*end = 1;
	return direction;
}



int wheremove(char* Maze,int start )
{			
		
			int temp = sdistance(Maze, start);
			int dis;
		//printf("temp %d",temp);
		
			if(Maze[start+1]!='#'){
			dis=sdistance(Maze, start+1);
		//printf("dis %d",dis);
			if(dis<temp)
			return start+1;	
			}

					
			if(Maze[start-1]!='#'){			
			dis=sdistance(Maze, start-1);
	//	printf("dis %d",dis);			
			if(dis<temp)
			return start-1;
			}
										
			if(Maze[start-52]!='#'){
			dis=sdistance(Maze, start-52);
	//	printf("dis %d",dis);
			if(dis<temp)
			return start-52;
			}
			
			if(Maze[start+52]!='#'){			
			dis=sdistance(Maze, start+52);
	//	printf("dis %d",dis);
			if(dis<temp)
			return start+52;			
			}
	
			return 0 ;
}	

int posn(char* Maze,char y)
{
	int i,j,x;
	for(i=0;i<52;i++)
	{
		for(j=0;j<52;j++)
		{
		if(*(Maze+i*52+j)==y)
		x=i*52+j;
		}
	}	
	return x;
}

int sdistance(char* Maze, int lrud)
{
	int i;
	int visit[52*52];
	for(i=0;i<52*52;i++)
	{
		visit[i]=0;	
	}

	Queue* p;
	p=queue_new();
	p=queue_push(p,lrud);
	p=queue_push(p,-1);              // '#' to -5 changed		
	
	int dis=shortestDistance(Maze,visit,p,0,52);
	
	return dis;
}
	
char* move(char* Maze,int x)
{
	
	int i,j;
	for(i=0;i<52;i++)
	{
		for(j=0;j<52;j++)
		{
			if(*(Maze+i*52+j)=='U'){
			Maze[x]='U';
			//*(Maze+i*52+j)='.';
			//Maze[i*52+j]='.';
			}
		}
	}	

	return Maze;
} 

