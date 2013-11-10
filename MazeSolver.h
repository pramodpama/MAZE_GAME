/*
 * Name :- Pramod Munemanik
 * R N  :- CS12B045
 * Date :- 18-10-13
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
int shortestDistance( char* maze,int* visit,Queue* X, int dis,int N);

int botstart(char* Maze );

int wheremove(char* Maze,int start );

int posn(char* Maze,char y);

int sdistance(char* Maze, int lrud);

char* move(char* Maze,int x);

void mazeprint(char* Maze);

#endif // TOKENISER_H
