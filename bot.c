/*
 * Name:- Pramod Munemanik
 *
 */

#include<stdio.h>
#include"MazeSolver.h"

int botstart(char* Maze )
{
//	mazeprint(Maze);
	int start=posn(Maze,'U');                      //position of U
	int next_posn= wheremove(Maze,start);
	int y=posn(Maze,'R');     // next position
	Maze[start]='.';
	Maze[next_posn]='U';
///	mazeprint(Maze);		
	//maze_print(Maze);
	
	//move(Maze,next_posn);
//	mazeprint(Maze);
	//maze_print(Maze);	
	
//	int y=posn(Maze,'R');
//	mazeprint(Maze);	
	if(next_posn==y)
	return 1;
	
	return 0;
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
										
			if(Maze[start-17]!='#'){
			dis=sdistance(Maze, start-17);
	//	printf("dis %d",dis);
			if(dis<temp)
			return start-17;
			}
			
			if(Maze[start+17]!='#'){			
			dis=sdistance(Maze, start+17);
	//	printf("dis %d",dis);
			if(dis<temp)
			return start+17;			
			}
	
			return 0 ;
}	

int posn(char* Maze,char y)
{
	int i,j,x;
	for(i=0;i<17;i++)
	{
		for(j=0;j<17;j++)
		{
		if(*(Maze+i*17+j)==y)
		x=i*17+j;
		}
	}	
	return x;
}

int sdistance(char* Maze, int lrud)
{
	int i;
	int visit[17*17];
	for(i=0;i<17*17;i++)
	{
		visit[i]=0;	
	}

	Queue* p;
	p=queue_new();
	p=queue_push(p,lrud);
	p=queue_push(p,-1);              // '#' to -5 changed		
	
	int dis=shortestDistance(Maze,visit,p,0,17);
	
	return dis;
}
	
char* move(char* Maze,int x)
{
	
	int i,j;
	for(i=0;i<17;i++)
	{
		for(j=0;j<17;j++)
		{
			if(*(Maze+i*17+j)=='U'){
			Maze[x]='U';
			//*(Maze+i*17+j)='.';
			//Maze[i*17+j]='.';
			}
		}
	}	

	return Maze;
} 
