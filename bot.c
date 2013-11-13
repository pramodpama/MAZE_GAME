/*
 * Name:- Pramod Munemanik
 *
 */
#include<stdlib.h>
#include<stdio.h>
#include"MazeSolver.h"



int bot2start(char* Maze,int* end )
{
//	mazeprint(Maze);
	int start=posn(Maze,'U');
/*
 * Variables declared and their uses :
 *                  tomove -> the position towards which the move must be intended
 *                  next_posn -> the immediate next position to reach tomove
 *                  direction -> the direction in which next_posn is from start
 */	
	int tomove = best_option(Maze, start);                     
	int next_posn= wheremove(Maze,start,tomove);
	int direction = next_posn - start;
	if(direction == -52) direction = 0;
	else if(direction == 1) direction = 1;
	else if(direction == 52) direction = 2;
	else direction = 3;
	int y=posn(Maze,'R');     // next position
	
	if(next_posn==y)
	*end = 1;
	return direction;
}
int bot3start(char* Maze,int* end )
{
//	mazeprint(Maze);
	int start=posn(Maze,'E');                      //position of E
	
	int next_posn= wheremove(Maze,start,2650);
	int direction = next_posn - start;
	if(direction == -52) direction = 0;
	else if(direction == 1) direction = 1;
	else if(direction == 52) direction = 2;
	else direction = 3;
	int y=posn(Maze,'R');     // next position
	
	if(next_posn==y)
	*end = 1;
	return direction;
}

int best_option(char* Maze, int start)
{
    int* U_$;
    int* Add_$; 
    int U_R = sdistance(Maze, start, 2650), min;   
    U_$ = (int*)malloc(sizeof(int)*100);
    Add_$ = (int*)malloc(sizeof(int)*100);
    int i =0,j=0;
    while(i<2704)
    {
        if(Maze[i] == '$')
        {
            U_$[j] = sdistance(Maze, start, i);
            Add_$[j] = i;
            j++;
        }
        i++;
    }
    U_$[j] = -10;  //termination constant
    j = 0;
    min = U_$[j];
    int minadd = Add_$[j];
    for(j=0; U_$[j] != -10; j++)
    {
        if(min > U_$[j])
            {min = U_$[j]; minadd = Add_$[j];} 
    }
    int E = posn(Maze, 'E');
    int E_R = sdistance(Maze, E, 2650);
    int* E_$;
    E_$ = (int*)malloc(sizeof(int)*100);
    i =0,j=0;
    while(i<2704)
    {
        if(Maze[i] == '$')
        {
            E_$[j] = sdistance(Maze, E, i);
            j++;
        }
        i++;
    }
    E_$[j] = -10;  //termination constant

    
    
/*
 * Now here, starts the bot algorithm The decisive part of the bot which decides
 * which point towards should the move be intended for
 */
 
/*
 * If distance between U and R is less than that between E and R
 * and provided E cant take 5 $ before U reaches R, go straight for R
 */ 
    if(U_R < dist_calc(E_$,5) && U_R < E_R)
        return 2650;

/*
 * If distance between U and R is less than that between E and R
 * and provided E can reach 5 $ before U reaches R.
 */
    else if(U_R < E_R && U_R > dist_calc(E_$,5))
    {
    // If U can reach a $ and still be close to R than E go take that $
        if(min + sdistance(Maze,minadd,2650) < E_R)
            return minadd;
    // Going towards R while collecting random $ near it (radius 4)               
//        else
//            return standard(Maze,start);
    }
    else if(U_R == E_R)
        return standard(Maze, start);
    else if(U_R > E_R)
    {
            return minadd;          
    }    
    return 2650;
}

/*
 * This funtion has been written to easen the distance calculation process for $
 * It basically takes in the array and a Number N. It then sums the N least numbers
 * int the array and gives the sum as output 
 */
int dist_calc(int* Arr, int N)
{
    int i;
    int temp[60];
    for(i=0;Arr[i]!= -10;i++);
        temp[i] = Arr[i];
    
// Using insertionsort as it works best on already sorted arrays    
    insertionsort(i,temp);
    int sum =0;
    for(i=0;i<N;i++)
        sum = sum + temp[i];
    return sum;    
}

int standard(char* Maze, int start)
{

    int i,j,k=0,arr[16],dis[16],p=0;
    for(i=start;i<start+4;i++)
    {
        for(j=0;j<4;j++)
        {   
            if(*(Maze+i*52+j)=='$' && sdistance(Maze,start,i*52+j)!=50*50){       //changed
                arr[k]=i*52+j;
                k++;
                dis[p]=sdistance(Maze,start,arr[k]);
                p++;
            }
        }
    }	
    for(i=0;i<k;i++)
    {
        dis[i]=sdistance(Maze,arr[i],2650) + dis[i];
    }	
    int x=2650;
    int min=dis[0];
    for(i=0;i<k;i++)
    {
        if(dis[i]<min)
        {
            min = dis[i];
            x = arr[i];
        }
    }   
    return x;
}


int wheremove(char* Maze,int start,int end )
{					
			int temp = sdistance(Maze, start, end);
			int dis;
			int flag;
		//printf("temp %d",temp);
		
			if(Maze[start+1]!='#'){
			flag =start + 1;
			dis=sdistance(Maze, start+1,end);
		//printf("dis %d",dis);
			if(dis<temp)
			    return start+1;	
			}

			if(Maze[start-52]!='#'){
			flag = start -52;
			dis=sdistance(Maze, start-52,end);
	//	printf("dis %d",dis);
			if(dis<temp)
			    return start-52;
			}
					
			if(Maze[start-1]!='#'){
			flag = start -1;			
			dis=sdistance(Maze, start-1, end);
	//	printf("dis %d",dis);			
			if(dis<temp)
			    return start-1;
			}
			
			if(Maze[start+52]!='#'){
			flag = start + 52;			
			dis=sdistance(Maze, start+52,end);
	//	printf("dis %d",dis);
			if(dis<temp)
			    return start+52;			
			}
	        return flag;
			
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

int sdistance(char* Maze, int lrud, int dest)
{
    Maze[2650] = '$';
    char store = Maze[dest];
    Maze[dest] = 'R';
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
	Maze[dest] = store;
	Maze[2650] = 'R';
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

void insertionsort( int n, int* arr )
{
    int counter, index,temp;
    for(index=0;index<n;index++)
    {
        counter=index+1;
        while(counter!=0)
        {
            if(arr[counter]<arr[counter-1] && counter<n){
                temp= arr[counter];
                arr[counter] = arr[counter-1];
                arr[counter-1] =temp;
            }
            counter--;
        }
    }
    return;   
}
