/*
 * Name :- Pramod Munemanik
 * R N  :- CS12B045
 * Date :- 18-10-13
 * MazeSolver
 */
#include<malloc.h>
#include "MazeSolver.h"

// function to find the shortest between U and R or E and R
int shortestDistance( char* maze,int* visit,Queue* X, int dis,int N)
{
	int start;
	start=queue_top(X);			
		
		if(start==-1){
				dis++;
				X=queue_pop(X);
				if(queue_size(X)==0)
				return -1;
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





