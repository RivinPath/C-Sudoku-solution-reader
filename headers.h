#ifndef HEADERS_H
#define HEADERS_H

#define GRID_SIZE 9

extern int sol[GRID_SIZE][GRID_SIZE];
extern int row[GRID_SIZE];
extern int col[GRID_SIZE];
extern int sub[GRID_SIZE];
extern int counter;
extern int delay;
extern pthread_mutex_t mutex;
extern pthread_cond_t cond_var;

void read_solution(char *filename);

int validate_row(int row_num, int (*sol)[GRID_SIZE]);
int validate_col(int col_num, int (*sol)[GRID_SIZE]);
int validate_subgrid(int subgrid_num, int (*sol)[GRID_SIZE]);
void print_validation_results(int *row, int *col, int *sub, int counter);

void *thread_func_1(void *arg);
void *thread_func_2(void *arg);
void *thread_func_3(void *arg);
void *thread_func_4(void *arg);



#endif // HEADERS_H