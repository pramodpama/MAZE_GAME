/*
 * Name :- Pramod Munemanik
 * R N  :- CS12B045
 * Date :- 1'U''#'0'#'3
 * MazeSolver
 */
#include<malloc.h>
#include "MazeSolver.h"
#include<stdio.h>

// function to find the shortest between U and R or E and R
char* maze_former()
{
        char *Maze;
        Maze = (char *)malloc(sizeof(char)*2704);
        int i,n,j,c=0,k=0,t=0,p=0;
        int x,y;
        int ER,UR;        
       
        
        for(i=0;i<52;i++)
                Maze[i]='#';
        
        for(i=0;i<52;i++)
                Maze[i*52]='#';
        
        for(i=0;i<52;i++)
                Maze[51*52+i]='#';
        
        for(i=0;i<52;i++)
                Maze[i*52+51]='#';
        
        for(i=1;i<51;i++){
                for(j=1;j<51;j++)
                {
                        n = rand()%2704;
                        if(n%4==0)
                        Maze[i*52+j]='#';
                        else
                        Maze[i*52+j]='.';
                }                        
        }
        
        
        for(i=1;i<51;i++){
                for(j=1;j<51;j++)
                {
                        n = rand()%2704;
                        if(n%50==0 && Maze[i*52+j]=='.' && c<50){
                                Maze[i*52+j]= '$';
                                c++;        
                        }
                        if(Maze[i*52+j]=='#' && k==0 && (n+11)%100==0){
                                k = i*52 + j;
                                Maze[k]='E';
                        }
                        if(Maze[i*52+j]=='#' && (n+3)%100==0 && t==0){
                                t = i*52+j;
                                Maze[t]='U';
                        }
                }
        }                        
        

        Maze[2650] = 'R';
        Queue *X;
        X = queue_new();
        X = queue_push(X,k);
        X = queue_push(X,-1);
        int visit[2704];
        int distance = 0;
        for(i=0; i<2704; i++)
            visit[i] = 0;
        Queue *Y;
        Y = queue_new();
        Y = queue_push(Y,t);
        Y = queue_push(Y,-1);
        int visit2[2704];
        int distance2 = 0;
        for(i=0; i<2704; i++)
            visit2[i] = 0;
        if(shortestDistance(Maze,visit,X,distance,52) != 50*50 &&                  
                 shortestDistance(Maze,visit2,Y,distance2,52) != 50*50)         //changed
        {
            return Maze;
        } else{
            return maze_former();
        }         
}

int Maze_alter(char* maze, int direction, int person, int* flag)
{
// converting my direction sense to global sense
    direction++;
    int add = 0;
    int score = 0;
    if(person == 1)
    {
        while(maze[add] != 'U')
        {
            add++;
        }
        if(direction == 1 && maze[add - 52] != '#')
        {
            maze[add] = '.';
            if(maze[add - 52] == '.')
            {
                maze[add - 52] = 'U';
            } else if(maze[add - 52] == '$')
            {
                maze[add - 52] = 'U';
                score = 10;
            } else if(maze[add - 52] == 'E')
            {
                maze[add] == 'U';
            } else if(maze[add - 52] == 'R')
            {
                *flag = 1;
                maze[add - 52] == 'U';
                score = 50;
            }
        }    
        if(direction == 2 && maze[add + 1] != '#')
        {
            maze[add] = '.';
            if(maze[add + 1] == '.')
            {
                maze[add + 1] = 'U';
            } else if(maze[add + 1] == '$')
            {
                maze[add + 1] = 'U';
                score = 10;
            } else if(maze[add + 1] == 'E')
            {
                maze[add] == 'U';
            } else if(maze[add + 1] == 'R')
            {
                *flag = 1;
                maze[add + 1] == 'U';
                score = 50;
            }
        }   
        if(direction == 3 && maze[add + 52] != '#')
        {
            maze[add] = '.';
            if(maze[add + 52] == '.')
            {
                maze[add + 52] = 'U';
            } else if(maze[add + 52] == '$')
            {
                maze[add + 52] = 'U';
                score = 10;
            } else if(maze[add + 52] == 'E')
            {
                maze[add] == 'U';
            } else if(maze[add + 52] == 'R')
            {
                *flag = 1;
                maze[add + 52] == 'U';
                score = 50;
            }
        }
        if(direction == 4 && maze[add - 1] != '#')
        {
            maze[add] = '.';
            if(maze[add - 1] == '.')
            {
                maze[add - 1] = 'U';
            } else if(maze[add - 1] == '$')
            {
                maze[add - 1] = 'U';
                score  = 10;
            } else if(maze[add - 1] == 'E')
            {
                maze[add] == 'U';
            } else if(maze[add - 1] == 'R')
            {    *flag = 1;
                maze[add - 1] == 'U';
                score  = 50;
            }
        }         
    } else {
        while(maze[add] != 'E')
        {
            add++;
        }
        if(direction == 1 && maze[add - 52] != '#')
        {
            maze[add] = '.';
            if(maze[add - 52] == '.')
            {
                maze[add - 52] = 'E';
            } else if(maze[add - 52] == '$')
            {
                maze[add - 52] = 'E';
                score  = 10;
            } else if(maze[add - 52] == 'U')
            {
                maze[add] == 'E';
            } else if(maze[add - 52] == 'R')
            {
                *flag = 1;
                maze[add - 52] == 'E';
                score  = 50;
            }
        }    
        if(direction == 2 && maze[add + 1] != '#')
        {
            maze[add] = '.';
            if(maze[add + 1] == '.')
            {
                maze[add + 1] = 'E';
            } else if(maze[add + 1] == '$')
            {
                maze[add + 1] = 'E';
                score  = 10;
            } else if(maze[add + 1] == 'U')
            {
                maze[add] == 'E';
            } else if(maze[add + 1] == 'R')
            {
                *flag = 1;
                maze[add + 1] == 'E';
                score  = 50;
            }
        }   
        if(direction == 3 && maze[add + 52] != '#')
        {
            maze[add] = '.';
            if(maze[add + 52] == '.')
            {
                maze[add + 52] = 'E';
            } else if(maze[add + 52] == '$')
            {
                maze[add + 52] = 'E';
                score  = 10;
            } else if(maze[add + 52] == 'U')
            {
                maze[add] == 'E';
            } else if(maze[add + 52] == 'R')
            {
                *flag = 1;
                maze[add + 52] == 'E';
                score  = 50;
            }
        }
        if(direction == 4 && maze[add - 1] != '#')
        {
            maze[add] = '.';
            if(maze[add - 1] == '.')
            {
                maze[add - 1] = 'E';
            } else if(maze[add - 1] == '$')
            {
                maze[add - 1] = 'E';
                score  = 10;
            } else if(maze[add - 1] == 'U')
            {
                maze[add] == 'E';
            } else if(maze[add - 1] == 'R')
            {
                *flag = 1;
                maze[add - 1] == 'E';
                score  = 50;
            }
        }
    }
   return score;   
}
int shortestDistance( char* maze,int* visit,Queue* X, int dis,int N)
{
	int start;
	start=queue_top(X);			
		
		if(start==-1){
				dis++;
				X=queue_pop(X);
				if(queue_size(X)==0)
				return 50*50;
				X=queue_push(X,-1);
					
		} else {
			
			X=queue_pop(X);
			visit[start]=1;
		
			if((maze[start+1]!='#')&&(visit[start+1]==0)){
			X=queue_push(X,start+1);
			visit[start+1]=1;
			}
					
			if((maze[start-1]!='#')&&(visit[start-1]==0)){			
			X=queue_push(X,start-1);
			visit[start-1]=1;
			}
										
			if((maze[start-N]!='#')&&(visit[start-N]==0)){
			X=queue_push(X,start-N);
			visit[start-N]=1;
			}
			
			if((maze[start+N]!='#')&&(visit[start+N]==0)){			
			X=queue_push(X,start+N);
			visit[start+N]=1;
			}

			if(visit[start]==1 && maze[start]=='R')
			return dis;

		 }
	
		shortestDistance( maze,visit,X,dis,N);
}

// Create a new empty queue
Queue* queue_new()
{
	Queue* empt;
	empt=NULL;
	return empt;
}

// Inserts @val to the back of the queue
Queue* queue_push( Queue* st, int val )
{
	Queue* temp;
	Queue* ts;
	ts=st;
	if(st==NULL){
	             st = (Queue*)malloc(sizeof(struct Queue_));
		     st->data=val;
		     st->next=NULL;
	}
	else{
	while(ts!=NULL) 
	{
	temp=ts;
        ts = ts->next ;
        }
	ts = (Queue*)malloc(sizeof(struct Queue_));
	
	ts->data=val;
	ts->next=NULL;
	temp->next=ts;
	}
	
	return st;
}

// Remove the element at the front of the queue - also frees memory
Queue* queue_pop( Queue* st )
{
	if(st==NULL){
	            return st;
	} else {
		
		Queue* ts;
		ts=st->next;
		free(st);
		
		return ts;
	 }
}

// Returns the element currently at the top of the queue.
int queue_top( Queue* st)
{
	if(st==NULL){
		
		    return ;
	}
	else {
	     
	     int ele = st->data;
	
	return ele;
	}
}

// Returns the number of elements in the queue
int queue_size( Queue* st )
{
	int count=0;
	
	while(st!=NULL){
			st=st->next;
			count++;
	}

	return count;
}	

void mazeprint(char* Maze)
{                                                                                                                                                           
                                                                                      
                                                                                                              
	int i,j;
	for(i=0;i<52;i++)
	{
		for(j=0;j<52;j++)
		{	
		printf("%c ",Maze[i*52+j]);
		//printf("%c ",(Maze[i*52+j]=='.')?' ':Maze[i*52+j]);
		}
	printf("\n");
	}
	
	return ;
}




