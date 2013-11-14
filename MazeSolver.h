/*
 * Name :- Pramod Munemanik
 * R N  :- CS12B045
 * MazeSolver
 */

#ifndef MAZESOLVER_H
#define MAZESOLVER_H

typedef struct Queue_ Queue;
struct Queue_ {
    int data;
    Queue* next;
};

// Create a new empty queue
Queue* queue_new();

// Inserts @val to the back of the queue
Queue* queue_push( Queue* st, int val );

// Remove the element at the front of the queue - also frees memory
Queue* queue_pop( Queue* st );

// Returns the element currently at the top of the queue. If the queue is empty,
// @error should be set to 1, else 0.
int queue_top( Queue* st);

// Returns the number of elements in the queue
int queue_size( Queue* st );

// Finds shortest distance to the 
// search symbol in the maze of size NxN
// from start position (x,y) and return
// a direction.
char* maze_former();

int shortestDistance( char* maze,int* visit,Queue* X, int dis,int N);

int standard(char* Maze, int start);

int Maze_alter(char* maze, int direction, int person, int* flag);

int bot2start(char* Maze,int* end );

int bot3start(char* Maze,int* end );

int wheremove(char* Maze,int start , int end );

int posn(char* Maze,char y);

void insertionsort( int n, int* arr );

int dist_calc(int* Arr, int N);

int sdistance(char* Maze, int lrud ,int end);

char* move(char* Maze,int x);

void mazeprint(char* Maze);

#endif // TOKENISER_H

