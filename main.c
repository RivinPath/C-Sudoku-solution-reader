#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "headers.h"

#include "shared.h"
#include "validation.h"

/*
 * AUTHOR: Rivin Pathirage
 * UNIT: Opareting System
 * PURPOSE: Main class for utilizing other classes and structuring the program
 * REFERENCES: 
 */



int sol[GRID_SIZE][GRID_SIZE];
int row[GRID_SIZE] = {0};
int col[GRID_SIZE] = {0};
int sub[GRID_SIZE] = {0};
int counter = 0;
int delay;
pthread_mutex_t mutex;
pthread_cond_t cond_var;

//PURPOSE: Reading the solution file
void read_solution(char *filename) 
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) 
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < GRID_SIZE; i++) 
    {
        for (int j = 0; j < GRID_SIZE; j++) 
        {
            fscanf(fp, "%d", &sol[i][j]);
            
        }

        
    }

    //print
    for (int i = 0; i < GRID_SIZE; i++) 
    {
        for (int j = 0; j < GRID_SIZE; j++) 
        {
            
            printf("%d ", sol[i][j]);
            
        }

        printf("\n");
        
    }

    

    fclose(fp);
}

int main(int argc, char *argv[]) 
{
    if (argc != 3) 
    {
        printf("Usage: %s <solution_file> <delay>\n", argv[0]);
        return 1;
    }

    read_solution(argv[1]);


    

    delay = atoi(argv[2]);
    printf("\nDelay - %d \n", delay);

    

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond_var, NULL);

    pthread_t threads[4];
    pthread_create(&threads[0], NULL, thread_func_1, NULL);
    pthread_create(&threads[1], NULL, thread_func_2, NULL);
    pthread_create(&threads[2], NULL, thread_func_3, NULL);
    pthread_create(&threads[3], NULL, thread_func_4, NULL);

    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&cond_var, &mutex);
    pthread_mutex_unlock(&mutex);

    print_validation_results(row, col, sub, counter);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_var);

    return 0;
}






