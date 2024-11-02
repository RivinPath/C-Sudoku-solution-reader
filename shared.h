#ifndef SHARED_H
#define SHARED_H

#define GRID_SIZE 9

extern int sol[GRID_SIZE][GRID_SIZE];
extern int row[GRID_SIZE];
extern int col[GRID_SIZE];
extern int sub[GRID_SIZE];
extern int counter;
extern int delay;
extern pthread_mutex_t mutex;
extern pthread_cond_t cond_var;

#endif